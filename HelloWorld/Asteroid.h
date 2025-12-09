#pragma once
#include "RigidBody.h"
#include "Constants.h"




class Asteroid : public RigidBody
{

	double scale;
	double rotSpeed;
	std::string spriteID = "asteroid";

	void Draw() override;

	Asteroid();

	void SimulatePhysics(double timeStep) override;

};