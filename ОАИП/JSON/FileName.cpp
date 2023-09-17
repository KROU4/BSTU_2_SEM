#include <iostream>         // Подключаем библиотеку для работы с потоками ввода-вывода
#include <nlohmann/json.hpp> // Подключаем библиотеку для работы с JSON
#include <fstream>          // Подключаем библиотеку для работы с файлами

using json = nlohmann::json; // Создаем псевдоним для типа nlohmann::json для удобства

// Функция для чтения JSON-файла и вывода его содержимого на экран
void read_json_file(const std::string& filename) {
    std::ifstream file(filename); // Открываем файл для чтения
    if (file.is_open()) {         // Если файл успешно открыт
        json j;                   // Создаем объект JSON
        file >> j;                // Считываем данные из файла в объект JSON
        // Выводим считанный JSON объект с отступом в 4 пробела
        std::cout << "Считанный JSON объект:\n" << j.dump(4) << std::endl;
    }
    else {
        // Выводим сообщение об ошибке, если файл не удалось открыть
        std::cerr << "Ошибка: Невозможно открыть файл " << filename << std::endl;
    }
}

// Функция для записи JSON-объекта в файл
void write_json_file(const json& j, const std::string& filename) {
    std::ofstream file(filename); // Открываем файл для записи
    if (file.is_open()) {         // Если файл успешно открыт
        file << j.dump(4);        // Записываем JSON объект в файл с отступом в 4 пробела
    }
    else {
        // Выводим сообщение об ошибке, если файл не удалось открыть
        std::cerr << "Ошибка: Невозможно открыть файл " << filename << std::endl;
    }
}

int main() {
    setlocale(0, "rus");       // Устанавливаем локализацию для корректного вывода кириллицы
    int choice;                // Переменная для выбора действия пользователем
    std::string filename;      // Переменная для хранения имени файла
    json person;               // JSON объект для хранения данных о человеке

    while (true) { // Бесконечный цикл для выбора действий пользователем
        std::cout << "Выберите действие:\n"
            << "1. Ввод имени, фамилии и возраста\n"
            << "2. Запись данных в JSON файл\n"
            << "3. Чтение JSON файла\n"
            << "4. Вывод текущих данных\n"
            << "0. Выход\n";
        std::cin >> choice; // Считываем выбор пользователя

        switch (choice) { // Ветвление в зависимости от выбора пользователя
        case 1: {
            std::string name, surname;
            int age;
            // Вводим имя, фамилию и возраст с клавиатуры
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите фамилию: ";
            std::cin >> surname;
            std::cout << "Введите возраст: ";
            std::cin >> age;

            // Сохраняем введенные данные в JSON объект
            person["name"] = name;
            person["surname"] = surname;
            person["age"] = age;
            break;
        }
        case 2: {
            // Вводим имя файла для записи и вызываем функцию записи данных в файл
            std::cout << "Введите имя файла для записи: ";
            std::cin >> filename;
            write_json_file(person, filename);
            break;
        }
        case 3: {
            // Вводим имя файла для чтения и вызываем функцию чтения данных из файла
            std::cout << "Введите имя файла для чтения: ";
            std::cin >> filename;
            read_json_file(filename);
            break;
        }
        case 4: {
            // Выводим текущие данные из JSON объекта на экран с отступом в 4 пробела
            std::cout << "Текущие данные:\n" << person.dump(4) << std::endl;
            break;
        }
        case 0: // Завершаем работу программы
            return 0;
        default: // Выводим сообщение об ошибке при некорректном выборе
            std::cerr << "Неверный выбор. Повторите попытку." << std::endl;
        }
    }

    return 0;
}
