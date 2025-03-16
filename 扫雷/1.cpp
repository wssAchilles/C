#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR() system("cls")
#else
#include <unistd.h>
#define CLEAR() system("clear")
#endif

#define DEFAULT_SIZE 8     // 默认游戏大小：8x8
#define DEFAULT_MINES 10   // 默认地雷数量：10

int SIZE = DEFAULT_SIZE;  // 当前游戏的大小
int MINES = DEFAULT_MINES;  // 当前游戏的地雷数量

// 使用动态分配内存存储雷区和揭开的状态
int **board;    // 存储雷区数据 (-1为地雷，其他为数字)
int **revealed; // 存储格子是否被揭开的状态（0为未揭开，1为已揭开）
int **flagged;  // 存储格子是否被标记（0为未标记，1为已标记）

// 初始化雷区
void init_board() {
    int i, j;

    // 动态分配内存
    board = (int **)malloc(SIZE * sizeof(int *));
    revealed = (int **)malloc(SIZE * sizeof(int *));
    flagged = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        board[i] = (int *)malloc(SIZE * sizeof(int));
        revealed[i] = (int *)malloc(SIZE * sizeof(int));
        flagged[i] = (int *)malloc(SIZE * sizeof(int));
    }

    // 初始化雷区和揭开的状态
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;  // 0表示未揭开
            flagged[i][j] = 0;   // 0表示未标记
        }
    }

    // 随机放置地雷
    srand((unsigned int)time(NULL));
    int placed_mines = 0;
    while (placed_mines < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != -1) {
            board[x][y] = -1;
            placed_mines++;
        }
    }

    // 计算每个格子周围的地雷数
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                continue;
            }
            int mine_count = 0;
            int dx, dy;
            // 检查周围八个格子
            for (dx = -1; dx <= 1; dx++) {
                for (dy = -1; dy <= 1; dy++) {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == -1) {
                        mine_count++;
                    }
                }
            }
            board[i][j] = mine_count;
        }
    }
}

// 判断是否超出边界
int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// 显示雷区
void display_board() {
    int i, j;
    CLEAR();

    // 计算居中位置
    int padding = (80 - 2 * SIZE) / 2; // 假设控制台宽度为80字符
    if (padding < 0) padding = 0;

    for (int p = 0; p < padding; p++) {
        printf(" ");
    }
    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);  // 显示列号
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        for (int p = 0; p < padding; p++) {
            printf(" ");
        }
        printf("%2d ", i);  // 显示行号
        for (j = 0; j < SIZE; j++) {
            if (flagged[i][j] == 1) {
                printf(" F");  // 标记格子
            } else if (revealed[i][j] == 1) {
                if (board[i][j] == -1) {
                    printf(" *");  // 显示地雷
                } else {
                    printf(" %d", board[i][j]);  // 显示数字
                }
            } else {
                printf(" .");  // 未揭开的格子
            }
        }
        printf("\n");
    }
}

// 标记或取消标记格子
void toggle_flag(int x, int y) {
    if (revealed[x][y] == 1) {
        printf("无法标记，格子已经揭开\n");
        return;
    }
    flagged[x][y] = !flagged[x][y];
}

// 保存当前游戏状态
void save_game(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("无法保存游戏！\n");
        return;
    }

    fprintf(file, "%d %d\n", SIZE, MINES);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fprintf(file, "%d %d %d\n", board[i][j], revealed[i][j], flagged[i][j]);
        }
    }

    fclose(file);
    printf("游戏已保存到%s\n", filename);
}

// 加载游戏状态
void load_game(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法加载游戏！\n");
        return;
    }

    fscanf(file, "%d %d", &SIZE, &MINES);

    // 释放旧内存并重新分配
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
        free(revealed[i]);
        free(flagged[i]);
    }
    free(board);
    free(revealed);
    free(flagged);

    init_board();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, "%d %d %d", &board[i][j], &revealed[i][j], &flagged[i][j]);
        }
    }

    fclose(file);
    printf("游戏已从%s加载\n", filename);
}

// 自动揭开周围安全格子
void auto_reveal(int x, int y) {
    if (!is_valid(x, y) || revealed[x][y] || flagged[x][y]) {
        return;
    }

    revealed[x][y] = 1;

    if (board[x][y] == 0) { // 如果是空格，递归揭开周围格子
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0) {
                    auto_reveal(x + dx, y + dy);
                }
            }
        }
    }
}

// 判断是否获胜
int check_win() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != -1 && revealed[i][j] == 0) {
                return 0; // 还有未揭开的非雷格子
            }
        }
    }
    return 1; // 赢了
}

// 游戏主循环
void play_game() {
    int x, y;
    char command;

    while (1) {
        display_board();
        printf("输入指令 (r x y: 揭开, f x y: 标记, s: 保存, q: 退出): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("退出游戏\n");
            break;
        } else if (command == 's') {
            save_game("minesweeper_save.txt");
        } else if (command == 'r') {
            scanf("%d %d", &x, &y);
            if (!is_valid(x, y)) {
                printf("无效位置！\n");
                continue;
            }
            if (flagged[x][y]) {
                printf("此格已标记，无法揭开！\n");
                continue;
            }
            if (board[x][y] == -1) {
                printf("你踩到地雷了！游戏结束！\n");
                revealed[x][y] = 1; // 显示地雷
                display_board();
                break;
            } else {
                auto_reveal(x, y);
                if (check_win()) {
                    printf("恭喜你，赢了！\n");
                    display_board();
                    break;
                }
            }
        } else if (command == 'f') {
            scanf("%d %d", &x, &y);
            if (!is_valid(x, y)) {
                printf("无效位置！\n");
                continue;
            }
            toggle_flag(x, y);
        } else {
            printf("无效指令！\n");
        }
    }
}

// 清理内存
void cleanup() {
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
        free(revealed[i]);
        free(flagged[i]);
    }
    free(board);
    free(revealed);
    free(flagged);
}

int main() {
    printf("欢迎来到扫雷游戏！\n");
    printf("请选择难度 (1: 简单, 2: 中等, 3: 困难): ");
    int difficulty;
    scanf("%d", &difficulty);

    if (difficulty == 1) {
        SIZE = 8;
        MINES = 10;
    } else if (difficulty == 2) {
        SIZE = 16;
        MINES = 40;
    } else if (difficulty == 3) {
        SIZE = 24;
        MINES = 99;
    } else {
        printf("无效选择，使用默认难度\n");
    }

    init_board();
    play_game();
    cleanup();

    return 0;
}
