#pragma once
#include "functions.h"
#include "RadioButtons.h"
#include "UpButton.h"
#include "DownButton.h"
#include <vector>
#include "math.h"


class Gui
{ //The class Gui is the main class for designing the graphic user interface.
public:
	Gui(void);
	~Gui(void);

	//Getters
	int GetArmNumber();
	std::vector<char> GetChoices();
	std::vector<std::vector<double>> GetParameters();
	int GetSimulationNumber();
	int GetInitNumber();
	double GetTau();
	double GetBeta();
	double GetEpsilon();

	void Welcome(void);// First window welcoming the user
	void ChooseArmNumber();// Get the number of arms
	void SetArm(const char* text);//Set one arm
	void SetArms();//Set the arms
	//void SetMode();//choose the mode
	void SetSimulations();//Set the parametres of the simulation (number of initializing try and then number of try)
	
private:
	//Boolean for closing the program

	bool _quit;

	// The fonts used in the program
	TTF_Font* _font;
	TTF_Font* _font2;

	//The color used in the program

	SDL_Color _textColor;

	//The screen used to display the windows
	Screens _screen;

	// The number of arms
	int _numberArms;

	//The number of try simulated
	double _simulationNumber;

	//The number of try for the initialization
	double _initNumber;

	//Vector containing the differents kinds of arms wich will be chosen by he user
	std::vector<char> _choices;
	std::vector<std::vector<double>> _parameters;

	//parameters for the strategy

	double _epsilon;// parametre de epsilon greedy strategy
	double _tau;//  parametre de boltzmann exploration strategy
	double _beta;// parametre de pursuit strategy


};

