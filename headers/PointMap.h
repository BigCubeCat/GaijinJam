//
// Created by bigcubecat on 15.08.2021.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

class PointMap {
public:
    std::vector<std::vector<int>> points;
    PointMap(const std::string&);
    sf::Vector2f nearestPoint(sf::Vector2f);
    // для поиска ближайшей точки в матрице использовать nearestPoint!
    std::queue<sf::Vector2f> Search(sf::Vector2i point);
};