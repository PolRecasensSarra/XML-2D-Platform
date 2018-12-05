#include "UiItem_Label.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Textures.h"
UiItem_Label::UiItem_Label(p2Point<int> pos, p2SString text, SDL_Color color, TTF_Font * font):itemUi(pos)
{
	CreateText(text.GetString(),color, font);
	if(texture!=nullptr)
	App->tex->GetSize(texture, (uint&)rect.w, (uint&)rect.h);
	hover = true;

	p2SString hoverText(text);
	hoverText += "is Hover";
	textureHover = App->font->Print(hoverText.GetString(), color, font);
	App->tex->GetSize(textureHover, (uint&)rectOnHover.w, (uint&)rectOnHover.h);

}

void UiItem_Label::CreateText(const char* text, SDL_Color color, TTF_Font* font)
{
	texture = App->font->Print(text, color, font);
}
