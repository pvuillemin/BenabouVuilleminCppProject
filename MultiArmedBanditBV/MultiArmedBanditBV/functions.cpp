#include "functions.h"



//Function allowing to blit surfaces on the screen
void ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{

//Make a temporary rectangle to hold the offsets
SDL_Rect offset;

//Give the offsets to the rectangle
offset.x = x;
offset.y = y;

//Blit the surface
SDL_BlitSurface (source,NULL,destination,&offset);
}


//Function permitting to load image into a format which can be blitted on the screen
SDL_Surface* LoadImage(std::string filename)
{
	//Temporary storage for the image that's loaded 	
	SDL_Surface* loadedImage = NULL; 

	//The optimized image that will be used 	
	SDL_Surface* optimizedImage = NULL;

	

	//Load the image
	loadedImage = IMG_Load( filename.c_str() );

	//If nothing went wrong in loading the image
	 if (loadedImage != NULL)
	 {
		//Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

		//Free the old image
		SDL_FreeSurface( loadedImage );

		//Return the optimized image
		return optimizedImage;
	 }
}

const char* Convert(int i)
{
	std::stringstream strm;
    strm << i;
	return strm.str().c_str();
}
