#include <iostream>
#include <random>
#include <vector>
#include "Player.h"
#include "Bandit.h"
#include "Arm.h"
#include "Exponential.h"
#include "UniformReal.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Gui.h"


using namespace std;



int main( int argc, char* args[])
{
	mt19937_64 generator;

	Gui gui;
	gui.Welcome();
	gui.ChooseArmNumber();
	gui.SetArms();

    /*Exponential Bras1(3.2);
    cout << Bras1.Generate(generator) << endl;
	cout << Bras1.Generate(generator) << endl;
	cout <<Bras1.GetRealMean() << endl;
    

	UniformReal Bras2(1.1,2.1);
	cout << Bras2.Generate(generator) << endl;
	cout << Bras2.Generate(generator) << endl;
	cout <<Bras2.GetRealMean()<< endl;

	vector <char> choices;
	choices.push_back('A');
	choices.push_back('B');
	vector <vector<double>> parameters;
	vector <double> parameter1 (1,3) ;
	vector <double> parameter2(2);
	parameter2[0]=0;
	parameter2[1]=1;
	parameters.push_back(parameter1);
	parameters.push_back(parameter2);*/

	Bandit Bandit1 (gui.GetArmNumber(),gui.GetChoices(),gui.GetParameters());
	/*cout << parameters[0][0] << endl;
	cout << Bandit1.GenerateArm(1,generator) << endl;*/
	
	Player joueur;
	joueur.ActivateArm(&Bandit1,0,generator);
//joueur.ActivateArm(&Bandit1,1,generator);

/*
cout << Bandit1.GetRealMeanArm(0) << endl;;
cout << Bandit1.GetBestRealMeanArms()[1] << endl;
cout <<Bandit1.GetEmpiricalMeanArm(0) << endl;
*/
vector<vector<double>> A;

//joueur.UCBStrategy(&Bandit1,10, generator);


//joueur.EpsilonGreedyStrategy(&Bandit1, 10, generator,0.75);

//joueur.BoltzmannExplorationStrategy(&Bandit1,10,generator,0.75);
joueur.PursuitAlgorithmStrategy(&Bandit1, 10, generator,0.75);

A=joueur.GetData();
joueur.WriteDataInCSV("Data/Data.csv");

	return 0;
	
}