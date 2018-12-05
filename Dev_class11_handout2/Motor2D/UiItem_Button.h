#ifndef UIITEM_BUTTON_H
#define UIITEM_BUTTON_H
#include "itemUI.h"
#include "p2Point.h"
#include "j1Textures.h"

class UiItem_Button :public itemUi
{
public:
	SDL_Rect section = {0,0,0,0};

public:
	UiItem_Button(p2Point<int> pos, SDL_Texture* texture, const SDL_Rect* section);
	

};

#endif