#include <iostream>
#include <string>
#include <windows.h>
#include "LongArithmetic.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    LongArithmetic test;

    int menu = 0;
    while(true) {
        cout << "\n������� ����:\n"
                "1 - ������/������ ��������\n"
                "2 - ��������� �����\n"
                "3 - ��������� ������\n"
                "4 - ��������� �������\n"
                "5 - ��������� ������\n"
                "6 - ��������� ��������� �� ������\n"
                "7 - ��������� �����\n"
                "8 - ��� ���������� ��������\n";
        cin >> menu;
        if (menu == 1) test.setValues();
        else if (menu == 2) test.sum();
        else if (menu == 3) test.sub();
        else if (menu == 4) test.mult();
        else if (menu == 5) test.div();
        else if (menu == 6){
            cout << "\n������ ������ ��� ���������\n";
            int n = 0;
            cin >> n;
            test.longPow(n);
        }
        else if (menu == 7) {
            test.sqrt();
            cout << "\n����� �������� ������ � ����� ������� 11.01 = 12\n";
        }
        else break;
    }
    return 0;
}
