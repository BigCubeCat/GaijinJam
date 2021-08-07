//
// Created by DerFreimensch on 06.08.2021.
//
#include <string>
#include <cmath>
#include <list>
#include "Wall.h"
#include <fstream>
#pragma once

int charToInt(std::string & line);
void makeMap(std::string & path, std::list<Wall> & mainWallList, std::list <std::list<Wall>> & mapWallList);





