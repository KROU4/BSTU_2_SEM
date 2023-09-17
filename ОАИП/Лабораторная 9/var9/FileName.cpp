#include <iostream>
using namespace std;

int sum(int n, int m) {
    if (m == 0) {
        return n;
    }
    else {
        return sum(n + 1, m - 1);
    }
}

int diff(int n, int m) { // вычитание
    if (m == 0) {
        return n;
    }
    else {
        return diff(n - 1, m - 1);
    }
}

int mul(int n, int m) { // умножение
    if (m, m == 0) {
        return 0;
    }
    else {
        return n + mul(n, m - 1);
    }
}

int pow(int n, int m) { // возведение в степень
    if (m == 0) {
        return 1;
    }
    else {
        return n * pow(n, m - 1);
    }
}

int main() {
    int n = 4, m = 3;
    cout << "n + m = " << sum(n, m) << endl;
    cout << "n - m = " << diff(n, m) << endl;
    cout << "n * m = " << mul(n, m) << endl;
    cout << "n ^ m = " << pow(n, m) << endl;
    return 0;
}
