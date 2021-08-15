#include "../headers/PointMap.h"
#include "../headers/Helper.h"

PointMap::PointMap(const std::string& path) {
    this->points = loadMatrix(path);
}

sf::Vector2f PointMap::nearestPoint(sf::Vector2f point){
    int row, col;
    row = point.y / NPS_SIZE;
    col = point.x / NPS_SIZE;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (this->points[row+i][col+j] == FREE_POINT || this->points[row+i][col+j] == FINISH_POINT) {
                return sf::Vector2f{(float)(col+j) * NPS_SIZE, (float)(row+i) * NPS_SIZE};
            }
        }
    }
    return sf::Vector2f{0, 0};
}
std::vector<sf::Vector2f> PointMap::getWay(sf::Vector2f point) {
    std::vector<sf::Vector2f> way;
    std::vector<std::vector<int>> map;
    map.swap(this->points);
    this->Search(point, way, map);
    return way;
}

void PointMap::Search(sf::Vector2f point, std::vector<sf::Vector2f> &way, std::vector<std::vector<int>> &map) {
    way.emplace_back(point);
    map[point.y][point.x] = NO_POINT;
    std::vector<sf::Vector2f> freeNeighbours;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            auto newPoint = sf::Vector2f{point.x+i, point.y+i};
            switch (map[point.y+i][point.x+j]) {
                case FINISH_POINT:
                    way.emplace_back(newPoint);
                    return;
                case FREE_POINT:
                    freeNeighbours.emplace_back(newPoint);
                    break;
            }
        }
    }
    for (const auto &p : freeNeighbours) {
        this->Search(p, way, map);
    }
}