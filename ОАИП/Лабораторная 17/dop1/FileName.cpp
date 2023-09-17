#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr = { 10, 2, 8, 4, 5, 6, 7, 3, 1, 9 };

    std::sort(arr.begin(), arr.begin() + 4); // сортировка первых 4 элементов по возрастанию

    std::sort(arr.end() - 4, arr.end(), std::greater<int>()); // сортировка последних 4 элементов по убыванию

    for (const auto& el : arr) {
        std::cout << el << ' ';
    }

    return 0;
}
