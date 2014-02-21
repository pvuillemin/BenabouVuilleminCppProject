#pragma once
#include "buttons.h"
#include "Texts.h"
class UpButton :
	public Buttons
{// This class is for the button which allow the user to increment a number by clicking on upward arrow.
public:
	UpButton(int x, int y,TTF_Font* font,const char* text, SDL_Color textColor);
	~UpButton(void);
	// Diplaying the button
	void Show(Screens screen, int& a, TTF_Font* font, SDL_Color textColor);
	void DisplayCentered(Screens screen, int& a, TTF_Font* font, SDL_Color textColor);
	void DisplayLeft(Screens screen, int& a, TTF_Font* font, SDL_Color textColor);
	void DisplayRight(Screens screen, int& a, TTF_Font* font, SDL_Color textColor);
	//Getting the events
	void HandleEvents(SDL_Event event, int& a);
private:
	//The box where the number to increment is displayed
	SDL_Surface* _writingBox;
	Texts _text;
};

