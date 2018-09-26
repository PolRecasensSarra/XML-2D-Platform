#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

struct TileSet {
	char* name;
	uint tilewidth = 0;
	uint tileheight = 0;
	uint spacing = 0;
	uint margin = 0;
	p2SString file;
};
// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------

enum class render_order
{
	left_down,
	right_down,
	left_up,
	left_down,
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
// TODO 1: Create a struct needed to hold the information to Map node
struct Map {
	uint tilewidth = 0;
	uint tileheight = 0;
	uint width = 0;
	uint height = 0;
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


public:

	// TODO 1: Add your struct for map info as public for now

private:

	pugi::xml_document	map_file;
	pugi::xml_node		file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__