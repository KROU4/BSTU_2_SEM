#pragma once

#include "graph.h"

// ��������� ������������ ����
void drawAxis();
// ��������� �������
void drawGraph(const Graph& graph);
// ��������� ������� � ��������� �����
void drawGraphWithLabels(const Graph& graph);
// �������� �������
Graph createGraph();
// ���������� ����� � ������
void addPointToGraph(Graph& graph, int x, int y);
// ���������� ����� � �������
void connectPointsInGraph(Graph& graph);
// ���������� ������� � ����
void saveGraphToFile(const Graph& graph, const std::string& filepath);
// �������� ������� �� �����
void loadGraphFromFile(Graph& graph, const std::string& filepath);