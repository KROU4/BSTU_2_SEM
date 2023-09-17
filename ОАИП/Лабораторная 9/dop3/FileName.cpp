#include <iostream> //var 4
#include <string>

using namespace std;

void findSymbol(string alphabet, int index, string& currentString)
{
    if (27 > index)
    {
        currentString = alphabet[index] + currentString;
        findSymbol(alphabet, index + 1, currentString);
    }

}

int main() {
    setlocale(LC_ALL, "rus");

    int N;

    cout << "¬ведите N: "; cin >> N;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string currentString;

    findSymbol(alphabet, 0, currentString);

    cout << currentString[N - 1];
}
