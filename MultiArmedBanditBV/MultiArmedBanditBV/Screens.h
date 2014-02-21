#pragma once
#include "functions.h"
class Screens
{
public:
	Screens(int screenWidth, int screenHeight, int screenBPP, std::string fileName);
	~Screens(void);
	void Display(); // Displaying the Screen
	SDL_Surface* GetScreen(void); //a getter because the screen will be used for displaynig things
	void Screens::Clean(std::string fileName); //cleaning the screen repainting it with the background (erasing all the blitted objects)
private:
	// The dimensions
	int _screenWidth;
	int _screenHeight;
	int _screenBPP;

	//Name of the wallpaper
	std::string _fileName;

	//Corresponding SDL_Surface* 
	SDL_Surface* _screen;
	
};

