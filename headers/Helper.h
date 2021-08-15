//
// Created by DerFreimensch on 06.08.2021.
//
#include <string>
#include <cmath>
#include <list>
#include "Wall.h"
#include <fstream>
#pragma once

float charToInt(std::string & line);
void makeMap(const std::string& path, int &mapNumber, std::list<Wall> & mainWallList, std::list <Wall> & mapWallList, b2World &world);
float* makeArr(const std::string& line, float *mas);
float distance(sf::Vector2f, sf::Vector2f);

std::vector<std::vector<int>> loadMatrix(const std::string& fileName);


