// Заголовочный файл для класса графа, содержащий объявление методов и полей класса.

#pragma once

#include <vector>
#include <string>

class Graph {
public:
	// Добавить точку в граф с заданными координатами (x, y)
	void addPoint(int x, int y);
	// Соединить все точки в графе линиями, образуя график
	void connectPoints();

	// Сохранить граф в файл в формате "x y\nx y\n...\n---\n"
	// где каждая точка задана координатами (x, y) в одной строке,
	// а символ "---" используется в качестве разделителя между графами в файле
	void saveToFile(const std::string& filepath) const;

	// Загрузить граф из файла в формате, описанном выше
	void loadFromFile(const std::string& filepath);

	// Получить вектор точек, представляющих граф
	const std::vector<std::pair<int, int>>& getPoints() const;
private:
	std::vector<std::pair<int, int>> points; // Вектор точек, представляющих граф
};