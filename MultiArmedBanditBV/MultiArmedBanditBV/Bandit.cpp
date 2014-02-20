#include "Bandit.h"
#include <iostream>
#include <random>
#include <vector>
#include "Exponential.h"
#include "UniformReal.h"
#include "UniformInt.h"
#include "Poisson.h"
#include "LogNormal.h"
using namespace std;


Bandit::Bandit(int numberArms, vector<char> choices, vector<vector<double>> parameters)
{
	
	_numberArms= numberArms;
	int n(0);
	for (n=0; n < numberArms; n++)
	{
		switch(choices[n])
		{
		case 'A':
			{
			Exponential* arm (0);
			arm= new Exponential (parameters[n][0]);
			_arms.push_back(arm);
			break;
			}
			

		case 'B':
			{
			UniformReal* arm1 (0);
			arm1= new UniformReal (parameters[n][0],parameters[n][1]);
			_arms.push_back(arm1);
			break;
			}
		case 'C':
			{
			UniformInt* arm1 (0);
			arm1= new UniformInt (parameters[n][0],parameters[n][1]);
			_arms.push_back(arm1);
			break;
			}
		case 'D':
			{
			Poisson* arm1 (0);
			arm1= new Poisson (parameters[n][0]);
			_arms.push_back(arm1);
			break;
			}
		case 'E':
			{
			LogNormal* arm1 (0);
			arm1= new LogNormal (parameters[n][0],parameters[n][1]);
			_arms.push_back(arm1);
			break;
			}
		}
	}
}

double Bandit:: GenerateArm(int n,mt19937_64& generator)
{
	Arm* arm (_arms[n]);
	return arm->Generate(generator);
}

vector<double> Bandit:: GetBestRealMeanArms()
{
	vector<double> A;
	double bestMean (0);
	int n (0);
	int k (0);

for (n=0; n < _numberArms; n++)
	 {
		 if (bestMean<(_arms[n]->GetRealMean()))
		 {
			 k=n;
			 bestMean=_arms[n]->GetRealMean();
		 }
	 } 
double number (0);
number=k;
A.push_back(number);
A.push_back(bestMean);

return A;

}

double Bandit:: GetRealMeanArm(int n)
{
	return _arms[n]->GetRealMean();
}

double Bandit:: GetEmpiricalMeanArm(int n)
{
	return _arms[n]->GetEmpiricalMean();
}

vector<double> Bandit:: GetBestEmpiricalMeanArms()
{
	int k (0);
	int n (0);
	double BestEmpiricalMean (0);
	for (k=0; k < _numberArms; k++)
	{
		if (BestEmpiricalMean < (*this).GetEmpiricalMeanArm(k))
		{
			n=k;
			BestEmpiricalMean=(*this).GetEmpiricalMeanArm(k);
		}
	}
	vector <double> A;
	double number (0);
	number=n;
	A.push_back(number);
	A.push_back(BestEmpiricalMean);
	return A;
}


Bandit::~Bandit(void)
{
}

int Bandit:: GetNumberArms()
{
	return _numberArms;
}

int Bandit:: GetTimesChosenArm(int n)
{
	return _arms[n]->GetTimesChosen();
}
