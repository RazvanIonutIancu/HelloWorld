#include "Ship.h"
#include "Play.h"



Ship::Ship()
{
	pos.x = DISPLAY_WIDTH / 2;
	pos.y = DISPLAY_HEIGHT / 2;
	vel.x = 0;
	vel.y = 0;
	acc.x = 0;
	acc.y = 0;

	radius = 10;
}





void Ship::Draw()
{

	Play::DrawSpriteRotated(spriteID.c_str(), pos, 0, rotation);

}





void Ship::SimulatePhysics(double timeStep)
{
	if (Play::KeyDown(Play::KEY_LEFT))
	{
		rotation += 0.3;
	}
	if (Play::KeyDown(Play::KEY_RIGHT))
	{
		rotation -= 0.3;
	}
	if (Play::KeyDown(Play::KEY_SPACE))
	{
		acc.x += thrust * sin(rotation) * timeStep;
		acc.y -= thrust * cos(rotation) * timeStep;
	}



	pos += vel * timeStep;
	vel += acc * timeStep;
	acc.x = 0;
	acc.y = 0;
}
