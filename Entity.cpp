#include "Entity.h"


sf::Clock clk, m_clock, m_clock2;

Entity::Entity() :
	m_speed(0),
	slow(false),
	slip(false)
{
	m_sprite.setScale(0.78125f, 0.78125f);
}

void Entity::moveDirection(char dir, float velocity) {

	int frameX = 0;
	int width = 64;
	int height = 64;


	if (dir == 'u') {//if direction is 'up'
		m_sprite.move(0, -velocity);
		if (clk.getElapsedTime().asMilliseconds() >= interval) {
			clk.restart();
			if (i == 0) {
				m_sprite.setTextureRect({ 0 , 512, width, height });
				i++;
			}
			else if (i == 1) {
				m_sprite.setTextureRect({ 64, 512, width, height });
				i++;
			}
			else if (i == 2) {
				m_sprite.setTextureRect({ 128, 512, width, height });
				i++;
			}
			else if (i == 3) {
				m_sprite.setTextureRect({ 192, 512, width, height });
				i++;
			}
			else if (i == 4) {
				m_sprite.setTextureRect({ 256, 512, width, height });
				i++;
			}
			else if (i == 5) {
				m_sprite.setTextureRect({ 320, 512, width, height });
				i++;
			}
			else if (i == 6) {
				m_sprite.setTextureRect({ 384, 512, width, height });
				i++;
			}
			else if (i == 7) {
				m_sprite.setTextureRect({ 448, 512, width, height });
				i++;
			}
			else if (i == 8) {
				m_sprite.setTextureRect({ 512, 512, width, height });
				i = 0;
			}
			else {
				i = 0;
			}
		}
	}
	else 	if (dir == 'd') {
		m_sprite.move(0, velocity);
		if (clk.getElapsedTime().asMilliseconds() >= interval) {
			clk.restart();
			if (i == 0) {
				m_sprite.setTextureRect({ 0, 640, width, height });
				i++;
			}
			else if (i == 1) {
				m_sprite.setTextureRect({ 64, 640, width, height });
				i++;
			}
			else if (i == 2) {
				m_sprite.setTextureRect({ 128, 640, width, height });
				i++;
			}
			else if (i == 3) {
				m_sprite.setTextureRect({ 192, 640, width, height });
				i++;
			}
			else if (i == 4) {
				m_sprite.setTextureRect({ 256, 640, width, height });
				i++;
			}
			else if (i == 5) {
				m_sprite.setTextureRect({ 320, 640, width, height });
				i++;
			}
			else if (i == 6) {
				m_sprite.setTextureRect({ 384, 640, width, height });
				i++;
			}
			else if (i == 7) {
				m_sprite.setTextureRect({ 448, 640, width, height });
				i++;
			}
			else if (i == 8) {
				m_sprite.setTextureRect({ 512, 640, width, height });
				i = 0;
			}
			else {
				i = 0;
			}
		}
	}
	else 	if (dir == 'l') {
		m_sprite.move(-velocity, 0);
		if (clk.getElapsedTime().asMilliseconds() >= interval) {
			clk.restart();
			if (i == 0) {
				m_sprite.setTextureRect({ 0, 576, width, height });
				i++;
			}
			else if (i == 1) {
				m_sprite.setTextureRect({ 64, 576, width, height });
				i++;
			}
			else if (i == 2) {
				m_sprite.setTextureRect({ 128, 576, width, height });
				i++;
			}
			else if (i == 3) {
				m_sprite.setTextureRect({ 192, 576, width, height });
				i++;
			}
			else if (i == 4) {
				m_sprite.setTextureRect({ 256, 576, width, height });
				i++;
			}
			else if (i == 5) {
				m_sprite.setTextureRect({ 320, 576, width, height });
				i++;
			}
			else if (i == 6) {
				m_sprite.setTextureRect({ 384, 576, width, height });
				i++;
			}
			else if (i == 7) {
				m_sprite.setTextureRect({ 448, 576, width, height });
				i++;
			}
			else if (i == 8) {
				m_sprite.setTextureRect({ 512, 576 , width, height });
				i = 0;
			}
			else {
				i = 0;
			}
		}
	}
	else 	if (dir == 'r') {
		m_sprite.move(velocity, 0);
		if (clk.getElapsedTime().asMilliseconds() >= interval) {
			clk.restart();
			if (i == 0) {
				m_sprite.setTextureRect({ 0, 704, width, height });
				i++;
			}
			else if (i == 1) {
				m_sprite.setTextureRect({ 64, 704, width, height });
				i++;
			}
			else if (i == 2) {
				m_sprite.setTextureRect({ 128, 704, width, height });
				i++;
			}
			else if (i == 3) {
				m_sprite.setTextureRect({ 192, 704, width, height });
				i++;
			}
			else if (i == 4) {
				m_sprite.setTextureRect({ 256, 704, width, height });
				i++;
			}
			else if (i == 5) {
				m_sprite.setTextureRect({ 320, 704, width, height });
				i++;
			}
			else if (i == 6) {
				m_sprite.setTextureRect({ 384, 704, width, height });
				i++;
			}
			else if (i == 7) {
				m_sprite.setTextureRect({ 448, 704, width, height });
				i++;
			}
			else if (i == 8) {
				m_sprite.setTextureRect({ 512, 704, width, height });
				i = 0;
			}
			else {
				i = 0;
			}
		}
	}
	else {
		m_sprite.setTextureRect({ 0, 448, width, height });
	}
}

void Entity::Slow()
{
	if (slow == true)
	{
		m_speed -= 7;

		if (m_speed <= 0)
		{
			m_speed = 0.5f;
		}
	}
	if (m_speed <= 7.5f && m_clock.getElapsedTime().asMilliseconds() >= 250)
	{
		slow = false;
		m_speed += 0.7;
		m_clock.restart();
	}

}

void Entity::Slip()
{
	if (slip == true)
	{
		m_speed += 10;
		if (m_clock2.getElapsedTime().asMilliseconds() >= 200)
		{
			if (m_speed >= 10.5f)
			{
				m_speed = 0;
			}
			m_clock2.restart();
		}
	}

	if (m_speed <= 7.5f && m_clock.getElapsedTime().asMilliseconds() >= 250)
	{
		slip = false;
		m_speed += 0.7;
		m_clock.restart();
	}

}

void Entity::SetSlip(bool m_slip)
{
	slip = m_slip;
}

void Entity::setSpeed(float spd)
{
	m_speed = spd;
}

void Entity::SetSlow(bool m_slow)
{
	slow = m_slow;
}