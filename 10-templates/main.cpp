#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
void ReadMatrix(T **matrix, int num_rows, int num_cols, ifstream &fin);

template <class T>
void PrintMatrix(T **matrix, int num_rows, int num_cols);

template <class T>
void DeleteRows(T **matrix, int &num_rows, int num_cols);

template <class T>
void DeleteCols(T **matrix, int num_rows, int &num_cols);

template <class T>
int FindFirstPosRow(T **matrix, int num_rows, int num_cols);

template <class T>
int Execute(string file_name);

int main() {
    while (true) {
        string type;
        cout << "Select type (1 - int, 2 - float, 3 - double, e - to close): ";
        cin >> type;

        if (type == "e") {
            return 0;
        }
        else if (type == "1") {
            Execute<int>("int.txt");
        }
        else if (type == "2") {
            Execute<float>("float.txt");
        }
        else if (type == "3") {
            Execute<double>("double.txt");
        }
        else {
            cout << "\nERROR... Enter correct character...\n\n";
        }
    }
}

template <class T>
int Execute(string file_name) {
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "ERROR!!! Can't open file: " << file_name << endl;
        return 1;
    }

    int num_rows, num_cols;
    fin >> num_rows;
    fin >> num_cols;

    T **matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++)
        matrix[i] = new T[num_cols];

    ReadMatrix(matrix, num_rows, num_cols, fin);
    fin.close();

    cout << "\nInitial matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);

    DeleteRows(matrix, num_rows, num_cols);
    DeleteCols(matrix, num_rows, num_cols);
    cout << "\nTransformed matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);

    int first_row_with_pos_element = FindFirstPosRow(matrix, num_rows, num_cols);
    if (first_row_with_pos_element != -1) {
        cout << "\nFirst row containing positive element: ";
        cout << first_row_with_pos_element + 1;
    }
    else {
        cout << "\nArray doesn't have any positive elements...";
    }
    cout << endl;
    cout << endl;

    for (int i = 0; i < num_rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

template <class T>
void ReadMatrix(T **matrix, int num_rows, int num_cols, ifstream &fin) {
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
}

template <class T>
void PrintMatrix(T **matrix, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

template <class T>
void DeleteRows(T **matrix, int &num_rows, int num_cols) {
    int i = 0;
    while (i < num_rows) {
        // Проверяем строку на наличие отличных от нуля элементов
        bool all_zeros = true;
        for (int j = 0; j < num_cols; j++)
            if (abs(matrix[i][j]) > 0) {
                all_zeros = false;
                break;
            }

        // Если строка состоит только из нулевых элементов,
        // переносим ее в конец и сокращаем число строк на 1
        if (all_zeros) {
            for (int l = i; l < num_rows - 1; l++)
                swap(matrix[l], matrix[l + 1]);
            num_rows -= 1;
        }
        else {
            i++;
        }
    }
}

template <class T>
void DeleteCols(T **matrix, int num_rows, int &num_cols) {
    int j = 0;
    while (j < num_cols) {
        // Проверяем столбец на наличие отличных от нуля элементов
        bool all_zeros = true;
        for (int i = 0; i < num_rows; i++)
            if (abs(matrix[i][j]) > 0) {
                all_zeros = false;
                break;
            }

        // Если столбец состоит только из нулевых элементов,
        // переносим его в конец и сокращаем число столбцов на 1
        if (all_zeros) {
            for (int l = j; l < num_cols - 1; l++)
                for (int i = 0; i < num_rows; i++)
                    swap(matrix[i][l], matrix[i][l + 1]);
            num_cols -= 1;
        }
        else {
            j++;
        }
    }
}

template <class T>
int FindFirstPosRow(T **matrix, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            if (matrix[i][j] > 0)
                return i;
    return -1;
}