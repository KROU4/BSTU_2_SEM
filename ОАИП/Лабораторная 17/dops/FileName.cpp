#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(0, "rus");
    int n;
    std::cout << "������� ���������� ���������: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    auto max_it = std::max_element(arr.begin(), arr.end());
    auto min_it = std::min_element(arr.begin(), arr.end());

    std::cout << "������������ �������: " << *max_it << ", ��� �����: " << std::distance(arr.begin(), max_it) << std::endl;
    std::cout << "����������� �������: " << *min_it << ", ��� �����: " << std::distance(arr.begin(), min_it) << std::endl;

    return 0;
}
