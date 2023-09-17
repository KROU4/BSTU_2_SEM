// ������������ ���� ��� ������ �����, ���������� ���������� ������� � ����� ������.

#pragma once

#include <vector>
#include <string>

class Graph {
public:
	// �������� ����� � ���� � ��������� ������������ (x, y)
	void addPoint(int x, int y);
	// ��������� ��� ����� � ����� �������, ������� ������
	void connectPoints();

	// ��������� ���� � ���� � ������� "x y\nx y\n...\n---\n"
	// ��� ������ ����� ������ ������������ (x, y) � ����� ������,
	// � ������ "---" ������������ � �������� ����������� ����� ������� � �����
	void saveToFile(const std::string& filepath) const;

	// ��������� ���� �� ����� � �������, ��������� ����
	void loadFromFile(const std::string& filepath);

	// �������� ������ �����, �������������� ����
	const std::vector<std::pair<int, int>>& getPoints() const;
private:
	std::vector<std::pair<int, int>> points; // ������ �����, �������������� ����
};