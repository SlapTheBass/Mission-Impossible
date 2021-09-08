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
	void drawPlayer(sf::RenderWindow&);

	/* takes the character and velocity as an input and checks what direction player should move
	** also sets the specific frame while player is moving and animates movement
	*/
	//void moveDirection(char, float);

	/*sets player speed*/
	//void setSpeed(float);

	/*checks if player is hiding in bushes and returns sprite with specific texture*/
	sf::Sprite isHidden();

	/*sets hide parameter - TRUE or FALSE*/
	void Hide(bool);

	/*gets player sprite position and returns it as Vector2f*/
	sf::Vector2f GetPosition();

	/*sets player position by values of given Vector2f*/
	//void SetPosition(sf::Vector2f);

	/*decreases player speed for a short time, after this time speed will slowly increase*/
	//void Slow();

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

