#include <stdio.h>
#include <stdbool.h>

// Function to print the current state of the game board
void printBoard(char board[3][3]) {
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

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

// Function to check if the game is a draw (no moves left)
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(char board[3][3], int move, char player) {
    int row = (move - 1) / 3;  // Calculate row
    int col = (move - 1) % 3;  // Calculate column

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    } else {
        printf("Invalid move! Try again.\n");
        return false;
    }
}

// Main game function
int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char currentPlayer = 'X';  // Player X always starts
    bool gameWon = false;
    bool gameDraw = false;
    int move;

    printf("Welcome to Tic Tac Toe!\n");

    // Main game loop
    while (!gameWon && !gameDraw) {
        printBoard(board);  // Print the game board

        // Ask the current player to make a move
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);

        // Check if the move is valid
        if (move < 1 || move > 9) {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            continue;
        }

        // Make the move if it's valid
        if (makeMove(board, move, currentPlayer)) {
            // Check if the current player has won
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the game is a draw
            gameDraw = checkDraw(board);
            if (gameDraw) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch player (X -> O, O -> X)
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}