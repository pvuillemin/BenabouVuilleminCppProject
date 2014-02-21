#include "Player.h"
#include<iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
using namespace std;

Player::Player()
{
	_numberActions=0;
	_sumRewards=0;
}

void Player::ActivateArm(Bandit* bandit, int n,mt19937_64& generator)
{
	double x (bandit->GenerateArm(n,generator));
	_armHistory.push_back(n);
	_numberActions++;
	_rewardsHistory.push_back(x);
	_sumRewards+=x;
	int k (0);
	double a ((bandit->GetBestRealMeanArms())[1]);
	_cumulatedRegret.push_back(_numberActions*a-_sumRewards);	
}

void Player::UCBStrategy(Bandit* bandit, int numberActionsWished, mt19937_64& generator,int numberInitialisingActions)
{
	if (numberInitialisingActions>0)
	{
	this->Initialisation(bandit,generator,numberInitialisingActions);
	}

	int q (0);
 for  (q=0;q< numberActionsWished;q++)
	{
		int k (0);
		vector<double> EmpiricalMeans;
		vector <int> TimesChosen;
		for (k=0;k<bandit->GetNumberArms();k++)
		{
		EmpiricalMeans.push_back(bandit->GetEmpiricalMeanArm(k));
		TimesChosen.push_back(bandit->GetTimesChosenArm(k));
		}
		int I (0);
		int m(0);
		for (m=0; m<(bandit->GetNumberArms());m++)
		{
			double p (_numberActions+1);
			if (I < EmpiricalMeans[m]+ sqrt(2*log(p)/TimesChosen[m]))
			{
				I=m;
			}
		}
		this->ActivateArm(bandit, I, generator);
	}
}

vector<vector<double>> Player:: GetData()
{
vector<vector<double>> A ;
A.push_back(_cumulatedRegret);
A.push_back(_armHistory);
A.push_back(_rewardsHistory);

return A;

}

void Player::EpsilonGreedyStrategy(Bandit* bandit, int numberActionsWished,mt19937_64& generator, double epsilon, int numberInitialisingActions)
{
	if (numberInitialisingActions>0)
	{
	this->Initialisation(bandit,generator,numberInitialisingActions);
	}

	int n (0);
	for (n=0; n< numberActionsWished; n++)
	{
		bernoulli_distribution distribution(epsilon);
        bool x  (distribution(generator));
		if (x)
		{
			    uniform_int_distribution<int> distribution(0, (bandit->GetNumberArms()) - 1);
                int k  (distribution(generator));
				this->ActivateArm(bandit,k,generator);
				
		}
		else
		{
			int k ( (bandit->GetBestEmpiricalMeanArms())[0] );
			this->ActivateArm(bandit,k,generator);
		}

		

	}



}

void Player::BoltzmannExplorationStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator,double tau,int numberInitialisingActions)
{
	if (numberInitialisingActions>0)
	{
	this->Initialisation(bandit,generator,numberInitialisingActions);
	}


	int n (0);
	for (n=0; n< numberActionsWished; n++)
	{
		double sumExponentialEmpiricalMeans (0);
		vector <double> P (0);
		int k (0);
		for (k=0; k< bandit->GetNumberArms();k++)
		{
			sumExponentialEmpiricalMeans+=exp(tau*(bandit->GetEmpiricalMeanArm(k)));
			P.push_back(sumExponentialEmpiricalMeans);
		}
		uniform_real_distribution<double> distribution(0, sumExponentialEmpiricalMeans);
		double x  (distribution(generator));
		int q (0);
		if (x<P[0])
		{
			this->ActivateArm(bandit,0,generator);
		}
		else if (x>P[0]) 
		{
			for (q=0;q<(bandit->GetNumberArms())-1;q++)
			{
				if ((P[q]<x)&(x<P[q+1]))
				{
					this->ActivateArm(bandit,q+1,generator);
				}
			}
		}

		
	}
}

void Player::PursuitAlgorithmStrategy(Bandit* bandit, int numberActionsWished,std::mt19937_64& generator,double beta,int numberInitialisingActions)

{
	if (numberInitialisingActions>0)
	{
	this->Initialisation(bandit,generator,numberInitialisingActions);
	}
	
	vector <double> * P (0);
	P=new vector <double> (bandit->GetNumberArms());


	uniform_int_distribution<int> distribution(0, (bandit->GetNumberArms())-1);
	int d (distribution(generator));
	cout << d << endl;
	this->ActivateArm(bandit,d,generator);
	
	int k(0);
	for (k=0;k<bandit->GetNumberArms();k++)
	{
		double r (0);
		r=bandit->GetNumberArms();
		(*P)[k]=(1/r);
	}
	int n(0);
	for (n=0;n<numberActionsWished-1;n++)
	{
		vector <double> * sumProbabilities (0);
		sumProbabilities= new vector<double>;
		double * sumProbability(0);
		sumProbability= new double;
		*sumProbability=0;
		
		int q(0);
		for (q=0;q<(bandit->GetNumberArms());q++)
		{
			//double z (0);
			//z=q;
			if ((bandit->GetBestEmpiricalMeanArms())[0]==q)
			{
				cout <<(*P)[q]<<endl;
				(*P)[q]+=beta*(1-(*P)[q]);
				//cout <<(*P)[q]<<endl;
				(*sumProbability)+=(*P)[q];
				(*sumProbabilities).push_back(*sumProbability);
			}
			else
			{
				cout <<(*P)[q]<<endl;
				(*P)[q]-=beta*(*P)[q];
				//cout <<(*P)[q]<<endl;
				(*sumProbability)+=(*P)[q];
				(*sumProbabilities).push_back(*sumProbability);
			}
		}
		uniform_real_distribution<double> distribution(0,*sumProbability);
		double x  (distribution(generator));
		cout << x << endl;
		cout << *sumProbability << endl;
		int m (0);
		if (x<(*sumProbabilities)[0])
		{
			cout <<1 << endl;
			this->ActivateArm(bandit,0,generator);
		}
		else 
		{
			for (m=0;m<(bandit->GetNumberArms())-1;m++)
			{
				if (((*sumProbabilities)[m]<x)&(x<(*sumProbabilities)[m+1]))
				{
					cout << m << endl;
					this->ActivateArm(bandit,m+1,generator);
				}
			}
		}
	delete sumProbability;
	delete sumProbabilities;
	}
	delete P;

	}


void Player:: WriteDataInCSV(string adresse)
{
	string const nomFichier(adresse);
    ofstream monFlux (nomFichier.c_str());
	monFlux << "Cumulated Regrets ; Chosen Arms ; Rewards" << endl;
	vector<vector<double>> A (this->GetData());
	int (k) (0);
	for (k=0; k<_numberActions; k++)
	{
		
	if (monFlux)
	{
		monFlux << A[0][k] << ";" << A[1][k] << ";"  << A[2][k]<< endl;
	}
	else
	{
		cout << "Erreur" << endl;
	}

}
}

void Player:: Initialisation (Bandit* bandit,std::mt19937_64& generator, int numberInitialisingActions)
{
	int n (0);
	for (n=0;n<bandit->GetNumberArms();n++)
	{
		int k (0);
		for (k=0;k<numberInitialisingActions;k++)
		{
			ActivateArm(bandit,n,generator);
		}
	}
}



Player::~Player(void)
{
}
