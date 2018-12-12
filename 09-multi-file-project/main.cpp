#include "functions.h"

int main() {
    const int kArraySize = 10;
    double arr[kArraySize] = { 0, -1.9, -2, -3.1, -4, 5.1, -6, -7.1, 1.8, 0.9 };

    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);

    cout << "\nIndex of the absolute maximum element of the array: ";
    cout << FindIndexAbsMax(arr, kArraySize) + 1 << endl;

    int index_first_pos_elem = FindFirstPosElemIndex(arr, kArraySize);
    if (index_first_pos_elem != -1) {
        cout << "\nSum after first positive element is: ";
        cout << ComputeSum(arr, index_first_pos_elem + 1, kArraySize) << endl;
    }
    else {
        cout << "\nArray doesn't have any positive elements...\n";
    }

    double a, b;
    cout << "\nEnter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    SortArray(arr, a, b, kArraySize);
    cout << "\nTransformed array:\n";
    PrintArray(arr, kArraySize);
}