#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int rows = 10;
const int cols = 10;
const int mines = 10;

std::vector<std::vector<char>> board(rows, std::vector<char>(cols, ' '));
std::vector<std::vector<bool>> revealed(rows, std::vector<bool>(cols, false));
std::vector<std::vector<bool>> isMine(rows, std::vector<bool>(cols, false));
bool gameOver = false;

void placeMines() {
    int count = 0;
    while (count < mines) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (!isMine[x][y]) {
            isMine[x][y] = true;
            ++count;
        }
    }
}

void drawBoard() {
    std::cout << "  ";
    for (int i = 0; i < cols; ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < cols; ++j) {
            if (revealed[i][j]) {
                if (isMine[i][j]) {
                    std::cout << "* ";
                } else {
                    int count = 0;
                    if (i > 0 && j > 0 && isMine[i - 1][j - 1]) count++;
                    if (i > 0 && isMine[i - 1][j]) count++;
                    if (i > 0 && j < cols - 1 && isMine[i - 1][j + 1]) count++;
                    if (j > 0 && isMine[i][j - 1]) count++;
                    if (j < cols - 1 && isMine[i][j + 1]) count++;
                    if (i < rows - 1 && j > 0 && isMine[i + 1][j - 1]) count++;
                    if (i < rows - 1 && isMine[i + 1][j]) count++;
                    if (i < rows - 1 && j < cols - 1 && isMine[i + 1][j + 1]) count++;
                    std::cout << count << " ";
                }
            } else {
                std::cout << "# ";
            }
        }
        std::cout << std::endl;
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (revealed[x][y]) return;

    revealed[x][y] = true;
    if (isMine[x][y]) {
        gameOver = true;
        return;
    }

    if (x > 0 && y > 0 && !isMine[x - 1][y - 1]) reveal(x - 1, y - 1);
    if (x > 0 && !isMine[x - 1][y]) reveal(x - 1, y);
    if (x > 0 && y < cols - 1 && !isMine[x - 1][y + 1]) reveal(x - 1, y + 1);
    if (y > 0 && !isMine[x][y - 1]) reveal(x, y - 1);
    if (y < cols - 1 && !isMine[x][y + 1]) reveal(x, y + 1);
    if (x < rows - 1 && y > 0 && !isMine[x + 1][y - 1]) reveal(x + 1, y - 1);
    if (x < rows - 1 && !isMine[x + 1][y]) reveal(x + 1, y);
    if (x < rows - 1 && y < cols - 1 && !isMine[x + 1][y + 1]) reveal(x + 1, y + 1);
}

int main() {
    srand(time(0));
    placeMines();
    while (!gameOver) {
        drawBoard();
        int x, y;
        std::cout << "Enter row and column to reveal: ";
        std::cin >> x >> y;
        x--; y--;
        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
        reveal(x, y);
    }
    std::cout << "Game over!" << std::endl;
    drawBoard();
    return 0;
}
