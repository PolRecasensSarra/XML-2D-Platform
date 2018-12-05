#ifndef ITEM_UI_H
#define ITEM_UI_H

#include "SDL/include/SDL.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "p2Point.h"
#include "j1Gui.h"

enum UI_STATES
{
	IDLE,
	HOVER,
	CLICK,
	MAX_STATES,
};

class itemUi
{
protected:
	
	SDL_Rect frames[MAX_STATES];
	UI_STATES state = IDLE;
	
public:
	SDL_Rect HitBox;
	itemUi(p2Point<int> position)
	{
		HitBox.x = position.x;
		HitBox.y = position.y;
	}

	virtual void Draw()
	{	
		App->render->Blit(App->gui->GetAtlas(), position.x, position.y, &frames[state].Rect, 0.0F);
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
		if (textureHover != nullptr && section!=nullptr)
		{
			frames[HOVER].tex = textureHover;
			if (section != NULL)
			{
				frames[HOVER].Rect = *section;
			}
			else
			{
				App->tex->GetSize(textureHover, (uint&)frames[HOVER].Rect.w, (uint&)frames[HOVER].Rect.h);
			}
			
		}
		
		
	}
	virtual void AddClick(SDL_Texture* textureClick, const SDL_Rect* section)
	{
		if (textureClick != nullptr && section != nullptr)
		{
			frames[CLICK].tex = textureClick;
			if (section != NULL)
			{
				frames[CLICK].Rect = *section;
			}
			else
			{
				App->tex->GetSize(textureClick, (uint&)frames[CLICK].Rect.w, (uint&)frames[CLICK].Rect.h);
			}

		}
	 }

};

#endif // !ITEM_UI_H

