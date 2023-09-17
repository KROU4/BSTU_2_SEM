#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::vector<int> arr = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -5, -4, -3, -2 };

    // Создаем set для удаления дубликатов и автоматической сортировки
    std::set<int> s(arr.begin(), arr.end());

    // Копируем элементы обратно в вектор
    arr.assign(s.begin(), s.end());

    for (const auto& el : arr) {
        std::cout << el << ' ';
    }

    return 0;
}
