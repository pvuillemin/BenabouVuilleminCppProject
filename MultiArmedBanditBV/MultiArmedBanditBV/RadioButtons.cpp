#include "RadioButtons.h"

//we use the constructor of Buttons to initialize the two buttons
RadioButtons::RadioButtons(int x, int y, const char* text, TTF_Font* font,SDL_Color textColor):Buttons(x,y,"Images/empty.png","Images/empty.png","Images/empty.png"), _inactiveButton(x,y,"Images/radio1.png","Images/radio2.png","Images/radio3.png"),
	_activeButton(x,y,"Images/radio4.png","Images/radio5.png","Images/radio6.png"), _text(x+13,y-2,font,text,textColor)
{
	//Initialization
	// When the button is generated it's inactive
	_active=false;
	_activeImage= _inactiveButton.GetOutImage();//and the mouse is (probably) out of the button

	//set the text color
	_textColor = textColor;
	
	//Defining the dimensions of the button
	_box.h=12;//the size of the button is always the same
	_box.w=13+_text.GetWidth();//12 for the button itself and one pixel of margin then the width of the text

}


RadioButtons::~RadioButtons(void)
{
}

void RadioButtons::SetPosition(int x, int y)
{
_box.x=x;
_box.y=y;

_text.SetPosition(x+_box.h+2,y-2);
}

void RadioButtons::Show(Screens screen)
{
	//We display the text and the button itself
	ApplySurface(_box.x,_box.y,_activeImage,screen.GetScreen());
	_text.Display(screen);
}


void RadioButtons::HandleEvents(SDL_Event event)
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
			 //we switch to the in image according if the button is active or not
				if(_active)
				{
				 
				_activeImage=_activeButton.GetInImage(); 
				
				}
				else
				{
				_activeImage=_inactiveButton.GetInImage();
				}
		    }
		 else
			{
			//According if the button is active or not we keep or put back the out image
			if(_active)
				{				 
				_activeImage=_activeButton.GetOutImage(); 
				}
			else
				{
				_activeImage=_inactiveButton.GetOutImage();
				}
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
					//According if the button is active or not
					if(_active)
				    {
					//we switch to the Push image 
					_activeImage=_activeButton.GetPushImage();  
					}
					else
					{
					_activeImage=_inactiveButton.GetPushImage();
					}
				//Anyway the button is now active
				_active=true;
				}
			 else
				{//If the click was on the horizontal box but not in the box 
				if(( y >_box.y ) && ( y < _box.y + _box.h ))
					{
						//The button becomes inactive
						_active=false;
					}
				 }
			} 
		}
	
	


}

bool RadioButtons::IsActive()
{
	return _active;
}

void RadioButtons::SetColor(SDL_Color color)
{
_textColor=color;
_text.SetColor(color);
}

