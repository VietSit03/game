#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 25;
const int height = 20;
bool gameOver;
int x, y, f_x, f_y;
int score = 0;
enum eDirection {STOP, UP, DOWN, LEFT, RIGHT};
eDirection dir = STOP;

void setFruit() {
    f_x = 1 + rand() % (width-2);
    f_y = 1 + rand() % (height-2);
    while (f_x == x && f_y == y) {
        f_x = 1 + rand() % (width-2);
        f_y = 1 + rand() % (height-2);
    }
}
void setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    setFruit();
}

void draw() {
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) {
            for (int j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
        else {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j == width -1) {
                    cout << "*";
                }
                else if (j == x && i == y) {
                    cout << "O";
                }
                else if (j == f_x && i == f_y) {
                    cout << "x";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    cout << "Your score: " << score << endl;
}

void logic() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':   x--;    dir = LEFT;     break;
            case 'd':   x++;    dir = RIGHT;    break;
            case 's':   y++;    dir = DOWN;     break;
            case 'w':   y--;    dir = UP;       break;
            default:
                break;
        }
    }
    else {
        switch (dir) {
            case LEFT:  x--;    break;
            case RIGHT: x++;    break;
            case UP:    y--;    break;
            case DOWN:  y++;    break;
            default:
                break;
        }
    }
    if (x == f_x && y == f_y) {
        setFruit();
        score++;
    }
}

int main() {
    srand(time(NULL));
    setup();
    while (!gameOver) {
        draw();
        logic();
        Sleep(300);
        system("cls");
    }
    return 0;
}