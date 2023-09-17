#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// Бубл сортировка
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

// Сортировка выбором
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

// Сортировка подсчетом
void countingSort(std::vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    std::vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

//Квадратиная сортировка
void squareRootSort(std::vector<int>& arr) {
    int n = arr.size();
    int m = sqrt(n);

    // Подгруппы для сортировки
    std::vector<std::vector<int>> groups;
    // Вспомогательный список
    std::vector<int> aux_list;

    // Делим на группы по sqrt(n) элементов
    for (int i = 0; i < n; i += m) {
        groups.push_back(std::vector<int>(arr.begin() + i, arr.begin() + std::min(i + m, n)));
    }

    // Выбираем наименьший элемент из каждой группы и добавляем во вспомогательный список
    for (auto& group : groups) {
        auto min_itr = std::min_element(group.begin(), group.end());
        aux_list.push_back(*min_itr);
        *min_itr = std::numeric_limits<int>::max(); // Заменяем на максимально возможное значение
    }

    // Заполняем окончательный список
    int idx = 0;
    while (idx < n) {
        auto min_itr = std::min_element(aux_list.begin(), aux_list.end());
        if (min_itr == aux_list.end()) break;
        arr[idx++] = *min_itr;
        *min_itr = std::numeric_limits<int>::max();

        for (auto& group : groups) {
            auto group_min_itr = std::min_element(group.begin(), group.end());
            if (group_min_itr != group.end() && *group_min_itr != std::numeric_limits<int>::max()) {
                aux_list.push_back(*group_min_itr);
                *group_min_itr = std::numeric_limits<int>::max();
            }
        }
    }
}



void fillRandom(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = dis(gen);
    }
}

int main() {
    std::vector<int> sizes = { 1000, 2000, 3000, 4000, 5000 };
    std::vector<void(*)(std::vector<int>&)> sorts = { bubbleSort, selectionSort, countingSort, squareRootSort };

    for (auto& sort : sorts) {
        for (auto& size : sizes) {
            std::vector<int> arr(size);
            fillRandom(arr);
            auto start = std::chrono::high_resolution_clock::now();
            sort(arr);
            auto end = std::chrono::high_resolution_clock::now();
            std::cout << "Time for size " << size << ": "
                << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                << " micro seconds\n";
        }
    }

    return 0;
}
