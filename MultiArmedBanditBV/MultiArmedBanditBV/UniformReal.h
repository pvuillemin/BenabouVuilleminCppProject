#pragma once
#include "Arm.h"
class UniformReal :
	public Arm
{
public:
	UniformReal(double parameter1, double parameter2);
	~UniformReal(void);
	virtual double Generate(std::mt19937_64& generator);

private:

};

