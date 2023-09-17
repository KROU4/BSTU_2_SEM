#include "raster_graphics.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// Тест на добавление и связывание точек в графе
void test_add_and_connect_points() {
	Graph graph;
	graph.addPoint(0, 0);
	graph.addPoint(1, 1);
	graph.addPoint(2, 0);
	const auto& points = graph.getPoints();
	assert(points.size() == 3);
	assert(points[0] == std::make_pair(0, 0));
	assert(points[1] == std::make_pair(1, 1));
	assert(points[2] == std::make_pair(2, 0));

	graph.connectPoints(); // Проверка любой другой логики в функции connectPoints(), если она реализована
}

// Тест на сохранение и загрузку графа из файла
void test_save_and_load_graph() {
	Graph graph;
	graph.addPoint(1, 2);
	graph.addPoint(3, 4);
	graph.addPoint(5, 6);
	std::string filepath = "test_graph.txt";
	graph.saveToFile(filepath); // Сохраняем граф в файл

	Graph loaded_graph;
	loaded_graph.loadFromFile(filepath); // Загружаем граф из файла

	const auto& points = loaded_graph.getPoints();
	assert(points.size() == 3);
	assert(points[0] == std::make_pair(1, 2));
	assert(points[1] == std::make_pair(3, 4));
	assert(points[2] == std::make_pair(5, 6));
}

int main() {
	try {
		test_add_and_connect_points();
		test_save_and_load_graph();
		std::cout << "All tests passed!\n"; // Если все тесты пройдены успешно
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << std::endl; // Если тест не прошел, выводим сообщение об ошибке
	}
	return 0;
}