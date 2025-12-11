#pragma once
#include "Asteroid.h"





void StepFrame(float elapsedTime);
void DestroyObjects();


void SpawnShip();
void SpawnAsteroid();
void DestroyBody(RigidBody* theAsteroid);