#pragma once
#include "buttons.h"
class UpButton :
	public Buttons
{// This class is for the button which allow the user to increment a number by clicking on upward arrow.
public:
	UpButton(int x, int y);
	~UpButton(void);
	// Diplaying the button
	void Show(Screens screen, int& a, TTF_Font* font, SDL_Color textColor);

	//Getting the events
	void HandleEvents(SDL_Event event, int& a);
private:
	//The box where the number to increment is displayed
	SDL_Surface* _writingBox;
};

