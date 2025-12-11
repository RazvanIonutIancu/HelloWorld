#include "Asteroid.h"







Asteroid::Asteroid()
{

	int side = rand() % 4;

	if (side == 0)
	{
		pos.x = (rand() % 101) - 100;
		pos.y = -100 + rand() % (DISPLAY_HEIGHT + 100);
	}
	else if (side == 1)
	{
		pos.x = (rand() % 101) + DISPLAY_WIDTH;
		pos.y = -100 + rand() % (DISPLAY_HEIGHT + 100);
	}
	else if (side == 2)
	{
		pos.y = (rand() % 101) - 100;
		pos.x = -100 + rand() % (DISPLAY_WIDTH + 100);
	}
	else
	{
		pos.y = (rand() % 101) + DISPLAY_HEIGHT;
		pos.x = -100 + rand() % (DISPLAY_WIDTH + 100);
	}

	//pos.y = DISPLAY_HEIGHT / 2;
	//pos.x = DISPLAY_WIDTH / 2;







	// Making sure the asteroid is not just standing there
	do
	{
		vel.x = 20 + (rand() % 201) - 100;
		vel.y = (rand() % 201) - 100;

	} while (vel.x < 5 && vel.x > -5 &&
		vel.y < 5 && vel.y > -5);


	acc.x = 0;
	acc.y = 0;

	scale = 0.5f + (rand() % 101) * 0.02;
	radius = ASTEROID_RADIUS * scale;

	rotSpeed = ((rand() % 201) - 100) * 0.0005;
	rotation = rand() % 101;

}


void Asteroid::Draw()
{
	Play::DrawSpriteRotated(spriteID.c_str(), pos, 0, rotation, scale);
	//Play::DrawCircle(pos, radius, Play::cRed);
}



void Asteroid::SimulatePhysics(double timeStep)
{

	rotation += rotSpeed;
	pos += vel * timeStep;

}