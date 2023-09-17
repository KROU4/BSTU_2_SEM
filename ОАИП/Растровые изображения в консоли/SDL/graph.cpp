#include "graph.h"
#include <fstream>

void Graph::addPoint(int x, int y) {
    points.push_back(std::make_pair(x, y));
}

void Graph::clearPoints() {
    points.clear();
}

const std::vector<std::pair<int, int>>& Graph::getPoints() const {
    return points;
}

void Graph::loadFromFile(const std::string& filepath) {
    std::ifstream inputFile(filepath);
    if (!inputFile) {
        throw std::runtime_error("Unable to open file for reading.");
    }

    clearPoints();

    int x, y;
    while (inputFile >> x >> y) {
        addPoint(x, y);
    }

    inputFile.close();
}

void Graph::saveToFile(const std::string& filepath) const {
    std::ofstream outputFile(filepath);
    if (!outputFile) {
        throw std::runtime_error("Unable to open file for writing.");
    }

    for (const auto& point : points) {
        outputFile << point.first << " " << point.second << std::endl;
    }

    outputFile.close();
}
