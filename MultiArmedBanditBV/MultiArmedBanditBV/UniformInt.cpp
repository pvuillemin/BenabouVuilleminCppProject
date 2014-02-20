#include "UniformInt.h"


#include <random>
#include <vector>
using namespace std;

UniformInt::UniformInt(int parameter1, int parameter2)
{
	_mean=(parameter1+parameter2)/2;
	_parameter.push_back(parameter1);
	_parameter.push_back(parameter2);
}

double UniformInt::Generate(mt19937_64& generator)
{
    //mt19937_64 generator;
    uniform_int_distribution<double> distribution(_parameter[0],_parameter[1]);
    double number  (distribution(generator));
	//double number(0);
	//number=x;
	_timesChosen++;
	_history.push_back(number);
    return number;
}



UniformInt::~UniformInt(void)
{
}
