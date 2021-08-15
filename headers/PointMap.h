//
// Created by bigcubecat on 15.08.2021.
//
#include <SFML/Graphics.hpp>

class PointMap {
private:
    std::vector<std::vector<int>> points;
public:
    PointMap(const std::string&);
    sf::Vector2f nearestPoint(sf::Vector2f);
    std::vector<sf::Vector2f> getWay(sf::Vector2f); // Принимает точку в матрице!!!
    // для поиска ближайшей точки в матрице использовать nearestPoint!
    void Search(sf::Vector2f point, std::vector<sf::Vector2f> &way, std::vector<std::vector<int>> &map);
};