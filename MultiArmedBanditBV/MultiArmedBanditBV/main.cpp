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



int main(int argc, char* args[])
{
	
	Gui gui;
	gui.Welcome();
	gui.ChooseArmNumber();
	gui.SetArms();
	gui.SetSimulations();
	mt19937_64 generator;
	Bandit Bandit (gui.GetArmNumber(),gui.GetChoices(),gui.GetParameters());	
	Player player;


	player.PursuitAlgorithmStrategy(&Bandit, 100, generator,0.1,5);


	player.WriteDataInCSV("Data/Data.csv");

	return 0;
	
}