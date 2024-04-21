#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
char currentPlayer = 'X';

void drawBoard() {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << (j == 2 ? "" : "|");
        }
        std::cout << std::endl;
        if (i != 2) {
            std::cout << "  -----" << std::endl;
        }
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool placeMarker(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

int main() {
    int row, col;
    while (true) {
        drawBoard();
        std::cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        std::cin >> row >> col;
        if (placeMarker(row - 1, col - 1)) {
            if (checkWin()) {
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            } else if (isBoardFull()) {
                std::cout << "It's a tie!" << std::endl;
                break;
            }
            switchPlayer();
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
    return 0;
}
