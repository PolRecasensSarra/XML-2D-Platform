#ifndef __j1GUI_H__
#define __j1GUI_H__
#include "j1Fonts.h"
#include "j1Module.h"

#include "itemUI.h"
#include "UiItem_Label.h"
#include "UiItem_Image.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

// ---------------------------------------------------
class j1Gui : public j1Module
{
private:
	TTF_Font * BaseFont = nullptr;
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	bool Update();
	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	

	// TODO 2: Create the factory methods
	// Gui creation functions
	UiItem_Label* AddLabel(p2Point<int> pos, const char* text, SDL_Color color, TTF_Font* font);
	UiItem_Image* AddImage(p2Point<int> pos, SDL_Texture* texture, const SDL_Rect* section);

	const SDL_Texture* GetAtlas() const;
	p2List<itemUi*> ListItemUI;
private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__