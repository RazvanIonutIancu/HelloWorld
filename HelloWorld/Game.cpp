#include "Play.h"
#include "Game.h"
#include "Asteroid.h"
#include "Ship.h"




Ship* ship = nullptr;
Asteroid* asteroid = nullptr;


void StepFrame(float elapsedTime)
{
	static int frame = 0;
	frame++;

	if (!ship)
	{
		ship = new Ship();
	}

	ship->Draw();



}