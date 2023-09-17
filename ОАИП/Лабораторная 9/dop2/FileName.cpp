#include <iostream> //var 3
#include <fstream>
using namespace std;

void generateNumbers(int n, int a[], int index, ofstream& outFile) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            outFile << a[i] << " ";
        }
        outFile << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < index; j++) {
            if (a[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            a[index] = i;
            generateNumbers(n, a, index + 1, outFile);
        }
    }
}

int main() {
    int n = 5; // 1 2 3 4 5
    int* a = new int[n];
    ofstream outFile("output.txt");
    generateNumbers(n, a, 0, outFile);
    outFile.close();
    cout << "Done!" << endl;
    return 0;
}

