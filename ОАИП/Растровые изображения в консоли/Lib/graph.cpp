#include "graph.h"
#include <fstream>

void Graph::addPoint(int x, int y) {
	points.emplace_back(x, y); // ���������� ����� � ������
}

void Graph::connectPoints() {
	// ����������� ������ ���������� ����� ������� �������.
	// ��� ��������� �� ������� ��� ����� ���� ���������� ����� ����������
	// �������� ��������� � ���������� ������ ������� ��������� �����.
}

void Graph::saveToFile(const std::string& filepath) const {
	std::ofstream outfile(filepath, std::ios::app); // ������� ���� � ������ ���������� ���������� � ����� �����
	if (!outfile.is_open()) { // �������� �� �������� �����
		throw std::runtime_error("�� ������� ������� ���� ��� ������"); // ����� ����������, ���� ���� �� ��� ������
	}
	for (const auto& point : points) { // ���� �� ������ �������
		outfile << point.first << ' ' << point.second << std::endl; // ������ ��������� ����� � ����
	}
	outfile << "---" << std::endl; // ����������� ����� ���������
	outfile.close(); // ������� ����
}

void Graph::loadFromFile(const std::string& filepath) {
	std::ifstream infile(filepath); // ������� ���� �� ������
	if (!infile.is_open()) { // �������� �� �������� �����
		throw std::runtime_error("�� ������� ������� ���� ��� ������"); // ����� ����������, ���� ���� �� ��� ������
	}
	points.clear(); // �������� ������ �����
	int x, y;
	while (infile >> x >> y) { // ���� �� ������� � �����
		points.emplace_back(x, y); // �������� ����� � ������ �����
	}
	infile.close(); // ������� ����
}

const std::vector<std::pair<int, int>>& Graph::getPoints() const {
	return points; // ������� ������ ����� �������
}