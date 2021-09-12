#include "GameEngine.h"

using namespace sf;

int main()
{
    //RANDOM SEED
    srand(static_cast<int>(time(nullptr)));

    //MAIN WINDOW
    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); 

    //GAME LOOP
    GameEngine game(mainWindow);
    game.Initialize();
    game.Run(mainWindow);
}

