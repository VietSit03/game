#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

char g_board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool g_checkPlayer = false;
bool g_checkEnd = false;
char g_player = 'x';
int choice;
int count = 0;

void changePlayer() {
    if (g_checkPlayer) {
        g_player = 'x';
        g_checkPlayer = !g_checkPlayer;
    }
    else {
        g_player = 'o';
        g_checkPlayer = !g_checkPlayer;
    }
}

void Play() {
    cout << "Turn of Player " << g_player << ": ";
    cin >> choice;
    switch (choice) {
        case 1: g_board[0][0] = g_player; break;
        case 2: g_board[0][1] = g_player; break;
        case 3: g_board[0][2] = g_player; break;
        case 4: g_board[1][0] = g_player; break;
        case 5: g_board[1][1] = g_player; break;
        case 6: g_board[1][2] = g_player; break;
        case 7: g_board[2][0] = g_player; break;
        case 8: g_board[2][1] = g_player; break;
        case 9: g_board[2][2] = g_player; break;
    }
    count++;
    changePlayer();
}

bool endGame() {
    for (int i = 0; i < 3; i++) {
        if (g_board[i][0] == g_board[i][1] && g_board[i][1] == g_board[i][2] || g_board[0][i] == g_board[1][i] && g_board[1][i] == g_board[2][i]) {
            return true;
        }
    }
    if (g_board[0][0] == g_board[1][1] && g_board[1][1] == g_board[2][2] || g_board[0][2] == g_board[1][1] && g_board[1][1] == g_board[2][0]) {
        return true;
    }
    return false;
}

void printBoard() {
    cout << " "<<g_board[0][0]<<" | "<<g_board[0][1]<<" | "<<g_board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " "<<g_board[1][0]<<" | "<<g_board[1][1]<<" | "<<g_board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " "<<g_board[2][0]<<" | "<<g_board[2][1]<<" | "<<g_board[2][2] << endl;
}

int main() {
    printBoard();
    while (!g_checkEnd && count != 9) {
        Play();
        printBoard();
        g_checkEnd = endGame();
    }
    if (count == 9) {
        cout << "Draw!!" << endl;
    }
    else {
        changePlayer();
        cout << "Player " << g_player << " is winning!" << endl;
    }
    return 0;
}