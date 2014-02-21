#include "Texts.h"


Texts::Texts(int x, int y, TTF_Font* font, const char* text, SDL_Color textColor):_message(NULL)
{
	// Loading the attributes from the parameters
	_text=text;
	_textColor= textColor;
	_font=font;
	//Setting the surface which will be displayed
	_message = TTF_RenderText_Solid(font,_text,textColor);

	//Getting the dimensions of the message
	_box.x=x;
	_box.y=y;
	_box.h = (*_message).clip_rect.h;
	_box.w = (*_message).clip_rect.w;
}


Texts::~Texts(void)
{
	//Deleting the surface properly avoiding memory leak
	SDL_FreeSurface(_message);
}

int Texts::GetHeight()
{
return _box.h;
}

int Texts::GetWidth()
{
return _box.w;
}

void Texts::SetPosition(int x,int y)
{
_box.x=x;
_box.y=y;
}
void Texts::Display(Screens screen)
{
	ApplySurface(_box.x,_box.y,_message,screen.GetScreen());
}

void Texts::DisplayCentered(Screens screen)
{

	//get the dimension of the screen

	SDL_Surface screen2 = *(screen.GetScreen());
	int width = screen2.clip_rect.w;

	//Apply the surface at  the center (x = (width of screen - width of message)/2)

	ApplySurface((width-_box.w)/2,_box.y,_message,screen.GetScreen());
}

void Texts::SetColor(SDL_Color color)
{
//chnage the color
_textColor=color;

//change the message
_message = TTF_RenderText_Solid(_font,_text,_textColor);
}