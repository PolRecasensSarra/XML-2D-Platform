#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include <list>

struct TileSet {
	SDL_Texture* tilesetImage;
	p2SString name;
	uint firstgid = 0;
	uint tilewidth = 0;
	uint tileheight = 0;
	uint spacing = 0;
	uint margin = 0;
	p2SString file;
};
// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------



// TODO 1: Create a struct needed to hold the information to Map node
struct Map_info {
	enum class render_order
	{
		left_down,
		right_down,
		left_up,
		right_up,
		error
	};
	enum class map_orientation
	{
		orthogonal,
		isometric,
		isometric_e,
		hexagonal_e,
		error
	};
	uint tilewidth = 0;
	uint tileheight = 0;
	uint width = 0;
	uint height = 0;
	float version = 0.0f;
	render_order render = render_order::error;
	map_orientation orientation = map_orientation::error;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	
private:
	bool LoadMap(const pugi::xml_node& map);
	bool LoadTile(const pugi::xml_node& map);

public:
	// TODO 1: Add your struct for map info as public for now
	Map_info map_info;
	//TileSet tile_set;
	std::list<TileSet> tile_set;

private:

	pugi::xml_document	map_file;
	pugi::xml_node		map_node;
	pugi::xml_node		tile_node;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__