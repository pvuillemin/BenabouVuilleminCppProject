#include "UpButton.h"
#include "Texts.h"


UpButton::UpButton(int x, int y,TTF_Font* font,const char* text, SDL_Color textColor)
	:Buttons(x,y,"Images/getNumberU.png","Images/getNumberU2.png","Images/getNumberU2.png"),_writingBox(NULL),_text(x-132,y,font,text,textColor)
{
	//setting the writing Box
	_writingBox=LoadImage("Images/getNumberBis.png");

}


UpButton::~UpButton(void)
{
	SDL_FreeSurface(_writingBox);
}

void UpButton::Show(Screens screen, int& a, TTF_Font* font, SDL_Color textColor)
{	

	

	
	//Display the writingBox
	ApplySurface((_box.x-122),(_box.y-3),_writingBox,screen.GetScreen());
	_text.Display(screen);
	Buttons::Show(screen);
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(_box.x-116,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);

}

void UpButton::DisplayCentered(Screens screen, int& a, TTF_Font* font, SDL_Color textColor)
{	

	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = ((*(screen.GetScreen())).clip_rect.w-(_text.GetWidth()+ 10 +(*_writingBox).clip_rect.w))/2;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
	//relocate the button itself
	_box.x=x+_text.GetWidth()+10+(*_writingBox).clip_rect.w-(*_activeImage).clip_rect.w-4;

	//then display
	Buttons::Show(screen);
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(_box.x-116,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);

}

void UpButton::DisplayLeft(Screens screen, int& a, TTF_Font* font, SDL_Color textColor)
{	

	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = 100;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
	//relocate the button itself
	_box.x=x+_text.GetWidth()+10+(*_writingBox).clip_rect.w-(*_activeImage).clip_rect.w-4;

	//then display
	Buttons::Show(screen);
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(_box.x-116,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);

}

void UpButton::DisplayRight(Screens screen, int& a, TTF_Font* font, SDL_Color textColor)
{	

	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = (*(screen.GetScreen())).clip_rect.w-100-_text.GetWidth()-(*_writingBox).clip_rect.w-10;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
	//relocate the button itself
	_box.x=x+_text.GetWidth()+10+(*_writingBox).clip_rect.w-(*_activeImage).clip_rect.w-4;

	//then display
	Buttons::Show(screen);
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(_box.x-116,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);

}

void UpButton::HandleEvents(SDL_Event event, int& a)
{
//Setting th mouse offset
	int x = 0;
	int y = 0;

	 //If the mouse moved
	if( event.type == SDL_MOUSEMOTION ) 
		{
		 //Get the mouse offsets
		 x = event.motion.x; 
		 y = event.motion.y; 
		 //If the mouse is over the button 
		 if( ( x > _box.x ) && ( x < _box.x + _box.w ) && ( y > _box.y ) && ( y < _box.y + _box.h ) ) 
			{ 
			 //Change the image 
			 _activeImage = _inImage; 			
		    }
		 else
			{
			_activeImage=_outImage;
			}
	
		}
	 //If a mouse button was pressed 
	if( event.type == SDL_MOUSEBUTTONDOWN ) 
		{ 
		 //If the left mouse button was pressed 
		 if( event.button.button == SDL_BUTTON_LEFT ) 
			{ 
			 //Get the mouse offsets 
			 x = event.button.x; 
			 y = event.button.y; 
			 //If the mouse is over the button 
			 if( ( x > _box.x ) && ( x < _box.x + _box.w ) && ( y > _box.y ) && ( y < _box.y + _box.h ) ) 
				{ 
				a++;
				} 
			} 
		}

}


