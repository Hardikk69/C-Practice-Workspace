#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];

void initialize_board() {
    char num = '1';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
}

void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_win(char symbol) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    return 0;
}

void main() {
    int num, row, col, player = 1, total_moves = 0;
    char symbol;

    initialize_board();

    do {
        display_board();

        symbol = (player % 2) ? 'X' : 'O';

        printf("PLayer %d, enter the number (1-9) to place %c: ", player, symbol);
        scanf("%d", &num);

        if (num < 1 || num > 9) {
            printf("Invalid number. Please choose between 1 and 9.\n");
            continue;
        }

        row = (num - 1) / SIZE;
        col = (num - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken. Try again.\n");
            continue;
        }

        board[row][col] = symbol;

        if (check_win(symbol)) {
            display_board();
            printf("Player %d wins!\n", player);
            break;
        }

        total_moves++;
        if (total_moves == SIZE * SIZE) {
            display_board();
            printf("It's a draw!\n");
            break;
        }

        player = (player % 2) + 1;
    } while (1);
}
