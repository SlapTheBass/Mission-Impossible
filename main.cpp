#include "PCH.h"
#include "cPlayer.h"
#include "cBackground.h"
#include "Level.h"

using namespace sf;

int main(){

    srand(static_cast<int>(time(nullptr)));

    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); //main window
    mainWindow.setFramerateLimit(120); 
    mainWindow.setMouseCursorVisible(false);
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably


    //BACKGROUND
    cBackground background;

    //CREATING PLAYER 
    cPlayer player;

    Level level(mainWindow);

    Clock clock;

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape)) { 
            mainWindow.close();
        }

        player.movePlayer(); 

        mainWindow.clear(); //all objects  should be drawn after clearing window

        background.drawBackground(mainWindow);

        level.loadLevel("data/TEST.txt");
        level.drawLevel(mainWindow);
        level.hidePlayer(player);
        level.playerCollision(player);

        player.drawPlayer(mainWindow); //drawing player

        mainWindow.display();
    }
}

