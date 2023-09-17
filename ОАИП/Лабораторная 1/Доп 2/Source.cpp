#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int N = 3;

struct TRAIN
{
    string destination;
    int trainNumber;
    string departureTime;
};

//������� ��� ���������� ������� �� ��������
void sort(TRAIN* trains, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (trains[j].destination > trains[j + 1].destination)
            {
                TRAIN temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ������� ������ �������� ���� TRAIN 
    TRAIN trains[N];

    // ������ ������ � ������� � ����������
    for (int i = 0; i < N; i++)
    {
        cout << "������� �������� ������ ���������� ��� ������ �" << i + 1 << ": ";
        cin >> trains[i].destination;
        cout << "������� ����� ������ �" << i + 1 << ": ";
        cin >> trains[i].trainNumber;
        cout << "������� ����� ����������� ������ �" << i + 1 << ": ";
        cin >> trains[i].departureTime;
        cout << endl;
    }

    // ��������� ������ �� ��������
    sort(trains, N);

    // ����������� � ������������ ����� �����������
    string time;
    cout << "������� ����� �����������: ";
    cin >> time;
    cout << endl;

    // ������� ���������� � �������, ������� ������������ ����� ���������� �������
    bool isFound = false;
    cout << "������, �������������� ����� " << time << " ->" << endl;
    for (int i = 0; i < N; i++)
    {
        if (trains[i].departureTime > time)
        {
            cout << "����� �" << trains[i].trainNumber << " ���� � " << trains[i].destination << " � " << trains[i].departureTime << endl;
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "������� ����� " << time << " ���." << endl;
    }

    return 0;
}