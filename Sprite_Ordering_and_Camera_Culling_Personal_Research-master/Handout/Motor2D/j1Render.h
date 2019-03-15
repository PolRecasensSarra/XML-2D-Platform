#ifndef __j1RENDER_H__
#define __j1RENDER_H__

#include "SDL/include/SDL.h"
#include "p2Point.h"
#include "j1Module.h"
#include "j1App.h"
#include "j1Window.h"


class j1Render : public j1Module
{
public:

	j1Render();

	// Destructor
	virtual ~j1Render();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Load / Save
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;
	SDL_Rect CameraInitPos();

	// Blit
	//TODO 1: Create IsOnCamera function that returns true if a RECTANGLE is on camera's viewport
	/*Warnings: 
				Camera position uses negative numbers to go right and down
				Scale is important (Use 1, 2 and 3 to change between scales)
				You can use SDL_HasIntersection(SDL_Rect1, SDL_Rect2) to be more agile*/

	bool IsOnCamera(const int x, const int y, const int width, const int height) 
	{
		SDL_Rect camera_neg = { -camera.x, -camera.y, camera.w, camera.h };
		/*if (rect.x>camera_neg.x && rect.x<(camera_neg.x+ camera_neg.w) && rect.y>camera_neg.y && rect.y<(camera_neg.y+ camera_neg.h))
			return true;*/
		uint scale = App->win->GetScale();
		SDL_Rect rect = { x*scale, y*scale, width*scale, height*scale };
		if (SDL_HasIntersection(&camera_neg, &rect))
			return true;
		return false;
	}

	iPoint ScreenToWorld(int x, int y) const;
	bool Blit(SDL_Texture* texture, int x, int y, const SDL_Rect* section = NULL, float speed = 1.0f, bool scale = true, SDL_RendererFlip = SDL_FLIP_NONE, double angle = 0, int pivot_x = INT_MAX, int pivot_y = INT_MAX);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool filled = true, bool use_camera = true) const;
	bool DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool use_camera = true) const;
	bool DrawCircle(int x1, int y1, int redius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool use_camera = true) const;

	// Set background color
	void SetBackgroundColor(const SDL_Color &color);

public:

	SDL_Renderer*	renderer;
	SDL_Rect		camera;
	SDL_Color		background;
};

#endif // __j1RENDER_H__