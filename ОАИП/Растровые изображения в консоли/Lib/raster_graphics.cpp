#include "raster_graphics.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// ���� �� ���������� � ���������� ����� � �����
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

	graph.connectPoints(); // �������� ����� ������ ������ � ������� connectPoints(), ���� ��� �����������
}

// ���� �� ���������� � �������� ����� �� �����
void test_save_and_load_graph() {
	Graph graph;
	graph.addPoint(1, 2);
	graph.addPoint(3, 4);
	graph.addPoint(5, 6);
	std::string filepath = "test_graph.txt";
	graph.saveToFile(filepath); // ��������� ���� � ����

	Graph loaded_graph;
	loaded_graph.loadFromFile(filepath); // ��������� ���� �� �����

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
		std::cout << "All tests passed!\n"; // ���� ��� ����� �������� �������
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << std::endl; // ���� ���� �� ������, ������� ��������� �� ������
	}
	return 0;
}