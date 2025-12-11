#pragma once
#include "RigidBody.h"
#include "Constants.h"




class Asteroid : public RigidBody
{
public:
	double scale;
	double rotSpeed;
	std::string spriteID = "asteroid";

	void Draw() override;

	//~Asteroid();

	Asteroid();

	void SimulatePhysics(double timeStep) override;

};