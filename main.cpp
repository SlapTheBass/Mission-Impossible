﻿#include "PCH.h"
#include "cPlayer.h"
#include "cBackground.h"
#include "Level.h"

using namespace sf;

int main(){

    srand(static_cast<int>(time(nullptr)));

    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); //main window
    mainWindow.setFramerateLimit(120); 
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably


    //BACKGROUND
    cBackground background;

    Level level(&mainWindow);
 
    //CREATING PLAYER 
    cPlayer player;

    cBush bush;

    Clock clock;

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape)) { // if "ESC" pressed -> close app
            mainWindow.close();
        }

        player.movePlayer(); //simply move our hero -> more details in "cPlayer.cpp"

        mainWindow.clear(); //all objects  should be drawn after clearing window

        background.drawBackground(mainWindow);

        level.loadLevel("data/levelData.txt");
        level.drawLevel(mainWindow);

        player.drawPlayer(mainWindow); //drawing player

        mainWindow.display();
    }
}

