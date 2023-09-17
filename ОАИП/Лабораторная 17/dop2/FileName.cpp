#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::vector<int> arr = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -5, -4, -3, -2 };

    // ������� set ��� �������� ���������� � �������������� ����������
    std::set<int> s(arr.begin(), arr.end());

    // �������� �������� ������� � ������
    arr.assign(s.begin(), s.end());

    for (const auto& el : arr) {
        std::cout << el << ' ';
    }

    return 0;
}
