#pragma once
/*base class for agents and player*/
#include "cObject.h"

class Entity : public cObject
{
public:
	/*default constructor*/
	Entity();

	/*if true - decreases object speed for a short time, after this time speed will slowly increase*/
	void Slow();

	/*sets the speed of object
	  @speedVal param is the new speed value described by float type
	*/
	void setSpeed(float speedVal);

	/* takes the character and velocity as an input and checks what direction entity should move
	** also sets the specific frame while entity is moving and animates movement
	*/
	void moveDirection(char, float);

protected:
	float m_speed;

private:
	int i = 0;
	float interval = 20;
	
};

