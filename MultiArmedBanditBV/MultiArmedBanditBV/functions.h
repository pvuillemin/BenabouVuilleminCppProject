#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <sstream>

	

//Function permitting to load an image
SDL_Surface* LoadImage(std::string filename);

//Function permitting to blit a surface
void ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination);

const char* Convert(int i);