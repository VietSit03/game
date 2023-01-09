#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 25;
const int height = 20;
bool gameOver;
int g_x = width/2, g_y = height/2;
int score = 0;
enum eDirection {STOP, UP, DOWN, LEFT, RIGHT};
eDirection dir = STOP;

struct position {
    int x, y;
    char c;
};

class snake {
    private:
        int length;
        position* pos = new position[(width-1)*(height-1)];
    public:
        snake() {
            length = 1;
            pos[0].x = g_x;
            pos[0].y = g_y;
            pos[0].c = '@';
        };
        int getLength() {
            return this->length;
        }
        int getPosX(int i) {
            return this->pos[i].x;
        }
        int getPosY(int i) {
            return this->pos[i].y;
        }
        char getPosC(int i) {
            return this->pos[i].c;
        }
        void move() {
            for (int i = length-1; i > 0; i--) {
                pos[i].x = pos[i-1].x;
                pos[i].y = pos[i-1].y;
            }
            pos[0].x = g_x;
            pos[0].y = g_y;
        }
        void eat() {
            score++;
            length++;
            pos[length-1].c = 'o';
            move();
        }

};
snake s;

class fruit {
    private:
        int score;
        position pos;
    public:
        fruit () {
            score = 1;
            setPos(s);
        }
        int getScore() {
            return score;
        }
        void setPos(snake s) {
            pos.x = 1 + rand() % (width-2);
            pos.y = 1 + rand() % (height-2);
            pos.c = '$';
            for (int i = 0; i < s.getLength(); i++) {
                while (pos.x == s.getPosX(i) && pos.y == s.getPosY(i)) {
                    pos.x = 1 + rand() % (width-2);
                    pos.y = 1 + rand() % (height-2);
                }
            }    
        }
        int getPosX() {
            return pos.x;
        }
        int getPosY() {
            return pos.y;
        }
        char getPosC() {
            return pos.c;
        }
};
fruit f;

bool checkSnake(int i, int j) {
    for (int k = 0; k < s.getLength(); k++) {
        if (s.getPosY(k) == i && s.getPosX(k) == j) {
            cout << s.getPosC(k);
            return true;
        }
    }
    return false;
}
void draw() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height-1) {
                cout << "#";
            }
            else if (j == 0 || j == width-1) {
                cout << "#";
            }
            else if (i == f.getPosY() && j == f.getPosX()) {
                cout << f.getPosC();
            }
            else if (checkSnake(i, j)) {
                
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Your score: " << score << endl;
}

void logic() {
    if (kbhit()) {
        switch (getch()) {
            case 'a':   if (dir != RIGHT) { g_x--; dir = LEFT; break; } goto loop;
            case 'd':   if (dir != LEFT) { g_x++; dir = RIGHT; break; } goto loop;
            case 's':   if (dir != UP) { g_y++; dir = DOWN; break; } goto loop;
            case 'w':   if (dir != DOWN) { g_y--; dir = UP; break; } goto loop;
            default: break;
        }
    }
    else {
loop:
        switch (dir) {
            case LEFT: g_x--; break;
            case RIGHT: g_x++; break;
            case DOWN: g_y++; break;
            case UP: g_y--; break;
            default: break;
        }
    }
    if (g_x == 0 || g_x == width-1 || g_y == 0 || g_y == height-1) {
        gameOver = true;
        return ;
    }
    for (int i = 1; i < s.getLength(); i++) {
        if (s.getPosX(i) == g_x && s.getPosY(i) == g_y) {
            gameOver = true;
            return ;
        }
    }
    if (g_x == f.getPosX() && g_y == f.getPosY()) {
        s.eat();
        f.setPos(s);
    }
    else {
        s.move();
    }
    
}

int main() {
    srand(time(0));
    while (!gameOver) {
        draw();
        logic();
        Sleep(300);
        system("cls");
    }
    draw();
    cout << "Game Over" << endl;
    return 0;
}