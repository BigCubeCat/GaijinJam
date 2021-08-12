//
// Created by DerFreimensch on 06.08.2021.
//

#include "../headers/Helper.h"

float charToInt(std::string & line){
    float res = 0;
    float k, l;
    for(int i = 1; i < line.size()+1; i++){
        k=((float)line[line.size()-i]  - 48);
        l=pow(10, i-1);
        res = res + k*l;
    }
    return res;
}

void makeMap(std::string path, int &mapNumber, std::list<Wall> & mainWallList, std::list <Wall> & mapWallList, b2World &world){
    std::ifstream file(path);
    if(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            float mas[4];
            if(line.find("mainwall") == 0){
                makeArr(line, mas);
                Wall newWall(world,mas[0], mas[1], mas[2], mas[3]);
                mainWallList.push_back(newWall);
            }
            if(line.find("firstmap_wall") == 0 && mapNumber == 1){
                    makeArr(line, mas);
                    Wall newWall(world,mas[0], mas[1], mas[2], mas[3]);
                    mapWallList.push_back(newWall);
            }
        }
    }
}

float* makeArr(std::string  line, float *mas){
    int i = 0;
    int ex1=0, ex2=0;
    std::string extra;
    while(ex2 !=-1){
        ex1 = line.find_first_of("123456789", ex2);
        ex2 = line.find(' ', ex1);
        extra = line.substr(ex1, ex2-ex1);
        mas[i] = charToInt(extra);
        i++;
    }
    return mas;
}

float distance(sf::Vector2f a, sf::Vector2f b) {
    float deltaX = a.x - b.x;
    float deltaY = a.y - b.y;
    return (deltaX * deltaX) + (deltaY * deltaY);
}