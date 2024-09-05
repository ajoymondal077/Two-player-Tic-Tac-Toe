#include <stdio.h>

char board[3][3]; // The tic-tac-toe board

// Function to initialize the board
void initializeBoard()
{
	int i,j;
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won
char checkWin() {
	int i;
    // Check rows, columns, and diagonals
    for(i = 0; i < 3; i++){
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return ' '; // No winner yet
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");
	printf("to enter")
    while (1) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        char winner = checkWin();
        if (winner != ' ' || moves == 9) {
            printBoard();
            if (winner != ' ') {
                printf("Player %c wins!\n", winner);
            } else {
                printf("It's a draw!\n");
            }
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

