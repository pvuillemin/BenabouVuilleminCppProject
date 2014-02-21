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
	
	Gui gui;//Initialize the gui
	gui.Welcome();//welcome window
	gui.ChooseArmNumber();//choose the number of arm for your bandit
	gui.SetArms();//Choose the parameters and the type of the arms
	gui.SetSimulations();//Set the simultation by indicating how many try you want
	mt19937_64 generator;//Initialization of the PRNG, we use the famous mersenne twister
	Bandit Bandit (gui.GetArmNumber(),gui.GetChoices(),gui.GetParameters());//Initialize the bandit using the information collected by the gui
	Player player;//Initialize the player

	double epsilon(0.5);// parametre de epsilon greedy strategy
	double tau(0.5);//  parametre de boltzmann exploration strategy
	double beta(0.5);// parametre de pursuit strategy
	Player playerUCB;
	Player playerEpsilonGreedy;
	Player playerBoltzmannExploration;
	Player playerPursuit;
	playerUCB.UCBStrategy(&Bandit, gui.GetSimulationNumber(), generator,gui.GetInitNumber());
	playerEpsilonGreedy.EpsilonGreedyStrategy(&Bandit, gui.GetSimulationNumber(), generator,gui.GetEpsilon(),gui.GetInitNumber());
	playerBoltzmannExploration.BoltzmannExplorationStrategy(&Bandit, gui.GetSimulationNumber(), generator,gui.GetTau(),gui.GetInitNumber());
	playerPursuit.PursuitAlgorithmStrategy(&Bandit, gui.GetSimulationNumber(), generator,gui.GetBeta(),gui.GetInitNumber());
	playerUCB.WriteDataInCSV("Data/UCB.csv");
	playerEpsilonGreedy.WriteDataInCSV("Data/EpsilonGreedy.csv");
	playerBoltzmannExploration.WriteDataInCSV("Data/BoltzmannExploration.csv");
	playerPursuit.WriteDataInCSV("Data/PursuitAlgorithm.csv");

	player.PursuitAlgorithmStrategy(&Bandit, gui.GetSimulationNumber(), generator,0.1,gui.GetInitNumber());//play using the parameters collected by the gui


	player.WriteDataInCSV("Data/Data.csv");


	return 0;
	
}