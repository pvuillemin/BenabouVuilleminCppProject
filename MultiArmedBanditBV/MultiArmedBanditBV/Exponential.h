#pragma once
#include "Arm.h"
#include <random>
class Exponential :
	public Arm
{
public:
	Exponential (double parameter);
	~Exponential(void);
	virtual double Generate(std::mt19937_64& generator);
	

private:
    
};

