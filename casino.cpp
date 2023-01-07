#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

#define timeSpin 3

int* g_num = new int[3];
int g_temp = 0;
int j = 0;
int g_coinPlayer = 100;

void spin() {
    while (j!=3) {
        time_t start = time(0);
        time_t end = time(0);
        while (difftime(end, start) < timeSpin/3) {
            end = time(0);
            for (int i = j; i < 3; i++) {
                    g_num[i] = rand() % 10;
            }
            cout << ".-----------." << endl;    
            cout << "| " << g_num[0] << " | " << g_num[1] << " | " << g_num[2] << " |_" << endl;
            cout << "'-----------' |" << endl;
            cout << "              O" << endl;
            Sleep(300);
            system("cls");
        }
        j++;
    }
    cout << ".-----------." << endl;
    cout << "| " << g_num[0] << " | " << g_num[1] << " | " << g_num[2] << " |_" << endl;
    cout << "'-----------' |" << endl;
    cout << "              O" << endl;
    j = 0;
    return ;
}

void updateCoin(int coin) {
    if (g_num[0] == g_num[1] && g_num[2] == g_num[1]) {
        g_coinPlayer += coin * 49;
        cout << "Congratulation!!! You won " << coin*50 << " coin!!!" << endl;
    }
    else if (g_num[0] == g_num[1] || g_num[1] == g_num[2] || g_num[2] == g_num[0]) {
        g_coinPlayer -= coin;
        cout << "So close!" << endl;
    }
    else {
        g_coinPlayer -= coin;
        cout << "Unlucky!" << endl;
    }
    system("pause");
}

void home() {
    cout << ".-----------. O" << endl;
    cout << "| 8 | 8 | 8 |_|" << endl;
    cout << "'-----------'" << endl;
    cout << "Your wallet: " << g_coinPlayer << " coins" << endl;
}

void checkCoin(int& coin) {
    while (coin > g_coinPlayer) {
        cout << "Your wallet contains: " << g_coinPlayer << ", insert coin again: ";
        cin >> coin;
    }
}

void menu(int& choice, int& coin) {
    cout << "Insert coin: ";
    cin >> coin;
    checkCoin(coin);
    cout << "1. Spin." << endl;
    cout << "2. Change coin." << endl;
    cout << "3. Exit." << endl;
    cout << "Select choice: ";
    cin >> choice;
}

bool checkChoice(int& choice, int& coin) {
    switch (choice) {
        case 1:
            system("cls");
            spin();
            return true;
        case 2:
            menu(choice, coin);
            return checkChoice(choice, coin);
        case 3:
            return false;
        default:
            cout << "Wrong choice. Select choice again: ";
            cin >> choice;
            return checkChoice(choice,coin);
    }
}

void start() {
    static int choice, coin;
    menu(choice, coin);
    if (checkChoice(choice,coin)) {
        updateCoin(coin);
        system("cls");
        home();
        start();
    }
}

int main() {
    srand(time(0));
    home();
    start();
    return 0;
}
