#pragma once
#include "Screens.h"
#include "functions.h"
class Texts
{// Class text for the messages to be displayed in the windows.
public:
	Texts(int x, int y, TTF_Font* font, const char* text, SDL_Color textColor);
	~Texts(void);

	void SetPosition(int x,int y);
	//Function displaying the message
	void Display(Screens screen);
	
	//Getters for the dimesions
	int GetHeight(void);
	int GetWidth(void);
	
	//Center the text and dipslay it
	void DisplayCentered(Screens screen);

	void SetColor(SDL_Color color);
private:
	SDL_Surface* _message;// surfacecontianing the text
	TTF_Font* _font;//font used to display the text
	SDL_Color _textColor; // Color used to dipaly the message 
	const char* _text;//the message to be written
	//the dimensions of the message, useful when we want to display it properly
	SDL_Rect _box;
};

