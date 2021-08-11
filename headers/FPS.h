//
// Created by DerFreimensch on 11.08.2021.
//

#pragma once
#include <SFML/Graphics.hpp>

class FPS
        {
        public:
            FPS();
            unsigned int getFPS() const;
        private:
            unsigned int mFrame;
            unsigned int mFps;
            sf::Clock mClock;
        public:
            void update();
        };
