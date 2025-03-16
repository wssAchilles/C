#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 8     // Ĭ����Ϸ��С��8x8
#define DEFAULT_MINES 10   // Ĭ�ϵ���������10

int SIZE = DEFAULT_SIZE;  // ��ǰ��Ϸ�Ĵ�С
int MINES = DEFAULT_MINES;  // ��ǰ��Ϸ�ĵ�������

// ʹ�ö�̬�����ڴ�洢�����ͽҿ���״̬
int **board;    // �洢�������� (-1Ϊ���ף�����Ϊ����)
int **revealed; // �洢�����Ƿ񱻽ҿ���״̬��0Ϊδ�ҿ���1Ϊ�ѽҿ���

// ��ʼ������
void init_board() {
    int i, j;

    // ��̬�����ڴ�
    board = (int **)malloc(SIZE * sizeof(int *));
    revealed = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        board[i] = (int *)malloc(SIZE * sizeof(int));
        revealed[i] = (int *)malloc(SIZE * sizeof(int));
    }

    // ��ʼ�������ͽҿ���״̬
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;  // 0��ʾδ�ҿ�
        }
    }

    // ������õ���
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

    // ����ÿ��������Χ�ĵ�����
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                continue;
            }
            int mine_count = 0;
            int dx, dy;
            // �����Χ�˸�����
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

// �ж��Ƿ�Խ��
int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// ��ʾ����
void display_board() {
    int i, j;
    printf("  ");
    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);  // ��ʾ�к�
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);  // ��ʾ�к�
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 1) {
                if (board[i][j] == -1) {
                    printf(" *");  // ��ʾ����
                } else {
                    printf(" %d", board[i][j]);  // ��ʾ����
                }
            } else {
                printf(" .");  // δ�ҿ��ĸ���
            }
        }
        printf("\n");
    }
}

// ��ʾʣ�������
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
    printf("ʣ�������: %d\n", remaining_mines);
}

// ��ʾʤ����Ϣ
void display_win_message() {
    printf("��ϲ����Ӯ�ˣ�\n");
}

// �ݹ�չ���հ�����
void reveal_empty(int x, int y) {
    if (!is_valid(x, y) || revealed[x][y] || board[x][y] == -1) {
        return;  // Խ�硢�ѽҿ����߲ȵ�����
    }

    revealed[x][y] = 1;  // �ҿ���ǰ����

    // ����ǿհ׸��ӣ���ݹ�չ����Χ�Ŀհ׸���
    if (board[x][y] == 0) {
        int dx, dy;
        for (dx = -1; dx <= 1; dx++) {
            for (dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;  // ������ǰ����
                reveal_empty(x + dx, y + dy);
            }
        }
    }
}

// ��ҵ������
int click_cell(int x, int y) {
    if (board[x][y] == -1) {
        return 0;  // ��������ף���Ϸ����
    }
    reveal_empty(x, y);
    return 1;  // ������Ϸ
}

// �ж��Ƿ�ʤ��
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
        return 1;  // ʤ��
    }
    return 0;  // ������Ϸ
}

int game_over = 0;  // ��Ϸ������־
int game_started = 0;  // ��ʱ���Ƿ�ʼ
time_t start_time;  // ��Ϸ��ʼʱ��

// ������ʱ��
void start_timer() {
    start_time = time(NULL);
    game_started = 1;
}

// ���¼�ʱ������ʾ
void display_timer() {
    if (game_started) {
        time_t current_time = time(NULL);
        printf("��Ϸʱ��: %ld ��\n", current_time - start_time);
    }
}

// ������Ϸ
void restart_game() {
    game_over = 0;
    game_started = 0;
    init_board();
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            revealed[i][j] = 0;  // ���ýҿ���״̬
        }
    }
    printf("��Ϸ��������\n");
}

// ѡ���Ѷ�
void choose_difficulty() {
    char choice;
    printf("��ѡ���Ѷ�\n1. ���� (8x8, 10����)\n2. �м� (12x12, 20����)\n3. �߼� (16x16, 40����)\n��ѡ��:  ");
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
        printf("��Ч��ѡ��Ĭ��Ϊ���Ѷ�\n");
        SIZE = 8;
        MINES = 10;
    }
}

int main() {
    int x, y;
    char choice;

    // ѡ���Ѷ�
    choose_difficulty();

    // ��ʼ����Ϸ
    init_board();

    // ������ʱ��
    start_timer();

    // ��Ϸ��ѭ��
    while (!game_over) {
        display_board();  // ��ʾ����
        display_remaining_mines(); // ��ʾʣ�������
        display_timer();  // ��ʾ��Ϸʱ��

        printf("���������� (�� ��): ");
        scanf("%d %d", &x, &y);

        if (is_valid(x, y)) {
            if (click_cell(x, y)) {
                if (check_win()) {
                    display_board();
                    display_win_message();  // ��ʾʤ����Ϣ
                    game_over = 1;
                }
            } else {
                display_board();
                printf("��ȵ������ˣ���Ϸ������\n");
                game_over = 1;
            }
        } else {
            printf("��Ч�����꣬���������롣\n");
        }

        if (game_over) {
            printf("�Ƿ�������Ϸ? (y/n): ");
            getchar();  // ���ĵ��������еĻ��з�
            choice = getchar();
            if (choice == 'y' || choice == 'Y') {
                restart_game();
            } else if (choice == 'n' || choice == 'N') {
                printf("лл���棡�ټ���\n");
                break;
            }
        }
    }

    return 0;
}

