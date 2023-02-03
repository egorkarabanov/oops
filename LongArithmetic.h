#ifndef OOPS_LONGARITHMETIC_H
#define OOPS_LONGARITHMETIC_H

#include <iostream>
#include <string>
#include <windows.h>

namespace std {

    class LongArithmetic {
    private:
        int *valueA;
        int sizeA;
        bool negativeA;

        int *valueB;
        int sizeB;
        bool negativeB;

        int *stringToArray(string str);

        int *sum_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize);

        bool isABigger(int *valueA, int sizeA, int *valueB, int sizeB);

        void stripZeros(int *&arr, int *size);

        int *sub_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize);

        int *intToVeryLong(long long value, int *size);

        int *mult_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize);

        int *div_base(int *maxarr, int maxsize, int *minarr, int minsize, int *tempsize);

        int *pow_base(int *mainarr, int mainsize, int *tempsize, int pownumber);

        int *sqrt_base(int *mainarr, int mainsize, int *tempsize);

        void print_arr(int *arr, int size);


    public:
        LongArithmetic(void);

        LongArithmetic(string value1, string value2);

        void setValues(void);

        LongArithmetic(const LongArithmetic &obj);

        ~LongArithmetic(void);

        void sum(void);

        void sub(void);

        void mult(void);

        void div(void);

        void longPow(int pownumber);

        void sqrt(void);
    };

}

#endif //OOPS_LONGARITHMETIC_H
