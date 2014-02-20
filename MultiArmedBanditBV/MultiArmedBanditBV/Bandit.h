#pragma once
#include <vector>
#include <random>
#include "Arm.h"

class Bandit//Creates a Bandit
{
public:
	Bandit(int numberArms, std::vector<char> choices, std::vector<std::vector<double>> parameters);// The bandit is defined by his number of arms, the vector of the types of each arm chosen: A: Exponential, B:UniformReal, C:UniformInt, D:Poisson, E:LogNormal, and by the vector of the parameters where each parameter is a vector in the same order as the arms
	double GenerateArm(int n,std::mt19937_64& generator);//Generates a random number from the arm number n, using the generator mt19937_64
	double GetRealMeanArm(int n);//returns the mean of the distribution of the arm number n
	std::vector<double> GetBestRealMeanArms();// returns the number of the arm which has the best distribution mean and the value of that mean
	double GetEmpiricalMeanArm(int n);//returns the empirical mean of the arm number n
	std::vector<double> GetBestEmpiricalMeanArms();// returns the number of the arm which has the best empirical mean and the value of that empirical mean
	int GetTimesChosenArm(int n);//returns the number of the times the arm number n has been chosen
	int GetNumberArms();//returns the number of arms in the bandit
	~Bandit(void);

private:
	std::vector<Arm*> _arms;//vector of pointers on the arms (arm is an abstract class so we cannot create arm objects)
	std::vector<char> _choices;//vector composed by the numbers of the arms chosen is a chronological order
	std::vector<std::vector<double>> _parameters;//vector of the parameters of the arms
	int _numberArms;// number of arms in the bandit

	//friend double Generate();
};

