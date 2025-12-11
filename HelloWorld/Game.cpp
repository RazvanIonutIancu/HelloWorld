#include "Play.h"
#include "Game.h"
#include "Asteroid.h"
#include "Ship.h"




RigidBody* ship = nullptr;
std::vector<RigidBody*> bodies;

void StepFrame(float elapsedTime)
{
	/*static int frame = 0;
	frame++;*/
	bool shipHit = false;
	std::vector<RigidBody*> ptrToDelete;
	for (int i = 0; i < bodies.size(); i++)
	{
		bodies[i]->SimulatePhysics(elapsedTime);
		bodies[i]->Draw();

		if (bodies[i]->pos.x < -200 || bodies[i]->pos.x > DISPLAY_WIDTH + 200 
			|| bodies[i]->pos.y < -200 || bodies[i]->pos.y > DISPLAY_HEIGHT + 200)
		{
			ptrToDelete.push_back(bodies[i]);
		}

		if (bodies[i] != ship)
		{
			if (ship->IsColliding(bodies[i]))
			{
				shipHit = true;
			}
		}


	}

	for (int i = 0; i < ptrToDelete.size(); i++)
	{
		DestroyBody(ptrToDelete[i]);
	}

	if (shipHit)
	{
		DestroyBody(ship);
		ship = nullptr;
	}
		
	if (!ship) SpawnShip();

	if (bodies.size() < 100)
	{
		SpawnAsteroid();
	}


} // StepFrame end



void SpawnShip()
{
	ship = new Ship();
	bodies.push_back(ship);
}

void SpawnAsteroid()
{
	RigidBody* asteroid = new Asteroid();
	bodies.push_back(asteroid);
}

void DestroyBody(RigidBody* theBody)
{
	for (int i = 0; i < bodies.size(); i++)
	{
		if (bodies[i] == theBody)
		{
			bodies.erase(bodies.begin() + i);
			delete theBody;
			break;
		}
	}
}









void DestroyObjects()
{
	for (RigidBody* body : bodies) delete body;
	bodies.clear();
}