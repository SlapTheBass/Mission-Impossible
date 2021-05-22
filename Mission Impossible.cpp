#include <iostream>
#include <SFML/Graphics.hpp>
#include "cPlayer.h"
#include "cBackground.h"

using namespace sf;

int main(){
    VideoMode vm(1920, 1080); //default resolution

    RenderWindow mainWindow(vm, "Mission Impossible", Style::Fullscreen); //main window
    mainWindow.setFramerateLimit(60); //60 fps mode
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably

    //BACKGROUND as an object
    cBackground background("graphics/Background.png");

    //CREATING PLAYER from texture given between brackets
    cPlayer player("graphics/Player.png");

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape)) { // if "ESC" pressed -> close app
            mainWindow.close();
        }

        player.movePlayer(); //simply move our hero -> more details in "cPlayer.cpp"

        mainWindow.clear(); //all objects  should be drawn after clearing window

        background.drawBackground(mainWindow); //drawing background

        player.drawPlayer(mainWindow); //drawing player

        mainWindow.display();
    }
}

