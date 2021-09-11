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

	/*if true - increases object speed for a short time, after this time object will stop and slowly speed up*/
	void Slip();

	/*sets the speed of object
	  @speedVal param is the new speed value described by float type
	*/
	void setSpeed(float speedVal);

	/* takes the character and velocity as an input and checks what direction entity should move
	** also sets the specific frame while entity is moving and animates movement
	*/
	void moveDirection(char, float);

	/*Sets slow param as given boolean*/
	void SetSlow(bool m_slow);

	/*Sets slip param as given boolean*/
	void SetSlip(bool m_slip);

protected:
	float m_speed;
	bool slow;
	bool slip;

private:
	int i = 0;
	float interval = 20;
	
};

