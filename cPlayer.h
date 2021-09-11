#pragma once
/*Player class is used for animate player, load different textures depending on state and event handling*/
#include "PCH.h"
#include "Entity.h"

class cPlayer : public Entity
{
public:
	/*default constructor*/
	cPlayer();

	/*draws player on game window*/
	void Draw(sf::RenderWindow&);

	/*checks if player is hiding in bushes and returns sprite with specific texture*/
	sf::Sprite isHidden();

	/*sets hide parameter - TRUE or FALSE*/
	void Hide(bool);

	/*checks if player is visible for agents*/
	bool isVisible();

	/*moves player and aim*/
	void movePlayer();


private:
	sf::Texture pTexture;
	sf::Sprite aim;
	sf::Texture aim_tex;
	float max_speed = 8.f;
	bool slow;
	bool hide;
};

