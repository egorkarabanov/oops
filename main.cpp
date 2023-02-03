#include <iostream>
#include <string>
#include <windows.h>
#include "LongArithmetic.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    LongArithmetic test;

    int menu = 0;
    while(true) {
        cout << "\nГоловне меню:\n"
                "1 - ввести/змінити значення\n"
                "2 - визначити сумму\n"
                "3 - визначити різницю\n"
                "4 - визначити добуток\n"
                "5 - визначити частку\n"
                "6 - визначити піднесення до степіню\n"
                "7 - обчислити корінь\n"
                "8 - для завершення програми\n";
        cin >> menu;
        if (menu == 1) test.setValues();
        else if (menu == 2) test.sum();
        else if (menu == 3) test.sub();
        else if (menu == 4) test.mult();
        else if (menu == 5) test.div();
        else if (menu == 6){
            cout << "\nвведіть степінь для піднесення\n";
            int n = 0;
            cin >> n;
            test.longPow(n);
        }
        else if (menu == 7) {
            test.sqrt();
            cout << "\nКорінь береться завжди у більшу сторону 11.01 = 12\n";
        }
        else break;
    }
    return 0;
}
