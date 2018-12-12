#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    cout << "Write a: \n";
    cin >> a;

    double z1 = (sin(4 * a) * cos(2 * a)) / ((1 + cos(4 * a)) * (1 + cos(2 * a)));
    double z2 = tan(a); // Мат. свойство: ctg(3/2*pi - а) = tg(a)

    cout << "\nz1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    return 0;
}
