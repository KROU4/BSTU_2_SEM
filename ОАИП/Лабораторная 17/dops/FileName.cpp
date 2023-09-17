#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(0, "rus");
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    auto max_it = std::max_element(arr.begin(), arr.end());
    auto min_it = std::min_element(arr.begin(), arr.end());

    std::cout << "Максимальный элемент: " << *max_it << ", его номер: " << std::distance(arr.begin(), max_it) << std::endl;
    std::cout << "Минимальный элемент: " << *min_it << ", его номер: " << std::distance(arr.begin(), min_it) << std::endl;

    return 0;
}
