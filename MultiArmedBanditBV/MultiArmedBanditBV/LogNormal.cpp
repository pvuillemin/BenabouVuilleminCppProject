#include "LogNormal.h"


#include <random>
#include <vector>
using namespace std;

LogNormal::LogNormal(double parameter1, double parameter2)
{
	_mean=parameter1;
	_parameter.push_back(parameter1);
	_parameter.push_back(parameter2);
	
}

double LogNormal::Generate(mt19937_64& generator)
{
    //mt19937_64 generator;
    lognormal_distribution<double> distribution(_parameter[0],_parameter[1]);
    double number  (distribution(generator));
	_timesChosen++;
	_history.push_back(number);
    return number;
}

LogNormal::~LogNormal(void)
{
}
