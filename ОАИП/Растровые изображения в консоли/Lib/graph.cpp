#include "graph.h"
#include <fstream>

void Graph::addPoint(int x, int y) {
	points.emplace_back(x, y); // Добавление точки в вектор
}

void Graph::connectPoints() {
	// Реализовать логику соединения точек прямыми линиями.
	// Для программы на консоли это может быть достигнуто путем вычисления
	// линейных сегментов и обновления буфера консоли символами линии.
}

void Graph::saveToFile(const std::string& filepath) const {
	std::ofstream outfile(filepath, std::ios::app); // Открыть файл в режиме добавления информации в конец файла
	if (!outfile.is_open()) { // Проверка на открытие файла
		throw std::runtime_error("Не удалось открыть файл для записи"); // Вывод исключения, если файл не был открыт
	}
	for (const auto& point : points) { // Цикл по точкам графика
		outfile << point.first << ' ' << point.second << std::endl; // Запись координат точек в файл
	}
	outfile << "---" << std::endl; // Разделитель между графиками
	outfile.close(); // Закрыть файл
}

void Graph::loadFromFile(const std::string& filepath) {
	std::ifstream infile(filepath); // Открыть файл на чтение
	if (!infile.is_open()) { // Проверка на открытие файла
		throw std::runtime_error("Не удалось открыть файл для чтения"); // Вывод исключения, если файл не был открыт
	}
	points.clear(); // Очистить вектор точек
	int x, y;
	while (infile >> x >> y) { // Цикл по строкам в файле
		points.emplace_back(x, y); // Добавить точку в вектор точек
	}
	infile.close(); // Закрыть файл
}

const std::vector<std::pair<int, int>>& Graph::getPoints() const {
	return points; // Вернуть вектор точек графика
}