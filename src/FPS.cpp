//
// Created by DerFreimensch on 11.08.2021.
//
#include <SFML/Graphics.hpp>
#include "../headers/FPS.h"
FPS::FPS() : mFrame(0), mFps(0) {}
unsigned int FPS::getFPS() const { return mFps; }
void FPS::update()
            {
                if(mClock.getElapsedTime().asSeconds() >= 1.f)
                {
                    mFps = mFrame;
                    mFrame = 0;
                    mClock.restart();
                }

                ++mFrame;
            }
