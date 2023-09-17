#include <iostream> //var 8
#include <fstream>
using namespace std;

void generateNumbers(int n, int a[], int index, ofstream& outFile) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            outFile << a[i];
        }
        outFile << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[index] = i;
        generateNumbers(n, a, index + 1, outFile);
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите число А: "; // 3
    cin >> n;

    ofstream outFile("numbers.txt");
    int* a = new int[n];
    generateNumbers(n, a, 0, outFile);

    outFile.close();
    cout << "Готово! Результаты записаны в файл numbers.txt" << endl;

    return 0;
}
