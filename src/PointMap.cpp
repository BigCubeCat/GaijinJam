#include "../headers/PointMap.h"
#include "../headers/Helper.h"
#include <queue>
#include <iostream>

PointMap::PointMap(const std::string& path) {
    this->points = loadMatrix(path);
    std::cout << this->points[10][10] << "\n";
}

sf::Vector2f PointMap::nearestPoint(sf::Vector2f point){
    int row, col;
    row = (int)point.y / NPS_SIZE;
    col = (int)point.x / NPS_SIZE;
    int newX, newY;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            newX = row+i; newY = col+j;
            std::cout << this->points.size();
            if (newX < 0 || newX >= this->points[0].size() || newY < 0 || newY >= this->points.size()) continue;
            if (this->points[row+i][col+j] == FREE_POINT || this->points[row+i][col+j] == FINISH_POINT) {
                return sf::Vector2f{(float)(col+j) * NPS_SIZE, (float)(row+i) * NPS_SIZE};
            }
        }
    }
    return sf::Vector2f{0, 0};
}

std::queue<sf::Vector2f> PointMap::Search(sf::Vector2i point) {
    std::vector<std::vector<int>> map;
    map.swap(this->points);
    std::queue<sf::Vector2f> answer;
    std::vector<std::pair<sf::Vector2i, sf::Vector2i>> way;
    int width, height;
    height = map[1].size();
    width = map[0].size();
    map[point.y][point.x] = 1; // visited;
    std::vector<std::pair<int, sf::Vector2i>> freePoints;
    freePoints.push_back(std::make_pair(0, point));
    int x, y;
    while (freePoints.size() > 0) {
        for (const auto &parent : freePoints) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    y = point.y + i; x = point.x + j;
                    if (y < 0 || x < 0 || x >= width || y >= height) continue;
                    if (map[y][x] == FREE_POINT) {
                        map[y][x] = NO_POINT;
                        freePoints.emplace_back(std::make_pair(freePoints.size()-1, sf::Vector2i{x, y}));
                    } else if (map[y][x] == FINISH_POINT) {
                        map[y][x] = NO_POINT;
                        auto newPoint = sf::Vector2i{x, y};
                        freePoints.emplace_back(std::make_pair(freePoints.size()-1, newPoint));
                        int index = freePoints.size()-1;
                        while (index > 0) {
                            auto p = freePoints[index];
                            index = p.first;
                            answer.push(sf::Vector2f{(float)p.second.x, (float)p.second.y});
                        }
                    }
                }
            }
        }
    }
    return answer;
}