#include <iostream>
#include <string>

using namespace std;

char g_board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char g_player = 'x';
bool g_checkPlayer = false;
bool g_checkEnd = false;
bool g_checkChoice = true;
int g_choice;
int g_count = 0;
string g_choseChoice = "";

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

void checkChoice() {
choseAgain:
    while (g_choice < 1 || g_choice > 9) {
        cout << "Choose number from 1 to 9: ";
        cin >> g_choice;
    }
    for (int i = 0; i < g_choseChoice.length(); i++) {
        if (g_choice == g_choseChoice[i] - '0') {
            g_checkChoice = false;
            break;
        }
        else {
            g_checkChoice = true;
        }
    }
    while (!g_checkChoice) {
        cout << "Number " << g_choice << " was chosen. Choose another number: ";
        cin >> g_choice;
        goto choseAgain;
    }
}
void Play() {
    cout << "Turn of Player " << g_player << ": ";
    cin >> g_choice;
    checkChoice();
    switch (g_choice) {
        case 1: g_choseChoice += g_board[0][0]; g_board[0][0] = g_player;  break;
        case 2: g_choseChoice += g_board[0][1]; g_board[0][1] = g_player;  break;
        case 3: g_choseChoice += g_board[0][2]; g_board[0][2] = g_player;  break;
        case 4: g_choseChoice += g_board[1][0]; g_board[1][0] = g_player;  break;
        case 5: g_choseChoice += g_board[1][1]; g_board[1][1] = g_player;  break;
        case 6: g_choseChoice += g_board[1][2]; g_board[1][2] = g_player;  break;
        case 7: g_choseChoice += g_board[2][0]; g_board[2][0] = g_player;  break;
        case 8: g_choseChoice += g_board[2][1]; g_board[2][1] = g_player;  break;
        case 9: g_choseChoice += g_board[2][2]; g_board[2][2] = g_player;  break;
    }
    g_count++;
    changePlayer();
}

bool checkEnd() {
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
    int i=0;
    while (!g_checkEnd && g_count != 9) {
        Play();
        printBoard();
        g_checkEnd = checkEnd();
    }
    if (g_count == 9 && !g_checkEnd) {
        cout << "Draw!!" << endl;
    }
    else if (g_checkEnd) {
        changePlayer();
        cout << "Player " << g_player << " is winner!" << endl;
    }
    system("pause");
    system("cls");
    return 0;
}