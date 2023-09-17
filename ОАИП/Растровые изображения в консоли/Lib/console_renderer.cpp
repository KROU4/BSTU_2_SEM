#include "console_renderer.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

const int WIDTH = 50;
const int HEIGHT = 20;

void ConsoleRenderer::drawAxis(const Graph& graph) {
	// ���������� ������������ ��� ��������� ������� ��������� �����.
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			if (x == WIDTH / 2) {
				std::cout << '|';
			}
			else if (y == HEIGHT / 2) {
				std::cout << '-';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void ConsoleRenderer::drawGraph(const Graph& graph) {
	// ������� 2D-������, �������������� ������������ �������
	std::vector<std::vector<char>> consoleSpace(HEIGHT, std::vector<char>(WIDTH, ' '));
	// ���������� ������������ ��� � 2D-�������
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			if (x == WIDTH / 2) {
				consoleSpace[y][x] = '|';
			}
			else if (y == HEIGHT / 2) {
				consoleSpace[y][x] = '-';
			}
		}
	}

	// ���������� ����� ������� � 2D-�������
	const auto& points = graph.getPoints();
	for (const auto& point : points) {
		int x = WIDTH / 2 + point.first;
		int y = HEIGHT / 2 - point.second;

		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
			consoleSpace[y][x] = 'o';
		}
	}

	// ���������� ����� ����� ������� � 2D-�������
	// ����� ������������ �������� ��������� �����, ��������, �������� ����������

	// ������� ���������� 2D-������� � �������
	for (const auto& row : consoleSpace) {
		for (char c : row) {
			std::cout << c;
		}
		std::cout << std::endl;
	}
}