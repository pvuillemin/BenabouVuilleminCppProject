#pragma once
#include "functions.h"
#include "Screens.h"
class Buttons
{
public:
	Buttons(int x, int y, std::string outImageFile, std::string inImageFile, std::string pushImageFile );
	~Buttons(void);
	//Setters

	void SetActiveImage(SDL_Surface* image);//for the image to be displayed
	void SetPosition(int x, int y);//for the position


	// Diplaying the button
	void Show(Screens screen) const;

	//Getting the events
	bool HandleEvents(SDL_Event event);//the button reacts to the actions, this function will be used in a while loop
	
	//The getters
		//For the images
	SDL_Surface* GetOutImage(void);
	SDL_Surface* GetInImage(void);
	SDL_Surface* GetPushImage(void);
		// The position and dimensions
	SDL_Rect GetBox(void);

protected:
	SDL_Rect _box; //Define the rectangle containing the button

	//Images associated to the button according if the mouse is in or out or if the button is pressed
	SDL_Surface* _outImage ; // button when the mouse is  out
	SDL_Surface* _inImage ; // button when the mouse is  in
	SDL_Surface* _pushImage ; // button when the mouse is  pressed
	SDL_Surface* _activeImage; // button to display
		
};

