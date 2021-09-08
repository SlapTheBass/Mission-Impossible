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

	/*moves player and aim*/
	void movePlayer();

	/*checks if player is throwing rocks*/
	bool isThrowing();

	/*gets sprite of aim*/
	sf::Sprite& getAimSprite();

	/*checks if player can be chased by agents*/
	bool canBeChased();


private:
	sf::Texture pTexture;
	//sf::Sprite pSprite;
	sf::Sprite aim;
	sf::Texture aim_tex;
	int i = 0;
	float interval = 20;
	//float speed = 12.2;
	bool slow;
	bool hide;
};

