#ifndef ITEM_UI_H
#define ITEM_UI_H

#include "SDL/include/SDL.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "p2Point.h"
enum UI_STATES
{
	IDLE,
	HOVER,
	CLICK
};

class itemUi
{
protected:
	
	SDL_Texture* texture;
	SDL_Rect section = { 0,0,0,0 };
	bool hover = false;
	SDL_Texture* textureHover;
	SDL_Rect rectOnHover = { 0,0,0,0 };

	bool click = false;
	SDL_Texture* textureClick;
	SDL_Rect rectclick = { 0,0,0,0 };
public:
	SDL_Rect rect = { 0,0,0,0 };
	UI_STATES state = IDLE;
	itemUi(p2Point<int> position)
	{
		rect.x = position.x;
		rect.y = position.y;
	}
	virtual void Draw()
	{
		switch (state)
		{
		case IDLE:
			if (texture != nullptr)
			{
				App->render->Blit(texture, rect.x, rect.y, &section, 0.0F);
			}
			break;
		case HOVER:
			if (hover && textureHover!=nullptr)
			{
				App->render->Blit(textureHover, rect.x, rect.y, &rectOnHover, 0.0F);
			}
			else
			{
				App->render->Blit(texture, rect.x, rect.y, &section, 0.0F);
			}
			break;

		case CLICK:
			if (click && textureClick != nullptr)
			{
				App->render->Blit(textureClick, rect.x, rect.y, &rectclick, 0.0F);
			}
			else
			{
				App->render->Blit(texture, rect.x, rect.y, &section, 0.0F);
			}
			break;

		default:
			break;
		}
		
	}
	virtual void OnClick(uint MouseButtonNum)
	{
		state = CLICK;
	};
	virtual void OnHover()
	{
		state = HOVER;
	}
	virtual void AddHover(SDL_Texture* textureHover, const SDL_Rect* section)
	{
		if (!hover)
		{
			hover = true;
		}
		this->textureHover = textureHover;
		if (section != NULL)
		{
			rectOnHover = *section;
		}
		else
		{
			App->tex->GetSize(textureHover, (uint&)this->rectOnHover.w, (uint&)this->rectOnHover.h);
		}
	}
	virtual void AddClick(SDL_Texture* textureClick, const SDL_Rect* section)
	{
		if (!click)
		{
			click = true;
		}
		this->textureClick = textureClick;
		if (section != NULL)
		{
			rectclick = *section;
		}
		else
		{
			App->tex->GetSize(textureClick, (uint&)this->rectclick.w, (uint&)this->rectclick.h);
		}
	 }
};

#endif // !ITEM_UI_H

