#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Animation {
private:
    float spendedTime = 0;
    pair<int, float> getFrame();
public:
    string currentAnimation;
    int currentTexture = 0;
    map<string, vector<pair<int, float>>> frames;
    void Tick(float);
    int GetTexture();
};
