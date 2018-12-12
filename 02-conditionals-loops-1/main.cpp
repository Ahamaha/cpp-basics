#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double kEps = 1e-15;

    double a, b, c, xn, xk, dx;
    cout << fixed;
    cout << "Please, enter a, b, c: ";
    cin >> a >> b >> c;
    cout << "Please, enter X.start, X.end, dx: ";
    cin >> xn >> xk >> dx;

    // Проверяем корректность шага функции,
    // во избежание образования бесконечного цикла
    if (dx > 0) {
        // Создаем шапку таблицы
        cout << string(36, '-') << endl;
        cout << "|" << setw(9) << "x" << setw(9);
        cout << "|" << setw(9) << "F" << setw(9) << "|\n";
        cout << string(36, '-') << endl;

        // Выводим на экран таблицу и заполняем
        // её значениями, вычисленными по заданным формулам
        for (double x = xn; x <= xk; x += dx) {
            cout << "|" << setw(17) << x << "|" << setw(16);
            double F;
            if (x < 0.6 && abs(b + c) > kEps) {
                F = a * pow(x, 3) + pow(b, 2) + c;
            }
            else if (x > 0.6 && abs(b + c) < kEps) {
                if (abs(x - c) > kEps) {
                    F = (x - a) / (x - c);
                }
                else {
                    cout << " ERROR div by 0 |\n";
                    continue;
                }
            }
            else {
                if (abs(c) > kEps && abs(a) > kEps) {
                    F = x / c + x / a;
                }
                else {
                    cout << " ERROR div by 0 |\n";
                    continue;
                }
            }

            int ac = static_cast<int>(a);
            int bc = static_cast<int>(b);
            int cc = static_cast<int>(c);
            if ((ac | bc) & cc)
                cout << F;
            else
                cout << static_cast<int>(F);
            cout << "|\n";
        }
        cout << string(36, '-');
    }
    else {
        cout << "Incorrect value of dx!!!";
    }

    return 0;
}