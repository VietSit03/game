#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

#define timeSpin 3

int* g_num = new int[3];
int g_temp = 0;
int j = 0;

void spin() {
    while (j!=3) {
        time_t start = time(0);
        time_t end = time(0);
        while (difftime(end, start) < timeSpin/3) {
            end = time(0);
            for (int i = j; i < 3; i++) {
                    g_num[i] = rand() % 10;
            }
            cout << "| " << g_num[0] << " | " << g_num[1] << " | " << g_num[2] << " |" << endl;
            Sleep(300);
            system("cls");
        }
        j++;
    }
    cout << "| " << g_num[0] << " | " << g_num[1] << " | " << g_num[2] << " |" << endl;
    j = 0;
    return ;
}

void check(int coin) {
    if (g_num[0] == g_num[1] && g_num[2] == g_num[1]) {
        cout << "Congratulation!!! You won " << coin*50 << "!!!" << endl;
    }
    else if (g_num[0] == g_num[1] || g_num[1] == g_num[2] || g_num[2] == g_num[0]) {
        cout << "So close!" << endl;
    }
    else {
        cout << "Unlucky!" << endl;
    }
    system("pause");
}
int main() {
    srand(time(0));
    cout << "| 8 | 8 | 8 |" << endl;
    int coin, choice;
loop:
    cout << "Insert coin: "; cin >> coin;
    cout << "1. Spin." << endl;
    cout << "2. Change coin." << endl;
    cout << "3. Exit." << endl;
    cout << "Select choice: "; cin >> choice;
    switch (choice) {
        case 1:
            system("cls");
            spin();
            break;
        case 2:
            goto loop;
        case 3:
            return 0;
    }
    check(coin);
    system("cls");
    cout << "| 8 | 8 | 8 |" << endl;
    goto loop;
    return 0;
}