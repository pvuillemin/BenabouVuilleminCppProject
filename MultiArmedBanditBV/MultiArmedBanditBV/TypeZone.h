#pragma once
#include "Screens.h"
#include "Texts.h"
#include <vector>
class TypeZone
{
public:
	TypeZone(int x, int y,TTF_Font* font,const char* text, SDL_Color textColor);
	~TypeZone(void);

	//Different way of dipslaying it
	void DisplayCentered(Screens screen, double& a, TTF_Font* font, SDL_Color textColor);
	void DisplayLeft(Screens screen, double& a, TTF_Font* font, SDL_Color textColor);
	void DisplayRight(Screens screen, double& a, TTF_Font* font, SDL_Color textColor);
	void HandleEvents(SDL_Event event, double& a);//The box reacts to the user's actions
	bool _isActive;
private:
	//bool _isActive;//bool indicating if we can type in the box
	SDL_Rect _box;//the box containing the zone
	SDL_Surface* _writingBox;//the image of the box where we write
	Texts _text;//the text next to the box
	std::vector<int> _number;
	int _pointPosition;

};

