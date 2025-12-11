#include "Ship.h"
#include "Play.h"
#include <cmath>



Ship::Ship()
{
	pos.x = DISPLAY_WIDTH / 2;
	pos.y = DISPLAY_HEIGHT / 2;
	vel.x = 0;
	vel.y = 0;
	acc.x = 0;
	acc.y = 0;

	radius = SHIP_RADIUS * scale;
	rotation = 0;
}





void Ship::Draw()
{

	Play::DrawSpriteRotated(spriteID.c_str(), pos, 0, rotation, scale);
	//Play::DrawCircle(pos, radius, Play::cGreen);

}





void Ship::SimulatePhysics(double timeStep)
{
	if (Play::KeyDown(Play::KEY_LEFT))
	{
		rotation += 0.1;
	}
	if (Play::KeyDown(Play::KEY_RIGHT))
	{
		rotation -= 0.1;
	}
	if (Play::KeyDown(Play::KEY_SPACE))
	{
		acc.x -= thrust * sin(rotation);
		acc.y += thrust * cos(rotation);
	}



	pos += vel * timeStep;

	if (pos.x > DISPLAY_WIDTH) pos.x = 0;
	if (pos.x < 0) pos.x = DISPLAY_WIDTH;
	if (pos.y > DISPLAY_HEIGHT) pos.y = 0;
	if (pos.y < 0) pos.y = DISPLAY_HEIGHT;


	vel += acc * timeStep;
	acc.x = 0;
	acc.y = 0;
} // SimulatePhysics



bool Ship::IsColliding(RigidBody* theAsteroid)
{
	double dx = this->pos.x - theAsteroid->pos.x;
	double dy = this->pos.y - theAsteroid->pos.y;

	double minDist = this->radius + theAsteroid->radius;

	return dx * dx + dy * dy < minDist * minDist;
}