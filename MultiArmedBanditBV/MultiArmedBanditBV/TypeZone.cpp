#include "TypeZone.h"
#include "math.h"

TypeZone::TypeZone(int x, int y,TTF_Font* font,const char* text, SDL_Color textColor):_writingBox(NULL),_text(x-132,y,font,text,textColor)
{
	//setting the writing Box
	_writingBox=LoadImage("Images/getNumberBis.png");

	//before its creation the button is inactive
	_isActive=false;
	//There is no point
	_pointPosition = 0;
	//setting the box
	_box.x=x;
	_box.y=y;
	_box.h=(*_writingBox).clip_rect.h;
	_box.w=(*_writingBox).clip_rect.w+_text.GetWidth();
}


TypeZone::~TypeZone(void)
{
	//Deleting the writing box properly
	SDL_FreeSurface(_writingBox);
}

void TypeZone::DisplayCentered(Screens screen, double& a, TTF_Font* font, SDL_Color textColor)
{


	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = ((*(screen.GetScreen())).clip_rect.w-(_text.GetWidth()+ 10 +(*_writingBox).clip_rect.w))/2;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
		
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(x+_text.GetWidth()+13,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);
	_box.x=x;
	

}

void TypeZone::DisplayLeft(Screens screen, double& a, TTF_Font* font, SDL_Color textColor)
{	

	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = 100;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
	//relocate the button itself
	
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(x+_text.GetWidth()+13,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);
	_box.x=x;
}

void TypeZone::DisplayRight(Screens screen, double& a, TTF_Font* font, SDL_Color textColor)
{	

	//Calculate the position for centering (width of the screen minus width of the button divided by two
	int x = (*(screen.GetScreen())).clip_rect.w-100-_text.GetWidth()-(*_writingBox).clip_rect.w-10;

	//Set the position of the text and display it
	_text.SetPosition(x,_box.y);
	_text.Display(screen);

	//Display the writingBox
	ApplySurface(x+_text.GetWidth()+10,(_box.y-3),_writingBox,screen.GetScreen());
	
	//Convert the number into another type in order to display it
	std::stringstream strm;
    strm << a;

	//Using the class text to display the number

	Texts number(x+_text.GetWidth()+13,_box.y+1,font,strm.str().c_str(),textColor);
	number.Display(screen);
	_box.x=x;
}

void TypeZone::HandleEvents(SDL_Event event, double& a)
{
//Setting the mouse offset
	int x = 0;
	int y = 0;

		if( (event.type == SDL_KEYDOWN)&&_isActive )
		{
		//For the numbers before the period
		 if(_pointPosition==0)
		 {

			switch( event.key.keysym.sym )
				{//we add a number
				case SDLK_COMMA:_pointPosition=1;break;
				case SDLK_0:a=10*a;break;
				case SDLK_1:a=10*a+1;break;
				case SDLK_2:a=10*a+2;break;
				case SDLK_3:a=10*a+3;break;
				case SDLK_4:a=10*a+4;break;
				case SDLK_5:a=10*a+5;break;
				case SDLK_6:a=10*a+6;break;
				case SDLK_7:a=10*a+7;break;
				case SDLK_8:a=10*a+8;break;
				case SDLK_9:a=10*a+9;break;	

				//Or we delete the last one
				case SDLK_BACKSPACE:a=(a-10*((a/10)-(floor(a/10))))/10;
				}
		 }
		 else
		 {//For the numbers after the period
		 switch( event.key.keysym.sym )
				{//pointPosition allows to know where is the point and then adding the number
				case SDLK_0:_pointPosition++;break;
				case SDLK_1:a+=1*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_2:a+=2*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_3:a+=3*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_4:a+=4*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_5:a+=5*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_6:a+=6*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_7:a+=7*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_8:a+=8*pow(10.0,-_pointPosition); _pointPosition++;break;
				case SDLK_9:a+=9*pow(10.0,-_pointPosition); _pointPosition++;break;	
				case SDLK_BACKSPACE:
					//if there is just the point 
					if(_pointPosition==1)
					{
						//we just decrement the position
					_pointPosition--;
					}
					else
					{
					//we delete the last number
					double d=pow(10.0,_pointPosition-2);
					a=floor(a*d)/d;_pointPosition--;
					}
					
					break;
				}
		 
		 }
		 }

	 //If the mouse moved

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
				_isActive=true;
				} 
			 else
				{
				_isActive=false;
				}
		  }
		}


			
		
}

