#include "Screens.h"


Screens::Screens(int screenWidth, int screenHeight, int screenBPP, std::string fileName): _screen(NULL)
{

	//assignment of the attributes
	_screenWidth = screenWidth ;
	_screenHeight = screenHeight ;
	_screenBPP = screenBPP;
	_fileName = fileName;
	
	//initialization of the screen
	SDL_Surface* screenBackground =NULL;
	_screen = SDL_SetVideoMode( _screenWidth, _screenHeight, _screenBPP, SDL_SWSURFACE );// we set the window
	SDL_WM_SetCaption( "Multi Armed Bandit", NULL );//we name the window
	screenBackground = LoadImage(fileName);// We load the wallpaper
	ApplySurface(0,0,screenBackground,_screen);//we blit the wallpaper to the window
	SDL_FreeSurface(screenBackground);

}


Screens::~Screens(void)
{
	
}

void Screens::Display(void)
{
// Refresh and display the screen

SDL_Flip( _screen );
}

SDL_Surface* Screens::GetScreen(void)
{
//Give access to the screen for displaying things on it
return _screen ;
}

void Screens::Clean(std::string fileName)
{	SDL_Surface* screenBackground =NULL;
	screenBackground = LoadImage(fileName);// We load the wallpaper
	ApplySurface(0,0,screenBackground,_screen);//we blit the wallpaper to the window
	SDL_FreeSurface(screenBackground);
}


