#include <iostream>

using namespace std;

void PrintArray(double *arr, const int kArraySize);
int FindIndexAbsMax(double *arr, const int kArraySize);
int FindFirstPosElemIndex(double *arr, const int kArraySize);
double ComputeSum(double *arr, int begin, const int kArraySize);
void SortArray(double *arr, double a, double b, const int kArraySize);

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
