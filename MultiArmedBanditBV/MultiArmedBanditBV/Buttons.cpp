
#include "Buttons.h"


Buttons::Buttons(int x, int y, std::string outImageFile, std::string inImageFile, std::string pushImageFile): _outImage(NULL), _inImage(NULL), _pushImage(NULL) 
{	//we set the box containing the button
	_box.x = x; 
	_box.y = y; 
	
	//We set all the images
	_outImage =LoadImage(outImageFile);
	_inImage = LoadImage(inImageFile);
	_pushImage = LoadImage(pushImageFile);

	//We use the parameters of the image to finish seting the box containing the button
	_box.h=(*_outImage).clip_rect.h;
	_box.w=(*_outImage).clip_rect.w;
	_activeImage = _outImage;
}


Buttons::~Buttons(void)
{
	//Here we delete the images (SDL_Surface*) properly
	SDL_FreeSurface(_outImage);
	SDL_FreeSurface(_inImage);
	SDL_FreeSurface(_pushImage);
	
}

void Buttons::SetActiveImage(SDL_Surface* image)
{
	_activeImage = image; 
}
SDL_Surface* Buttons::GetOutImage(void)
{
	return _outImage;
}
SDL_Surface* Buttons::GetInImage(void)
{
	return _inImage;
}


SDL_Surface* Buttons::GetPushImage(void)
{
	return _pushImage;
}

SDL_Rect Buttons::GetBox()
{
return _box;
}

bool Buttons::HandleEvents(SDL_Event event )
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
			 //we switch to the in image 
			 _activeImage = _inImage; 			
		    }
		 else
			{
			//we switch (or stay) to the out image
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
				_activeImage = _pushImage;
				} 
			} 
		}
	  //If a mouse button was released
	 if( event.type == SDL_MOUSEBUTTONUP ) 
		{ 
		 //If the left mouse button was released 
		if( event.button.button == SDL_BUTTON_LEFT ) 
			{ 
			 //Get the mouse offsets 
			 x = event.button.x; 
			 y = event.button.y; 
			 //If the mouse is over the button 
			 if( ( x > _box.x ) && ( x < _box.x + _box.w ) && ( y > _box.y ) && ( y < _box.y + _box.h ) ) 
				{ 
				 //returning false, allows the program to leave the loop.
				return false; 
				} 
			} 
		} 
//If the button wasn't pressed during the loop we continue
return true;
}



void Buttons::Show(Screens screen) const
{
 //Show the button 
 ApplySurface( _box.x, _box.y, _activeImage , screen.GetScreen() );
}