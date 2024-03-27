#include <stdio.h>
#include <stdbool.h>

void move(char mat[][3], int x, int y, int a) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || mat[x][y] != ' ') {
        printf("Invalid move. Please try again.\n");
        return;
    }
    mat[x][y] = (a == 0) ? 'X' : 'O';
}

int main() {
    char mat[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat[i][j] = ' ';
        }
    }

    int currentPlayer = 0; // 0 for Player One (X), 1 for Player Two (O)
    bool gameWon = false;

    while (!gameWon) {
        for (int i = 0; i < 3; ++i) {
                printf("| ");
            for (int j = 0; j < 3; ++j) {
                printf("%c | ", mat[i][j]);
            }
            printf("\n");
        }

        printf("Player %d, enter the coordinates of %c (row, column):\n",
               currentPlayer + 1, (currentPlayer == 0) ? 'X' : 'O');
        int x, y;
        scanf("%d %d", &x, &y);

        move(mat, x, y, currentPlayer);

        // Check for winning conditions
        if ((mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != ' ') ||
            (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != ' ') ||
            (mat[0][0] == mat[0][1] && mat[0][1] == mat[0][2] && mat[0][0] != ' ') ||
            (mat[1][0] == mat[1][1] && mat[1][1] == mat[1][2] && mat[1][0] != ' ') ||
            (mat[2][0] == mat[2][1] && mat[2][1] == mat[2][2] && mat[2][0] != ' ') ||
            (mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0] && mat[0][0] != ' ') ||
            (mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1] && mat[0][1] != ' ') ||
            (mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2] && mat[0][2] != ' ')) {
            gameWon = true;
            printf("Player %d wins!\n", currentPlayer + 1);
        } else {
            // Check for a draw
            bool isDraw = true;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (mat[i][j] == ' ') {
                        isDraw = false;
                        break;
                    }
                }
            }
            if (isDraw) {
            for (int i = 0; i < 3; ++i) {
                printf("| ");
                for (int j = 0; j < 3; ++j) {
                    printf("%c | ", mat[i][j]);
                }
                printf("\n");
            }
                printf("It's a draw!\n");
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
        }
    }

    return 0;
}