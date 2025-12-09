#pragma once
#include "RigidBody.h"
#include "Constants.h"




class Ship : public RigidBody
{
public:

	double thrust = 0;
	std::string spriteID = "ship";
	double scale = 1;

	Ship();






	void Draw() override;

	void SimulatePhysics(double timeStep) override;


};