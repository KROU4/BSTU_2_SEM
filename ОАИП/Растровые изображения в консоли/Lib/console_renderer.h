#pragma once

#include "graph.h"

class ConsoleRenderer {
public:
	void drawAxis(const Graph& graph); // Добавляем здесь параметр graph
	void drawGraph(const Graph& graph);
};