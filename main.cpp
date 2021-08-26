#include "PCH.h"

using namespace sf;

int main(){

    srand(static_cast<int>(time(nullptr)));

    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); //main window
    mainWindow.setFramerateLimit(60); //60 fps mode
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably

    std::unique_ptr<cBackground> grass;
    std::vector<Sprite> backgroundSpr;

    for (int i = 0; i <= mainWindow.getSize().x; i += 50)
    {
        for (int j = 0; j <= mainWindow.getSize().y; j += 20)
        {
            grass = std::make_unique<cBackground>("graphics/tiles/spr_grass.png", "graphics/tiles/spr_grass_alt.png");
            auto spr = grass->getBgrSprite();
            spr.setPosition(i, j);
            backgroundSpr.push_back(std::move(spr));
        }
    }
 
    //CREATING PLAYER 
    cPlayer player("graphics/Player.png");

    Clock clock;

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape)) { // if "ESC" pressed -> close app
            mainWindow.close();
        }

        player.movePlayer(); //simply move our hero -> more details in "cPlayer.cpp"

        mainWindow.clear(); //all objects  should be drawn after clearing window

        for (const auto& spr : backgroundSpr)
        {
            mainWindow.draw(spr);
        }

        player.drawPlayer(mainWindow); //drawing player

        mainWindow.display();
    }
}

