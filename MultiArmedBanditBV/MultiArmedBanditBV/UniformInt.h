#pragma once
#include "Arm.h"
#include <random>
class UniformInt :
	public Arm
{
public:
	UniformInt(int parameter1, int parameter2);
	~UniformInt(void);
	virtual double Generate(std::mt19937_64& generator);
};

