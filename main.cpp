#include "PCH.h"
#include "cPlayer.h"
#include "Entity.h"
#include "cBackground.h"
#include "Level.h"
#include "Agent.h"
#include "Command.h"

using namespace sf;

int main(){

    Clock timer;

    //RANDOM SEED
    srand(static_cast<int>(time(nullptr)));

    //MAIN WINDOW
    RenderWindow mainWindow(VideoMode::getDesktopMode(), "Mission Impossible", Style::Fullscreen); 
    mainWindow.setFramerateLimit(120); 
    mainWindow.setMouseCursorVisible(false);
    mainWindow.setKeyRepeatEnabled(true);  // holding a key means pressing it repeatably

    //MUSIC
    Music music;
    music.setLoop(true);
    music.setVolume(3.f);
    if (!music.openFromFile("sound/main.wav"))
    {
        return -1;
    }
    music.play();

    //LEVEL
    Level level(mainWindow);
    level.loadLevel("data/demo0.txt");
    level.Populate();

    //BACKGROUND
    cBackground background;

    //ENEMIES
    Agent agent1, agent2, agent3, agent4, agent5;
    agent1.SetPosition({ 1700, 510 });
    agent2.SetPosition({ 1800, 950 });
    agent3.SetPosition({ 250, 750 });
    agent4.SetPosition({ 1200, 510 });
    agent5.SetPosition({ 980, 170 });

    //PLAYER
    cPlayer player;

    //MAIN LOOP
    while (mainWindow.isOpen()) {


        if (Keyboard::isKeyPressed(Keyboard::Escape) || level.GameOver())
        {
            mainWindow.close();
            break;
        }

        player.movePlayer();
        agent1.moveAgent();
        agent2.moveAgent();
        agent3.moveAgent();
        agent4.moveAgent();
        agent5.moveAgent();
        

        if (timer.getElapsedTime().asSeconds() >= 5)
        {
            level.SpawnItem(static_cast<ITEM>(rand() % 2), level.RandomSpawnLocation());
            timer.restart();
        }

        mainWindow.clear(); //all objects  should be drawn after clearing window

        background.drawBackground(mainWindow);
        level.drawLevel(mainWindow);

        level.UpdateItems(player);
        level.hidePlayer(player);
        level.playerCollision(player);
        agent1.Seek(level, player);
        agent2.Seek(level, player);
        agent3.Seek(level, player);
        agent4.Seek(level, player);
        agent5.Seek(level, player);

     
        player.Draw(mainWindow); 
        agent1.Draw(mainWindow);
        agent2.Draw(mainWindow);
        agent3.Draw(mainWindow);
        agent4.Draw(mainWindow);
        agent5.Draw(mainWindow);


        mainWindow.display();
    }
}

