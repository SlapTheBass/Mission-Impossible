#include "PCH.h"

using namespace sf;

int main(){

    srand(static_cast<int>(time(nullptr)));

    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); //main window
    mainWindow.setFramerateLimit(60); //60 fps mode
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably


    //BACKGROUND
    cBackground background;
 
    //CREATING PLAYER 
    cPlayer player;

    Clock clock;

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape)) { // if "ESC" pressed -> close app
            mainWindow.close();
        }

        player.movePlayer(); //simply move our hero -> more details in "cPlayer.cpp"

        mainWindow.clear(); //all objects  should be drawn after clearing window

        background.drawBackground(mainWindow);

        player.drawPlayer(mainWindow); //drawing player

        mainWindow.display();
    }
}

