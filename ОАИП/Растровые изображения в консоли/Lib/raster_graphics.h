#pragma once

#include "graph.h"

// Отрисовка координатных осей
void drawAxis();
// Отрисовка графика
void drawGraph(const Graph& graph);
// Отрисовка графика с подписями точек
void drawGraphWithLabels(const Graph& graph);
// Создание графика
Graph createGraph();
// Добавление точки в график
void addPointToGraph(Graph& graph, int x, int y);
// Соединение точек в графике
void connectPointsInGraph(Graph& graph);
// Сохранение графика в файл
void saveGraphToFile(const Graph& graph, const std::string& filepath);
// Загрузка графика из файла
void loadGraphFromFile(Graph& graph, const std::string& filepath);