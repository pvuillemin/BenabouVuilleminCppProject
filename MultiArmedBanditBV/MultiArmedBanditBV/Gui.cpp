#include "Gui.h"
#include "TypeZone.h"

Gui::Gui(void):_font(NULL),_font2(NULL),_screen(800,600,32,"Images/background.png")
{	
	//Initialize the libraries
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();

	//Initialization 
	
	_quit=false;
		//The fonts used in the program
	_font = TTF_OpenFont( "Ubuntu-L.ttf", 36 );
	_font2 = TTF_OpenFont( "Ubuntu-L.ttf", 12 );
		//The color
	SDL_Color textColor={0,0,0};
	_textColor= textColor;

		//The numbers
	_numberArms = 0;
	_simulationNumber = 0;
	_initNumber = 0;
	_tau=0.5;
	_beta=0.5;
	_epsilon=0.5;
	

}


Gui::~Gui(void)
{	

	//Delete the fonts used in the program

	TTF_CloseFont(_font);
	TTF_CloseFont(_font2);
	//Close the libraries
	TTF_Quit();
	SDL_Quit();

}

int Gui::GetArmNumber(void)
{
return _numberArms;
}

std::vector<char> Gui::GetChoices()
{
return _choices;
}
std::vector<std::vector<double>> Gui::GetParameters()
{
return _parameters;
}

int Gui::GetInitNumber()
{
return _initNumber;
}

int Gui::GetSimulationNumber()
{
return _simulationNumber;
}

double Gui::GetTau()
{
return _tau;
}

double Gui::GetEpsilon()
{
return _epsilon;
}

double Gui::GetBeta()
{
return _beta;
}


//Welcoming window
void Gui::Welcome(void)
{
	//Define the texts
Texts welcome(0,150,_font,"Multi Armed Bandit",_textColor);
Texts authors(0,350,_font2,"Nathan Benabou & Pierre Vuillemin",_textColor);


	//Define the Button
Buttons enter(361, 500, "Images/enter1.png","Images/enter2.png","Images/enter3.png");
  //Display them centered
welcome.DisplayCentered(_screen);

authors.DisplayCentered(_screen);
//enter.Show(_screen);

//Start getting events
SDL_Event event;

//Initialization of the loop

bool skip = false;
while((_quit==false)&&(skip==false))
	{	//While there's an event to handle
		while( SDL_PollEvent( &event ) )
			{	
				if(enter.HandleEvents(event)==false)
				{
				skip=true;
				}

				
				
				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
					{
					//Quit the program
					_quit = true;
					}
			}
	
	enter.Show(_screen);	
	_screen.Display();
	}
	
_screen.Clean("Images/background.png");

}

void Gui::ChooseArmNumber()
{	
	// Initializing the texts 
	Texts chooseArmNumber(0,100,_font,"Choose the number of arms",_textColor);
	
	//Initializing the Buttons

	Buttons ok(361,450, "Images/ok1.png", "Images/ok2.png","Images/ok3.png");
	UpButton up(350, 250, _font2,"Number of arms",_textColor);
	DownButton down(350, 259);

	//Display all of them

	chooseArmNumber.DisplayCentered(_screen);
	
	ok.Show(_screen);
	up.DisplayCentered(_screen,_numberArms,_font2,_textColor);
	down.SetPosition(up.GetBox().x,up.GetBox().y+up.GetBox().h);
	down.Show(_screen);

	//Initialize the event structure
	SDL_Event event;

	//Initialization of the loop
	
	bool skip=false;
	while((skip==false)&&(_quit==false))
	{	//While there's an event to handle
		while( SDL_PollEvent( &event ) )
			{	
				//modify the number of arms
				up.HandleEvents(event,_numberArms);
				down.HandleEvents(event,_numberArms);
				//If it's okay then skip to the following window
				if(ok.HandleEvents(event)==false)
				{
				skip=true;
				}
				
				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
					{
					//Quit the program
					_quit = true;
					}
			}

	up.DisplayCentered(_screen,_numberArms,_font2,_textColor);	
	down.Show(_screen);
	ok.Show(_screen);	
	_screen.Display();
	}
	
_screen.Clean("Images/background.png");

}


void Gui::SetArm(const char* text)
{	
	//Initialize a surface used to hide a part of the screen wich is used later
	SDL_Surface* hide = NULL;
	hide=LoadImage("Images/hide.png");

	//The variables that the window is going to get

	double mean =0;//the mean of the arm
	double variance =0;//its variance
	char armType ='A';//its type

	//Initializing the texts
	Texts arm(0,150,_font,text,_textColor);	
	Texts instructions(0,250,_font2,"Choose a type of arm then click in the boxes and type the parameters",_textColor);
	//Initializing the buttons

	//Ok button to skip to the next window
	Buttons ok(361,500, "Images/ok1.png", "Images/ok2.png","Images/ok3.png");

	//Type zones for the mean and the variance
	TypeZone meanT(300,400,_font2,"Mean",_textColor);	
	TypeZone varianceT(600,400,_font2,"Variance",_textColor);
	

	//Radiobuttons to choose the type of arm (exponential, uniform real, uniform int, poisson, logNormal)
	RadioButtons exp(100,300,"Exponential",_font2,_textColor);
	RadioButtons unifr(exp.GetBox().x+exp.GetBox().w+20,300,"Uniform real",_font2,_textColor);
	RadioButtons unifi(unifr.GetBox().x+unifr.GetBox().w+20,300,"Uniform int",_font2,_textColor);
	RadioButtons poisson(unifi.GetBox().x+unifi.GetBox().w+20,300,"Poisson",_font2,_textColor);
	RadioButtons logNormal(poisson.GetBox().x+poisson.GetBox().w+20,300,"Log-normal",_font2,_textColor);

	//Calculate the x for centering them (width of the screen minus the sum the width of the buttons)

	int xCentered = ((*(_screen.GetScreen())).clip_rect.w-exp.GetBox().w-unifr.GetBox().w-unifi.GetBox().w-poisson.GetBox().w-logNormal.GetBox().w-80)/2;

	//Relocate the buttons

	exp.SetPosition(xCentered,exp.GetBox().y);
	unifr.SetPosition(exp.GetBox().x+exp.GetBox().w+20,unifr.GetBox().y);
	unifi.SetPosition(unifr.GetBox().x+unifr.GetBox().w+20,unifi.GetBox().y);
	poisson.SetPosition(unifi.GetBox().x+unifi.GetBox().w+20,poisson.GetBox().y);
	logNormal.SetPosition(poisson.GetBox().x+poisson.GetBox().w+20,logNormal.GetBox().y);

	//Display them all

	arm.DisplayCentered(_screen);
	instructions.DisplayCentered(_screen);
	//meanT.Display(_screen);

	
	
	ok.Show(_screen);
	exp.Show(_screen);
	unifr.Show(_screen);
	unifi.Show(_screen);
	poisson.Show(_screen);
	logNormal.Show(_screen);

	
	meanT.DisplayLeft(_screen,mean,_font2,_textColor);
	varianceT.DisplayRight(_screen,mean,_font2,_textColor);
	
	
	
		//Initialize the event structure
	SDL_Event event;

	//Initialization of the loop
	bool isChoiceCorrect= false;
	bool skip=false;
	while((skip==false)&&(_quit==false))
	{	//While there's an event to handle
		while( SDL_PollEvent( &event ) )
			{	
				//the buttons react to the user's actions 
				ok.HandleEvents(event);
				exp.HandleEvents(event);
				unifr.HandleEvents(event);
				unifi.HandleEvents(event);
				poisson.HandleEvents(event);
				logNormal.HandleEvents(event);

				meanT.HandleEvents(event,mean);
				
				
				//For some button we just need the mean to set the distribution so in this case we hide the variance
				if((exp.IsActive()==false)&&(poisson.IsActive()==false))
				{				
				varianceT.HandleEvents(event,variance);
				
				}
				//we check if one option was chosen
				isChoiceCorrect = (exp.IsActive()|| unifr.IsActive()||unifi.IsActive()||poisson.IsActive()||logNormal.IsActive());

				//If the user clicks on ok and made a choice 
				if((ok.HandleEvents(event)==false)&&(isChoiceCorrect))
				{
					//skip to the next window
				skip=true;
				}

				//If he clicks on ok and hasn't made a choice then change color of the text
				if((ok.HandleEvents(event)==false)&&(isChoiceCorrect==false))
				{
					SDL_Color red={240,0,0};
					exp.SetColor(red);
					unifr.SetColor(red);
					unifi.SetColor(red);
					poisson.SetColor(red);
					logNormal.SetColor(red);
				}
				
				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
					{
					//Quit the program
					_quit = true;
					}
			}

	    //Display all
	    ok.Show(_screen);
		exp.Show(_screen);
		unifr.Show(_screen);
		unifi.Show(_screen);
		poisson.Show(_screen);
		logNormal.Show(_screen);
	
		meanT.DisplayLeft(_screen,mean, _font2,_textColor);
		
		
		//For some button we just need the mean to set the distribution so in this case we hide the variance
		if((exp.IsActive()==false)&&(poisson.IsActive()==false))
			{
			 varianceT.DisplayRight(_screen,variance, _font2,_textColor);	
			 
			}
		else
			{
			 ApplySurface(400,398,hide,_screen.GetScreen());
			}

		_screen.Display();
	}
	
	_screen.Clean("Images/background.png");

	//Then we save the parameters in the Gui's attributes

	//First we get the type of arm:
	if(exp.IsActive()){armType='A';}
	if(unifr.IsActive()){armType='B';}
	if(unifi.IsActive()){armType='C';}
	if(poisson.IsActive()){armType='D';}
	if(logNormal.IsActive()){armType='E';}

	std::vector<double> parameter;
	
	//Then acoording to the type of arms we calculate the parameters required
	switch(armType)
		{
		case 'A'://Exponential: we need the lambda

			_choices.push_back('A');//we save the type in _choices 

			
			parameter.push_back(1.0/(mean*1.0));
			_parameters.push_back(parameter);//and the parameters calculated using the mean and the variance in _parameters

			break;
		case 'B'://uniform real on [a,b]  we need a and b

			_choices.push_back('B');

			
			parameter.push_back((2.0*mean-sqrt(12.0*variance))/2.0);
			parameter.push_back((2.0*mean+sqrt(12.0*variance))/2.0);
			_parameters.push_back(parameter);
			break;


		case 'C':

			_choices.push_back('C');//uniform integer on [a,b] we need a and b

			
			parameter.push_back((2.0*mean -sqrt(12.0*variance+1.0)+1)/2.0);
			parameter.push_back((2.0*mean+sqrt(12.0*variance+1)-1)/2.0);
			_parameters.push_back(parameter);
			break;


		case 'D': //poisson we just need the mu wich equal to the mean

			_choices.push_back('D');

			
			parameter.push_back(mean);
			_parameters.push_back(parameter);
			break;

		default:

			_choices.push_back('E'); //log-normal we need mu and sigma square

			
			parameter.push_back(log(mean*1.0)-0.5*log(1.0+((variance*1.0)/(mean*mean*1.0))));
			parameter.push_back((2.0*mean+sqrt(12.0*variance+1.0)-1.0)/2.0);
			_parameters.push_back(parameter);
			break;		

		}


}

void Gui::SetArms()
{


for(int i = 1 ; i< _numberArms+1 ; i++)
	{
	std::stringstream strm;
    strm << i;
	char str[7];
	strcpy(str,"Arm");
	strcat(str,strm.str().c_str());
	Gui::SetArm(str);
	}
}

void Gui::SetSimulations()
{
	//Create the texts
	Texts set(0,150,_font,"Set the simulation",_textColor);
	Texts instructions(0,250,_font2,"Click in the boxes and type the parameters",_textColor);

	//Create The TypeZone

	TypeZone simNumber(0,350,_font2,"Number of simulation",_textColor);
	TypeZone initNumber(0,400,_font2,"Number of initialization",_textColor);
	TypeZone beta(0,450,_font2,"Beta",_textColor);
	TypeZone tau(0,480,_font2,"Tau",_textColor);
	TypeZone epsilon(0,510,_font2,"Epsilon",_textColor);


	//Create the button

	Buttons generateData(361,570,"Images/data1.png","Images/data2.png","Images/data3.png");


	//Display them all
	set.DisplayCentered(_screen);
	instructions.DisplayCentered(_screen);
	generateData.Show(_screen);
	simNumber.DisplayCentered(_screen,_simulationNumber,_font2,_textColor);
	initNumber.DisplayCentered(_screen,_initNumber,_font2,_textColor);
	beta.DisplayCentered(_screen,_beta,_font2,_textColor);
	tau.DisplayCentered(_screen,_tau,_font2,_textColor);
	epsilon.DisplayCentered(_screen,_epsilon,_font2,_textColor);

	//Initialize the event structure
	SDL_Event event;

	//Initialization of the loop
	
	bool skip=false;
	while((skip==false)&&(_quit==false))
	{	//While there's an event to handle
		while( SDL_PollEvent( &event ) )
			{	
				//modify the number of arms
				simNumber.HandleEvents(event,_simulationNumber);
				initNumber.HandleEvents(event,_initNumber);
				beta.HandleEvents(event,_beta);
				tau.HandleEvents(event,_tau);
				epsilon.HandleEvents(event,_epsilon);
				//If it's okay then skip to the following window
				if(generateData.HandleEvents(event)==false)
				{
				skip=true;
				}
				
				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
					{
					//Quit the program
					_quit = true;
					}
			}

	simNumber.DisplayCentered(_screen,_simulationNumber,_font2,_textColor);	
	initNumber.DisplayCentered(_screen,_initNumber,_font2,_textColor);
	beta.DisplayCentered(_screen,_beta,_font2,_textColor);
	tau.DisplayCentered(_screen,_tau,_font2,_textColor);
	epsilon.DisplayCentered(_screen,_epsilon,_font2,_textColor);
	generateData.Show(_screen);	
	_screen.Display();
	}
	
_screen.Clean("Images/background.png");
}

/*void Gui::SetMode()
{
	//Define the texts
Texts setMode(0,150,_font,"Mode",_textColor);
Texts instructions(0,250,_font2,"Play or use implemented strategies",_textColor);


	//Define the Button
Buttons enter(361, 500, "Images/enter1.png","Images/enter2.png","Images/enter3.png");



//Radiobuttons to choose the type of arm (exponential, uniform real, uniform int, poisson, logNormal)
	RadioButtons solo(100,300,"Solo",_font2,_textColor);
	RadioButtons strat(solo.GetBox().x+solo.GetBox().w+20,300,"Implemented strategies",_font2,_textColor);
	

	//Calculate the x for centering them (width of the screen minus the sum the width of the buttons)

	int xCentered = ((*(_screen.GetScreen())).clip_rect.w-solo.GetBox().w-20)/2;

	//Relocate the buttons

	solo.SetPosition(xCentered,solo.GetBox().y);
	strat.SetPosition(solo.GetBox().x+solo.GetBox().w+20,strat.GetBox().y);
	

	//Display them all
	
	
	
	solo.Show(_screen);
	strat.Show(_screen);	

  //Display them centered
	setMode.DisplayCentered(_screen);
	instructions.DisplayCentered(_screen);
	enter.Show(_screen);

//Start getting events
SDL_Event event;

//Initialization of the loop

bool skip = false;
while((_quit==false)&&(skip==false))
	{	//While there's an event to handle
		while( SDL_PollEvent( &event ) )
			{	


				if(enter.HandleEvents(event)==false)
				{
				skip=true;
				}

				
				
				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
					{
					//Quit the program
					_quit = true;
					}
			}
	
	enter.Show(_screen);	
	_screen.Display();
	}
	
_screen.Clean("Images/background.png");

}*/







