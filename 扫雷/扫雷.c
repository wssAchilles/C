#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 8     // 默认游戏大小：8x8
#define DEFAULT_MINES 10   // 默认地雷数量：10

int SIZE = DEFAULT_SIZE;  // 当前游戏的大小
int MINES = DEFAULT_MINES;  // 当前游戏的地雷数量

// 使用动态分配内存存储雷区和揭开的状态
int **board;    // 存储雷区数据 (-1为地雷，其他为数字)
int **revealed; // 存储格子是否被揭开的状态（0为未揭开，1为已揭开）

// 初始化雷区
void init_board() {
    int i, j;

    // 动态分配内存
    board = (int **)malloc(SIZE * sizeof(int *));
    revealed = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        board[i] = (int *)malloc(SIZE * sizeof(int));
        revealed[i] = (int *)malloc(SIZE * sizeof(int));
    }

    // 初始化雷区和揭开的状态
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;  // 0表示未揭开
        }
    }

    // 随机放置地雷
    srand(time(NULL));
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

// 判断是否越界
int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// 显示雷区
void display_board() {
    int i, j;
    printf("  ");
    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);  // 显示列号
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);  // 显示行号
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 1) {
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

// 显示剩余地雷数
void display_remaining_mines() {
    int remaining_mines = MINES;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 1 && board[i][j] == -1) {
                remaining_mines--;
            }
        }
    }
    printf("剩余地雷数: %d\n", remaining_mines);
}

// 显示胜利信息
void display_win_message() {
    printf("恭喜！你赢了！\n");
}

// 递归展开空白区域
void reveal_empty(int x, int y) {
    if (!is_valid(x, y) || revealed[x][y] || board[x][y] == -1) {
        return;  // 越界、已揭开或者踩到地雷
    }

    revealed[x][y] = 1;  // 揭开当前格子

    // 如果是空白格子，则递归展开周围的空白格子
    if (board[x][y] == 0) {
        int dx, dy;
        for (dx = -1; dx <= 1; dx++) {
            for (dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;  // 跳过当前格子
                reveal_empty(x + dx, y + dy);
            }
        }
    }
}

// 玩家点击处理
int click_cell(int x, int y) {
    if (board[x][y] == -1) {
        return 0;  // 点击到地雷，游戏结束
    }
    reveal_empty(x, y);
    return 1;  // 继续游戏
}

// 判断是否胜利
int check_win() {
    int revealed_count = 0;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                revealed_count++;
            }
        }
    }

    if (revealed_count == SIZE * SIZE - MINES) {
        return 1;  // 胜利
    }
    return 0;  // 继续游戏
}

int game_over = 0;  // 游戏结束标志
int game_started = 0;  // 计时器是否开始
time_t start_time;  // 游戏开始时间

// 启动计时器
void start_timer() {
    start_time = time(NULL);
    game_started = 1;
}

// 更新计时器并显示
void display_timer() {
    if (game_started) {
        time_t current_time = time(NULL);
        printf("游戏时间: %ld 秒\n", current_time - start_time);
    }
}

// 重启游戏
void restart_game() {
    game_over = 0;
    game_started = 0;
    init_board();
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            revealed[i][j] = 0;  // 重置揭开的状态
        }
    }
    printf("游戏已重启！\n");
}

// 选择难度
void choose_difficulty() {
    char choice;
    printf("请选择难度\n1. 初级 (8x8, 10地雷)\n2. 中级 (12x12, 20地雷)\n3. 高级 (16x16, 40地雷)\n请选择:  ");
    scanf(" %c", &choice);

    if (choice == '1') {
        SIZE = 8;
        MINES = 10;
    } else if (choice == '2') {
        SIZE = 12;
        MINES = 20;
    } else if (choice == '3') {
        SIZE = 16;
        MINES = 40;
    } else {
        printf("无效的选择，默认为简单难度\n");
        SIZE = 8;
        MINES = 10;
    }
}

int main() {
    int x, y;
    char choice;

    // 选择难度
    choose_difficulty();

    // 初始化游戏
    init_board();

    // 启动计时器
    start_timer();

    // 游戏主循环
    while (!game_over) {
        display_board();  // 显示雷区
        display_remaining_mines(); // 显示剩余地雷数
        display_timer();  // 显示游戏时间

        printf("请输入坐标 (行 列): ");
        scanf("%d %d", &x, &y);

        if (is_valid(x, y)) {
            if (click_cell(x, y)) {
                if (check_win()) {
                    display_board();
                    display_win_message();  // 显示胜利信息
                    game_over = 1;
                }
            } else {
                display_board();
                printf("你踩到地雷了，游戏结束！\n");
                game_over = 1;
            }
        } else {
            printf("无效的坐标，请重新输入。\n");
        }

        if (game_over) {
            printf("是否重启游戏? (y/n): ");
            getchar();  // 消耗掉缓冲区中的换行符
            choice = getchar();
            if (choice == 'y' || choice == 'Y') {
                restart_game();
            } else if (choice == 'n' || choice == 'N') {
                printf("谢谢游玩！再见！\n");
                break;
            }
        }
    }

    return 0;
}

