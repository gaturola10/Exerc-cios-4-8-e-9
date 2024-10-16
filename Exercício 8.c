#include <stdio.h>

char board[3][3];
char current_player = 'X';


void initBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count + '0';
            count++;
        }
    }
}


void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}


int checkWinner() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}


int isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;
}


int makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_player;
        return 1;
    } else {
        printf("Posição já ocupada! Tente novamente.\n");
        return 0;
    }
}


void switchPlayer() {
    current_player = (current_player == 'X') ? 'O' : 'X';
}


int main() {
    int position;
    initBoard();
    while (1) {
        printBoard();
        printf("Jogador %c, escolha uma posição (1-9): ", current_player);
        scanf("%d", &position);

        if (position < 1 || position > 9) {
            printf("Posição inválida! Escolha entre 1 e 9.\n");
            continue;
        }


        if (makeMove(position)) {
            if (checkWinner()) {
                printBoard();
                printf("Jogador %c venceu!\n", current_player);
                break;
            }
            if (isDraw()) {
                printBoard();
                printf("Empate!\n");
                break;
            }
            switchPlayer();
        }
    }

    return 0;
}

