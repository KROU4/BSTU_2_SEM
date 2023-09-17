#include "raster_graphics.h"
#include <iostream>
#include <vector>

void displayMenu();
Graph importGraph();
Graph createNewGraph();
bool drawAnotherGraph();
void saveGraphs(const std::vector<Graph>&);

int main() {
	setlocale(LC_ALL, "RUS"); // ��������� ������ ��� �������� �����
	std::vector<Graph> graphs;
	drawAxis(); // ���������� ������������ ���
    while (true) {
        displayMenu(); // ������� ���� �� �����
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            graphs.push_back(importGraph()); // ������������� ������ �� �����
            break;
        case 2:
            graphs.push_back(createNewGraph()); // ������� ����� ������
            break;
        case 3:
            saveGraphs(graphs); // ��������� ������� ������� � ����
            break;
        case 4:
            return 0; // ����� �� ���������
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n"; // ������� ��������� �� ������ ��� �������� ������
        }
    }

    return 0;
}

// ����������� ������� displayMenu(), importGraph(), createNewGraph(), drawAnotherGraph() � saveGraphs() �����

void displayMenu() {
    std::cout << "�������� ��������:\n";
    std::cout << "1. ������ ������� �� �����\n";
    std::cout << "2. ������� ����� ������\n";
    std::cout << "3. ��������� ������� ������� � ����\n";
    std::cout << "4. ����� �� ���������\n";
    std::cout << "��� �����: ";
}

Graph importGraph() {
    std::string filepath;
    std::cout << "������� ���� � �����: ";
    std::cin >> filepath;
    Graph graph;
    try {
        graph.loadFromFile(filepath); // ��������� ������ �� �����
        drawGraph(graph); // ���������� ������
        return graph;
    }
    catch (const std::runtime_error& e) {
        std::cout << "������ ��� �������� �����: " << e.what() << std::endl; // ������� ��������� �� ������ ��� ��������� ��������
        return importGraph(); // ����������� ��������� ������ ��� ���
    }
}

Graph createNewGraph() {
    Graph graph;
    int numPoints;
    std::cout << "������� ���������� ����� (�� 1 �� 10): ";
    std::cin >> numPoints;
    for (int i = 0; i < numPoints; ++i) {
        int x, y;
        std::cout << "������� ���������� ����� " << i + 1 << " (x, y): ";
        std::cin >> x >> y;
        graph.addPoint(x, y); // �������� ����� � ������
    }

    graph.connectPoints(); // ��������� ����� �������
    drawGraph(graph); // ���������� ������
    return createNewGraph();
}