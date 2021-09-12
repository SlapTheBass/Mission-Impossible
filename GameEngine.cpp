#include "GameEngine.h"

GameEngine::GameEngine(sf::RenderWindow& window) 
{
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(120);

    level = std::make_unique<Level>(window);

	music.openFromFile("sound/main.wav");
	music.setLoop(true);
	music.setVolume(3.f);
	music.play();
}

void GameEngine::Initialize()
{
	level->loadLevel("data/demo0.txt");
	level->Populate();

	agent1.SetPosition({ 1700, 510 });
	agent2.SetPosition({ 1800, 950 });
	agent3.SetPosition({ 250, 750 });
	agent4.SetPosition({ 1200, 510 });
	agent5.SetPosition({ 980, 170 });
}

void GameEngine::Run(sf::RenderWindow& window)
{
    while (window.isOpen()) {


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || level->GameOver())
        {
            window.close();
            break;
        }

        MoveObjects();


        window.clear(); //all objects  should be drawn after clearing window

        Update();

        Draw(window);


        window.display();
    }

}

void GameEngine::Update()
{
    level->UpdateItems(player);
    level->hidePlayer(player);
    level->playerCollision(player);
    agent1.Seek(*level, player);
    agent2.Seek(*level, player);
    agent3.Seek(*level, player);
    agent4.Seek(*level, player);
    agent5.Seek(*level, player);
}


void GameEngine::MoveObjects()
{
    player.movePlayer();
    agent1.moveAgent();
    agent2.moveAgent();
    agent3.moveAgent();
    agent4.moveAgent();
    agent5.moveAgent();


    if (timer.getElapsedTime().asSeconds() >= 5)
    {
        level->SpawnItem(static_cast<ITEM>(rand() % 2), level->RandomSpawnLocation());
        timer.restart();
    }

}

void GameEngine::Draw(sf::RenderWindow& window)
{
    background.drawBackground(window);
    level->drawLevel(window);

    player.Draw(window);
    agent1.Draw(window);
    agent2.Draw(window);
    agent3.Draw(window);
    agent4.Draw(window);
    agent5.Draw(window);
}