#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <string>

class Graph {
public:
    void addPoint(int x, int y);
    void clearPoints();
    const std::vector<std::pair<int, int>>& getPoints() const;
    void loadFromFile(const std::string& filepath);
    void saveToFile(const std::string& filepath) const;

private:
    std::vector<std::pair<int, int>> points;
};

#endif // GRAPH_H
