//
// Created by DerFreimensch on 06.08.2021.
//

#include "../headers/Helper.h"

int charToInt(std::string & line){
    int res = 0;
    for(int i = 0; i < line.size(); i++){
        res = ((int)line[i]  - 48)* pow(10, i);
    }
}

void makeMap(std::string & path, std::list<Wall> & mainWallList, std::list <std::list<Wall>> & mapWallList){

}