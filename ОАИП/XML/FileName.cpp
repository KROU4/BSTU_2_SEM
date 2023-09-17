#include <iostream>
#include "tinyxml2.h" // Подключение библиотеки TinyXML - 2

int main() {
    setlocale(0, "rus"); // Установка локали для корректного отображения кириллицы

    tinyxml2::XMLDocument doc; // Создание объекта XML-документа
    tinyxml2::XMLError loadResult = doc.LoadFile("example.xml"); // Загрузка XML-файла

    // Проверка успешности загрузки XML-файла
    if (loadResult == tinyxml2::XML_SUCCESS) {
        std::cout << "XML-файл загружен успешно." << std::endl;

        // Получение корневого элемента XML-документа
        tinyxml2::XMLElement* root = doc.FirstChildElement("RootElement");

        // Проверка наличия корневого элемента
        if (root) {
            std::cout << "Корневой элемент найден." << std::endl;
            // Получение первого дочернего элемента с именем "ChildElement"
            tinyxml2::XMLElement* child = root->FirstChildElement("ChildElement");

            // Обход всех дочерних элементов с именем "ChildElement"
            while (child) {
                std::cout << "Дочерний элемент найден." << std::endl;
                // Получение значения атрибута с именем "attribute_name"
                const char* value = child->Attribute("attribute_name");

                // Проверка наличия атрибута и вывод его значения
                if (value) {
                    std::cout << "Значение атрибута: " << value << std::endl;
                }
                else {
                    std::cout << "Атрибут 'имя_атрибута' не найден." << std::endl;
                }

                // Переход к следующему дочернему элементу с именем "ChildElement"
                child = child->NextSiblingElement("ChildElement");
            }
        }
        else {
            std::cout << "Корневой элемент не найден." << std::endl;
        }
    }
    else {
        std::cout << "Не удалось загрузить XML-файл." << std::endl;
    }

    return 0;
}
