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

	// Check if the ship has been hit for later deletion
	bool shipHit = false;

	// A vector with pointers (a.k.a. asteroids) that need to be deleted
	// I delete them later so I don't mess with the vector size inside a loop
	std::vector<RigidBody*> ptrToDelete;
	for (int i = 0; i < bodies.size(); i++)
	{
		bodies[i]->SimulatePhysics(elapsedTime);
		bodies[i]->Draw();

		// Checks if asteroids go out of bounds
		if (bodies[i]->pos.x < -200 || bodies[i]->pos.x > DISPLAY_WIDTH + 200 
			|| bodies[i]->pos.y < -200 || bodies[i]->pos.y > DISPLAY_HEIGHT + 200)
		{
			ptrToDelete.push_back(bodies[i]);
		}

		// Compares asteroid positions with the ship position
		if (bodies[i] != ship)
		{
			if (ship->IsColliding(bodies[i]))
			{
				shipHit = true;
			}
		}


	}

	// Deletes anything that went out of bounds
	for (int i = 0; i < ptrToDelete.size(); i++)
	{
		DestroyBody(ptrToDelete[i]);
	}


	// Delete ship if hit
	if (shipHit)
	{
		DestroyBody(ship);
		ship = nullptr;
	}
	
	// Spawn ship if it doesn't exist
	if (!ship) SpawnShip();

	// Spawns new asteroids until a given amouont
	if (bodies.size() < NUM_OF_ASTEROIDS)
	{
		SpawnAsteroid();
	}


} // StepFrame end


// Creates a new ship and adds it to the vector
void SpawnShip()
{
	ship = new Ship();
	bodies.push_back(ship);
}


// Creates a new asteroid and adds it to the vector
void SpawnAsteroid()
{
	RigidBody* asteroid = new Asteroid();
	bodies.push_back(asteroid);
}

// Destroys a given object at the given position in the vector
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



// Deletes everything at the very end
void DestroyObjects()
{
	for (RigidBody* body : bodies) delete body;
	bodies.clear();
}