#include "Poisson.h"


#include <random>
#include <vector>
using namespace std;

Poisson::Poisson(double parameter1)
{
	_mean=parameter1;
	_parameter.push_back(parameter1);
}

double Poisson::Generate(mt19937_64& generator)
{
    //mt19937_64 generator ;
    poisson_distribution<double> distribution(_parameter[0]);
    double number  (distribution(generator));
	_timesChosen++;
	_history.push_back(number);
    return number;
}



Poisson::~Poisson(void)
{
}
