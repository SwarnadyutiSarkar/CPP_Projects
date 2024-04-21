#include <iostream>
#include <deque>
#include <conio.h>
#include <cstdlib>
#include <ctime>

const int width = 20;
const int height = 20;
bool gameOver;
int score;
int snakeX, snakeY, fruitX, fruitY;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
std::deque<std::pair<int, int>> snake;

void Setup() {
    gameOver = false;
    dir = STOP;
    snakeX = width / 2;
    snakeY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0) {
                std::cout << "#";
            }
            if (i == snakeY && j == snakeX) {
                std::cout << "O";
            } else if (i == fruitY && j == fruitX) {
                std::cout << "F";
            } else {
                bool print = false;
                for (auto& segment : snake) {
                    if (segment.first == j && segment.second == i) {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print) {
                    std::cout << " ";
                }
            }
            if (j == width - 1) {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    std::pair<int, int> tail = snake.back();
    snake.pop_back();
    int prevX = tail.first;
    int prevY = tail.second;
    int prev2X, prev2Y;
    for (auto& segment : snake) {
        prev2X = segment.first;
        prev2Y = segment.second;
        segment.first = prevX;
        segment.second = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
        default:
            break;
    }

    if (snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height) {
        gameOver = true;
    }

    for (const auto& segment : snake) {
        if (segment.first == snakeX && segment.second == snakeY) {
            gameOver = true;
        }
    }

    if (snakeX == fruitX && snakeY == fruitY) {
        score += 10;
        std::pair<int, int> newTail(snakeX, snakeY);
        snake.push_front(newTail);
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

    std::pair<int, int> newHead(snakeX, snakeY);
    snake.push_front(newHead);
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // Sleep(10); // Windows-specific sleep function
    }
    return 0;
}
