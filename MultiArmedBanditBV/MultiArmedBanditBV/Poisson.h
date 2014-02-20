#pragma once
#include "Arm.h"
#include <random>
class Poisson:
	public Arm
{
public:
	Poisson(double parameter1);
	~Poisson(void);
	virtual double Generate(std::mt19937_64& generator);
};

