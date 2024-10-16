#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initBoard(int board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}


void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int countAliveNeighbors(int board[ROWS][COLS], int x, int y) {
    int alive = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newX = x + i;
            int newY = y + j;


            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
                alive += board[newX][newY];
            }
        }
    }
    return alive;
}


void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = countAliveNeighbors(board, i, j);

            if (board[i][j] == 1) {

                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newBoard[i][j] = 0;
                } else {

                    newBoard[i][j] = 1;
                }
            } else {

                if (aliveNeighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];


    initBoard(board);

    printf("Estado inicial do tabuleiro:\n");
    printBoard(board);


    for (int i = 0; i < 10; i++) {
        printf("Geração %d:\n", i + 1);
        updateBoard(board);
        printBoard(board);
    }

    return 0;
}
