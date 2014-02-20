#pragma once
#include "Bandit.h"
#include <random>
#include <fstream>
#include <string>
class Player// Creates a player playing on a bandit
{
public:
	Player();
	~Player(void);
	void ActivateArm(Bandit* bandit, int n, std::mt19937_64& generator);//Activates the arm number n on the bandit using the mt19937_64 generator
	std::vector < std::vector<double>> GetData(); //Vector of 3 vectors: 1st vector: cumulated regrets, 2nd vector: number of the arms chosen, 3rd vector: rewards history
	void UCBStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator);// Activating that method on a bandit with a mt19937_64 generator lets the player play following the UCB Strategy for the length wished
	void EpsilonGreedyStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator,double epsilon); //Activating that method on a bandit with a mt19937_64 generator lets the player play following the Epsilon Strategy for the length wished and a chosen value for the parameter epsilon
	void BoltzmannExplorationStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator,double tau);// Activating that method on a bandit with a mt19937_64 generator lets the player play following the Boltzmann Exploration Strategy for the length wished and a chosen value for the parameter tau
	void PursuitAlgorithmStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator,double beta);// Activating that method on a bandit with a mt19937_64 generator lets the player play following the Pursuit Algorithm Strategy for the length wished and a chosen value for the parameter beta
	void WriteDataInCSV(std::string data);//Puts the data obtained by the method GetData on a .csv file already created.The adress of the file must be specified int he function.
private:
	int _numberActions;//The number of times the player has played
	std:: vector<double> _cumulatedRegret;//Cumulated regret history
	Bandit* _bandit;//Pointer on a bandit on which the player can play
	std::vector <double> _armHistory;//Arms number history 
	std::vector <double> _rewardsHistory;//Rewards history
	double _sumRewards;//Sum of the rewards

};

