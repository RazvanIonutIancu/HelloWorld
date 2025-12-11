#pragma once
#include "RigidBody.h"
#include "Constants.h"




class Ship : public RigidBody
{
public:

	double thrust = 100;
	std::string spriteID = "ship";
	double scale = 1;


	Ship();
	//~Ship();






	void Draw() override;

	void SimulatePhysics(double timeStep) override;

	bool IsColliding(RigidBody* theAsteroid) override;
};