#pragma once
#include "Play.h"


class RigidBody
{

public:

	Play::Point2D pos;
	Play::Vector2D vel;
	Play::Vector2D acc;

	double rotation, radius;

	virtual void Draw() = 0;

	//virtual bool IsColliding();

	virtual void SimulatePhysics(double timeStep) = 0;


};