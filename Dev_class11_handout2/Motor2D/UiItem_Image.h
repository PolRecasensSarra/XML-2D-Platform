#ifndef UIITEM_IMAGE_H
#define UIITEM_IMAGE_H
#include "itemUI.h"
#include "p2Point.h"
#include "j1Textures.h"

class UiItem_Image:public itemUi
{
public:
	UiItem_Image(p2Point<int> pos, SDL_Texture* texture, const SDL_Rect* section);

};
#endif // !UIITEM_IMAGE_H

