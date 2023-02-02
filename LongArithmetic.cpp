#include "LongArithmetic.h"

#define la LongArithmetic
namespace std {
    int *la::stringToArray(string str) {
        string buffer;
        int *array = new int[str.size()];
        for (int i = 0; i < str.size(); i++) {
            buffer = str[i];
            array[i] = stoi(buffer);
        }
        return array;
    }

    int *la::sum_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize) {
        *tempsize = maxsize;
        int *temparr = new int[(*tempsize) + 1]{0};
        for (int i = 0; i < minsize; i++) {
            temparr[i] = maxarr[i] + minarr[i];
        }
        for (int i = minsize; i < maxsize; i++) {
            temparr[i] = maxarr[i];
        }
        for (int i = 0; i < maxsize; i++) {
            if (temparr[i] >= 10) {
                temparr[i] -= 10;
                temparr[i + 1]++;
            }
        }
        if (temparr[*tempsize] != 0) {
            (*tempsize) += 1;
        }
        return temparr;
    }

    bool la::isABigger(int *valueA, int sizeA, int *valueB, int sizeB) {
        if (sizeA == sizeB) {
            for (int i = 0; i < sizeA; i++) {
                if (valueA[sizeA - i - 1] > valueB[sizeA - i - 1]) return true;
                if (valueA[sizeA - i - 1] < valueB[sizeA - i - 1]) return false;
            }
        } else {
            return sizeA > sizeB ? true : false;
        }
        return true;
    }

    void la::stripZeros(int *&arr, int *size) {
        int count = 0;
        for (int i = 0; i < *size; i++) {
            if (arr[i] == 0) count++;
            if (arr[i] != 0)count = 0;
        }
        if (count == *size) {
            *size = 1;
            arr = new int[1]{0};
        } else {
            *size -= count;
            int *temparr = new int[*size];
            for (int i = 0; i < *size; i++) {
                temparr[i] = arr[i];
            }
            delete arr;
            arr = temparr;
        }
    }

    int *la::sub_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize) {
        *tempsize = maxsize;
        int *temparr = new int[(*tempsize)]{0};
        for (int i = 0; i < minsize; i++) {
            temparr[i] = maxarr[i] - minarr[i];
        }
        for (int i = minsize; i < maxsize; i++) {
            temparr[i] = maxarr[i];
        }
        for (int i = 0; i < maxsize; i++) {
            if (temparr[i] < 0) {
                temparr[i] += 10;
                temparr[i + 1]--;
            }
        }
        stripZeros(temparr, tempsize);
        return temparr;
    }

    int *la::intToVeryLong(long long value, int *size) {
        int *temparr = new int[(*size)]{0};
        int i = 0;
        while (value > 0) {
            temparr[i] = value % 10;
            value /= 10;
            i++;
        }
        *size = i;
        stripZeros(temparr, size);
        return temparr;
    }

    int *la::mult_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize) {
        *tempsize = maxsize * maxsize + 1;
        int *temparr = new int[(*tempsize)]{0};

        for (int i = 0; i < minsize; i++) {
            for (int j = 0; j < maxsize; j++) {
                temparr[i + j] += minarr[i] * maxarr[j];
            }
        }
        for (int i = 0; i < *tempsize; i++) {
            temparr[i + 1] += temparr[i] / 10;
            temparr[i] %= 10;
        }
        stripZeros(temparr, tempsize);
        return temparr;
    }

    int *la::div_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize) {
        *tempsize = maxsize;
        int *temparr = new int[(*tempsize)]{0};

        int *size1 = new int(10);
        int *var = intToVeryLong(0, size1);

        int *sizeOne = new int(10);
        int *one = intToVeryLong(1, sizeOne);

        while (isABigger(maxarr, maxsize, minarr, minsize)) {
            maxarr = sub_base(maxarr, maxsize, minarr, minsize, tempsize);
            maxsize = *tempsize;

            var = sum_base(var, *size1, one, *sizeOne, size1);
        }

        *tempsize = int(*size1);

        delete size1;
        delete sizeOne;
        delete[] one;
        delete[] temparr;

        return var;
    }

    int *la::pow_base(int *mainarr, int mainsize, int *tempsize, int pownumber) {
        *tempsize = int(mainsize);
        int *temparr = new int[(*tempsize)]{0};

        for (int i = 0; i < mainsize; i++) {
            temparr[i] = mainarr[i];
        }

        for (int i = 0; i < pownumber - 1; i++) {
            int *t = new int(0);
            temparr = mult_base(temparr, *tempsize, mainarr, mainsize, t);
            *tempsize = int(*t);
            delete t;
        }
        return temparr;
    }

    int *la::sqrt_base(int *mainarr, int mainsize, int *tempsize) {
        int *size1 = new int(10);
        int *tempvar = intToVeryLong(1, size1);

        int *size2 = new int(10);
        int *a = 0;

        int *sizeOne = new int(10);
        int *one = intToVeryLong(1, sizeOne);

        while (true) {
            a = pow_base(tempvar, *size1, size2, 2);
            if (isABigger(a, *size2, mainarr, mainsize)) {
                break;
            }
            tempvar = sum_base(tempvar, *size1, one, *sizeOne, size1);
        }
        *tempsize = int(*size1);

        delete size1;
        delete size2;
        delete[] a;
        delete sizeOne;
        delete[] one;

        return tempvar;
    }

    void la::print_arr(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[size - i - 1];
        }
        cout << endl;
    }

    la::LongArithmetic(void) {
        valueA = new int[1]{0};
        sizeA = 1;
        valueB = new int[1]{0};
        sizeB = 1;
        negativeA = false;
        negativeB = false;
    }

    la::LongArithmetic(string value1, string value2) {
        if (value1[0] == '-') {
            negativeA = true;
            value1 = value1.substr(1);
        }
        sizeA = value1.size();
        reverse(value1.begin(), value1.end());
        valueA = stringToArray(value1);

        if (value2[0] == '-') {
            negativeB = true;
            value2 = value2.substr(1);
        }
        sizeB = value2.size();
        reverse(value2.begin(), value2.end());
        valueB = stringToArray(value2);
    }

    void la::setValues(void) {
        string buffer;
        cout << "Input number A:";
        cin >> buffer;
        if (buffer[0] == '-') {
            negativeA = true;
            buffer = buffer.substr(1);
        }
        sizeA = buffer.size();
        reverse(buffer.begin(), buffer.end());
        valueA = stringToArray(buffer);

        cout << "Input number B:";
        cin >> buffer;
        if (buffer[0] == '-') {
            negativeB = true;
            buffer = buffer.substr(1);
        }
        sizeB = buffer.size();
        reverse(buffer.begin(), buffer.end());
        valueB = stringToArray(buffer);
    }

    la::LongArithmetic(const LongArithmetic &obj) : sizeA(obj.sizeA), sizeB(obj.sizeB) {
        negativeA = !(obj.negativeA);
        negativeB = !(obj.negativeB);
        valueA = new int[sizeA];
        for (int i = 0; i < sizeA; i++) {
            valueA[i] = obj.valueA[i];
        }
        valueB = new int[sizeB];
        for (int i = 0; i < sizeB; i++) {
            valueB[i] = obj.valueB[i];
        }
    }

    la::~LongArithmetic(void) {
        delete[] valueB;
        delete[] valueA;
    }

    void la::sum(void) {
        int *tempsize = new int(0);
        int *temparr = 0;
        bool tempNegative = false;
        if (isABigger(valueA, sizeA, valueB, sizeB)) {
            if (!negativeA and !negativeB) {
                tempNegative = false;
                temparr = sum_base(valueA, sizeA, valueB, sizeB, tempsize);
            } else if (negativeA and negativeB) {
                tempNegative = true;
                temparr = sum_base(valueA, sizeA, valueB, sizeB, tempsize);
            } else if (!negativeA and negativeB) {
                tempNegative = false;
                temparr = sub_base(valueA, sizeA, valueB, sizeB, tempsize);
            } else {
                tempNegative = true;
                temparr = sub_base(valueA, sizeA, valueB, sizeB, tempsize);
            }
        } else {
            if (!negativeA and !negativeB) {
                tempNegative = false;
                temparr = sum_base(valueB, sizeB, valueA, sizeA, tempsize);
            } else if (negativeA and negativeB) {
                tempNegative = true;
                temparr = sum_base(valueB, sizeB, valueA, sizeA, tempsize);
            } else if (!negativeA and negativeB) {
                tempNegative = true;
                temparr = sub_base(valueB, sizeB, valueA, sizeA, tempsize);
            } else {
                tempNegative = false;
                temparr = sub_base(valueB, sizeB, valueA, sizeA, tempsize);
            }
        }
        if (tempNegative) cout << "-";
        print_arr(temparr, *tempsize);

        delete[] temparr;
        delete tempsize;
    }

    void la::sub(void) {
        negativeB = !negativeB;
        sum();
        negativeB = !negativeB;
    }

    void la::mult(void) {
        int *tempsize = new int(0);
        int *temparr = 0;
        bool tempNegative = false;
        if ((!negativeA and !negativeB) or (negativeA and negativeB)) {
            tempNegative = false;
        } else {
            tempNegative = true;
        }
        if (isABigger(valueA, sizeA, valueB, sizeB)) {
            temparr = mult_base(valueA, sizeA, valueB, sizeB, tempsize);
        } else {
            temparr = mult_base(valueB, sizeB, valueA, sizeA, tempsize);
        }

        if (tempNegative) cout << "-";
        print_arr(temparr, *tempsize);

        delete[] temparr;
        delete tempsize;
    }

    void la::div(void) {
        int *tempsize = new int(0);
        int *temparr = 0;
        bool tempNegative = false;
        if ((!negativeA and !negativeB) or (negativeA and negativeB)) {
            tempNegative = false;
        } else {
            tempNegative = true;
        }

        if (isABigger(valueA, sizeA, valueB, sizeB)) {
            temparr = div_base(valueA, sizeA, valueB, sizeB, tempsize);
        } else {
            temparr = div_base(valueB, sizeB, valueA, sizeA, tempsize);
        }

        if (tempNegative) cout << "-";
        print_arr(temparr, *tempsize);

        delete[] temparr;
        delete tempsize;
    }

    void la::longPow(int pownumber) {
        int *tempsize = new int();
        int *temparr = 0;
        bool tempNegative = false;
        if (pownumber % 2 == 0 or !negativeA) {
            tempNegative = false;
        } else {
            tempNegative = true;
        }
        temparr = pow_base(valueA, sizeA, tempsize, pownumber);

        if (tempNegative) cout << "-";
        print_arr(temparr, *tempsize);

        delete[] temparr;
        delete tempsize;
    }

    void la::sqrt(void) {
        if (negativeA) return;
        int *tempsize = new int(0);
        int *temparr = 0;

        temparr = sqrt_base(valueA, sizeA, tempsize);

        print_arr(temparr, *tempsize);

        delete[] temparr;
        delete tempsize;
    }
}