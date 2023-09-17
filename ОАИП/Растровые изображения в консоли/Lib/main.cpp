#include "raster_graphics.h"
#include <iostream>
#include <vector>

void displayMenu();
Graph importGraph();
Graph createNewGraph();
bool drawAnotherGraph();
void saveGraphs(const std::vector<Graph>&);

int main() {
	setlocale(LC_ALL, "RUS"); // Установка локали для русского языка
	std::vector<Graph> graphs;
	drawAxis(); // Нарисовать координатные оси
    while (true) {
        displayMenu(); // Вывести меню на экран
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            graphs.push_back(importGraph()); // Импортировать график из файла
            break;
        case 2:
            graphs.push_back(createNewGraph()); // Создать новый график
            break;
        case 3:
            saveGraphs(graphs); // Сохранить текущие графики в файл
            break;
        case 4:
            return 0; // Выйти из программы
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n"; // Вывести сообщение об ошибке при неверном выборе
        }
    }

    return 0;
}

// Реализовать функции displayMenu(), importGraph(), createNewGraph(), drawAnotherGraph() и saveGraphs() здесь

void displayMenu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Импорт графика из файла\n";
    std::cout << "2. Создать новый график\n";
    std::cout << "3. Сохранить текущие графики в файл\n";
    std::cout << "4. Выйти из программы\n";
    std::cout << "Ваш выбор: ";
}

Graph importGraph() {
    std::string filepath;
    std::cout << "Введите путь к файлу: ";
    std::cin >> filepath;
    Graph graph;
    try {
        graph.loadFromFile(filepath); // Загрузить график из файла
        drawGraph(graph); // Нарисовать график
        return graph;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Ошибка при загрузке файла: " << e.what() << std::endl; // Вывести сообщение об ошибке при неудачной загрузке
        return importGraph(); // Попробовать загрузить график еще раз
    }
}

Graph createNewGraph() {
    Graph graph;
    int numPoints;
    std::cout << "Введите количество точек (от 1 до 10): ";
    std::cin >> numPoints;
    for (int i = 0; i < numPoints; ++i) {
        int x, y;
        std::cout << "Введите координаты точки " << i + 1 << " (x, y): ";
        std::cin >> x >> y;
        graph.addPoint(x, y); // Добавить точку в график
    }

    graph.connectPoints(); // Соединить точки линиями
    drawGraph(graph); // Нарисовать график
    return createNewGraph();
}