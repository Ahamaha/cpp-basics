#include "functions.h"

void PrintArray(double *arr, const int kArraySize) {
    for (int i = 0; i < kArraySize; i++)
        cout << "[" << i + 1 << "] " << arr[i] << endl;
}

int FindIndexAbsMax(double *arr, const int kArraySize) {
    int imax = 0;
    double max = arr[0];
    for (int i = 1; i < kArraySize; i++) {
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
            imax = i;
        }
    }
    return imax;
}

int FindFirstPosElemIndex(double *arr, const int kArraySize) {
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] > 0)
            return i;

    return -1;
}

double ComputeSum(double *arr, int begin, const int kArraySize) {
    double sum = 0;
    for (int i = begin; i < kArraySize; i++)
        sum += arr[i];
    return sum;
}

void SortArray(double *arr, double a, double b, const int kArraySize) {
    int j = 0;
    for (int i = 0; i < kArraySize; i++) {
        int integer_part = static_cast<int>(arr[i]);
        if (a <= integer_part && integer_part <= b) {
            for (int l = i; l > j; l--)
                swap(arr[l], arr[l - 1]);
            j++;
        }
    }
}