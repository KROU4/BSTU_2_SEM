#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <cstdint>
#include <set>
#include <stdexcept>
#include <chrono>
#include <nmmintrin.h> // Äëÿ _mm_popcnt_u32
#include <random>      // Äëÿ std::mt19937 è std::uniform_int_distribution

size_t simple(const std::vector<uint8_t>& i) {
    for (size_t j = 0; j <= i.size() - 14; ++j) {
        std::set<uint8_t> unique_bytes(i.begin() + j, i.begin() + j + 14);
        if (unique_bytes.size() == 14) {
            return j + 14;
        }
    }
    throw std::runtime_error("No window of size 14 with all unique elements found.");
}

std::optional<size_t> david_a_perez(const std::vector<uint8_t>& input) {
    size_t idx = 0;
    while (idx + 14 <= input.size()) {
        const auto slice = input.begin() + idx;
        uint32_t state = 0;

        auto pos = std::find_if(slice, slice + 14, [&state](uint8_t byte) {
            size_t bit_idx = byte % 32;
            bool ret = state & (1 << bit_idx);
            state |= 1 << bit_idx;
            return ret;
            });

        if (pos != slice + 14) {
            idx += std::distance(slice, pos) + 1;
        }
        else if (_mm_popcnt_u32(state) == 14) {
            return idx;
        }
    }
    return std::nullopt;
}

template<typename Func>
double measure_time(Func func, const std::vector<uint8_t>& input) {
    auto start = std::chrono::high_resolution_clock::now();
    func(input);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

int main() {
    std::vector<uint8_t> input = { 7, 26, 55, 98, 104, 16, 210, 96, 88, 5, 143, 252, 189, 88, 24, 11, 148, 16, 220, 127, 109, 35, 179, 156, 251, 155, 98, 161, 27, 249, 39, 45, 55, 213, 51, 127, 167, 104, 94, 148, 246, 146, 169, 207, 107, 241, 237, 177, 216, 253, 202, 134, 79, 110, 93, 241, 116, 252, 106, 206, 183, 224, 226, 123, 160, 81, 32, 162, 205, 151, 113, 37, 24, 80, 76, 187, 199, 165, 217, 41, 52, 131, 129, 28, 133, 177, 251, 79, 25, 45, 233, 108, 239, 124, 8, 36, 185, 71, 197, 47, 66, 229, 133, 80, 86, 144, 239, 129, 197, 33, 114, 253, 118, 166, 170, 70, 32, 55, 237, 174, 162, 40, 104, 133, 20, 227, 143, 200, 34, 62, 60, 237, 52, 172, 72, 151, 196, 24, 94, 133, 70, 188, 254, 70, 159, 64, 179, 205, 181, 23, 180, 10, 223, 56, 71, 161, 207, 150, 138, 11, 190, 208, 100, 176, 207, 199, 196, 128, 242, 224, 226, 52, 235, 235, 102, 123, 35, 126, 239, 185, 180, 182, 79, 115, 191, 183, 111, 123, 9, 48, 63, 142, 215, 154, 220, 129, 27, 35, 125, 122, 161, 95, 122, 124, 236, 58, 132, 65, 91, 166, 240, 199, 52, 27, 166, 53, 19, 171, 254, 191, 93, 235, 239, 84, 196, 99, 181, 199, 168, 180, 213, 40, 193, 227, 158, 193, 25, 55, 210, 27, 229, 192, 76, 49, 151, 19, 208, 70, 129, 48, 47, 184, 170, 225, 89, 101, 196, 254, 251, 253, 113, 201, 87, 2, 69, 46, 80, 13, 89, 18, 111, 44, 148, 41, 177, 59, 198, 210, 249, 93, 175, 22, 196, 154, 105, 151, 69, 87, 60, 218, 244, 48, 111, 133, 188, 72, 155, 31, 84, 63 };
    while (true) {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Simple algorithm\n";
        std::cout << "2. David A Perez algorithm\n";
        std::cout << "3. View input array\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            auto res = simple(input);
            double duration = measure_time(simple, input);
            std::cout << "Simple algorithm result: " << res << ", time: " << duration << " ms\n";
        }
        break;
        case 2:
        {
            auto res = david_a_perez(input);
            double duration = measure_time(david_a_perez, input);
            if (res) {
                std::cout << "David A Perez algorithm result: " << *res << ", time: " << duration << " ms\n";
            }
            else {
                std::cout << "No window of size 14 with all unique elements found.\n";
            }
        }
        break;
        case 3:
            std::cout << "Input array:\n";
            for (const auto& elem : input) {
                std::cout << static_cast<int>(elem) << ' ';
            }
            std::cout << '\n';
            break;
        case 0:
            return 0;
        default:
            std::cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}