#include "Asteroid.h"







Asteroid::Asteroid()
{
	pos.x = 0;
	pos.y = DISPLAY_HEIGHT;

	vel.x = 0.5f + (rand() % 101) * 0.015;
	vel.y = 0.5f + (rand() % 101) * 0.015;

	acc.x = 0;
	acc.y = 0;

	scale = 0.5f + (rand() % 101) * 0.015;
	rotSpeed = 0.5f + (rand() % 101) * 0.015;

}


void Asteroid::Draw()
{
	Play::DrawSpriteRotated(spriteID.c_str(), pos, 0, rotation, scale);
}



void Asteroid::SimulatePhysics(double timeStep)
{
	pos += vel * timeStep;
}