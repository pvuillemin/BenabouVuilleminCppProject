#include "DownButton.h"


DownButton::DownButton(int x, int y)
	:Buttons(x,y,"Images/getNumberD.png","Images/getNumberD2.png","Images/getNumberD2.png")
{
}


DownButton::~DownButton(void)
{
}

void DownButton::HandleEvents(SDL_Event event, int& a)
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
				a--;
				} 
			} 
		}

}



