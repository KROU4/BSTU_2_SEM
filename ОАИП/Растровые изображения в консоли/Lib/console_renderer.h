#pragma once

#include "graph.h"

class ConsoleRenderer {
public:
	void drawAxis(const Graph& graph); // ��������� ����� �������� graph
	void drawGraph(const Graph& graph);
};