#pragma once
#include "buttons.h"
class DownButton :
	public Buttons
{
public:
	DownButton(int x, int y);
	~DownButton(void);
	void DownButton::HandleEvents(SDL_Event event, int& a);
};



