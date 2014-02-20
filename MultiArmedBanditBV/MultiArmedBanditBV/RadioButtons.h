#pragma once
#include "Buttons.h"
#include "Texts.h"
class RadioButtons :
	public Buttons
		
{//This class is for the radiobuttons, which allows to choose only one arm among the different arms implemented
public:
	//Constructor using the font and its color hence the position of the button and the text associated
	RadioButtons(int x, int y, const char* text, TTF_Font* font, SDL_Color textColor);
	~RadioButtons(void);
	void Show(Screens screen);//Displaying the button	
	void HandleEvents(SDL_Event event);//Capting the actions of the user, and assigning the effects
	bool IsActive(void);//Indicate if the button is active or not
	void SetColor(SDL_Color color);
private:
	bool _active;
	//We use two Buttons one when the button is active and another when it's inactive
	Buttons _activeButton;//when we click on the button
	Buttons _inactiveButton;//When nothing has been done, or when another radio button is active on the same line
	// The text writen next to the button
	Texts _text;
	
	//the color of the text
	SDL_Color _textColor;
	
	
};

