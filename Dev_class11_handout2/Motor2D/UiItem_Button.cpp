#include "UiItem_Button.h"
#include "p2Point.h"

UiItem_Button::UiItem_Button(p2Point<int> pos, SDL_Texture* texture, const SDL_Rect* section) : itemUi(pos)
{
	this->texture = texture;
	if (section == NULL)
	{
		App->tex->GetSize(texture, (uint&)this->section.w, (uint&)this->section.h);
	}
	else
	{
		this->section = *section;
	}
}