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
	//mt19937_64 generator;

	Gui gui;
	gui.Welcome();
	gui.ChooseArmNumber();
	gui.SetArms();
	gui.SetSimulations();

    

	//Bandit Bandit1 (gui.GetArmNumber(),gui.GetChoices(),gui.GetParameters());
	//Player joueur;
	




//joueur.UCBStrategy(&Bandit1,10, generator);
//joueur.EpsilonGreedyStrategy(&Bandit1, 10, generator,0.75);
//joueur.BoltzmannExplorationStrategy(&Bandit1,10,generator,0.75);
//joueur.PursuitAlgorithmStrategy(&Bandit1, 10, generator,0.75);
//joueur.WriteDataInCSV("Data/Data.csv");

	return 0;
	
}