#include "cPlayer.h"


cPlayer::cPlayer() 
{
	m_speed = 12.2;
	slow = false;
	hide = false;
	m_sprite.setPosition(100,200);
	aim_tex.loadFromFile("graphics/Player/aim.png");
	aim.setTexture(aim_tex);
}

void cPlayer::drawPlayer(sf::RenderWindow& window){
	Slow();
	isHidden();
	window.draw(m_sprite);
	window.draw(aim);
}

void cPlayer::movePlayer() {

	sf::Vector2i mousePos = sf::Mouse::getPosition();
	aim.setPosition((float)mousePos.x, (float)mousePos.y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		moveDirection('u', m_speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		moveDirection('d', m_speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		moveDirection('l', m_speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		moveDirection('r', m_speed);
	} else {
		moveDirection('x', 0);
	}
}

sf::Sprite cPlayer::isHidden()
{
	if (hide == false)
	{
		pTexture.loadFromFile("graphics/Player/Player.png");
		m_sprite.setTexture(pTexture);
	}
	else
	{
		pTexture.loadFromFile("graphics/Player/Player_hidden.png");
		m_sprite.setTexture(pTexture);
		m_speed = 8.3;
	}

	return m_sprite;
}


sf::Vector2f cPlayer::GetPosition()
{
	return m_sprite.getPosition();
}

void cPlayer::Hide(bool test)
{
	hide = test;
}
