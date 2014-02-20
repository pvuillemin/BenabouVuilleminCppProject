#pragma once
#include "Arm.h"
#include <random>
class LogNormal :
	public Arm
{
public:
	LogNormal(double parameter1, double parameter2);//moyenne variance
	virtual double Generate(std::mt19937_64& generator);
	~LogNormal(void);
};

