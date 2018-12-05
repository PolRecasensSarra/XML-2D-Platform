#include "UiItem_Image.h"
#include "j1App.h"
#include "j1Textures.h"


UiItem_Image::UiItem_Image(p2Point<int> pos, SDL_Texture * texture, const SDL_Rect * section) : itemUi(pos)
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

