#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	std::list<TileSet>::const_iterator iterator;
	for (iterator = tile_set.begin(); iterator != tile_set.end(); ++iterator) {
		App->render->Blit(iterator->tilesetImage, 0, 0);
	}

	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		map_node = map_file.child("map");
		LoadMap(map_node);
		
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	tile_node = map_file.child("tileset");
	LoadTile(tile_node);

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::LoadMap(const pugi::xml_node& map)
{
	map_info.height = map.attribute("height").as_uint();
	map_info.width = map.attribute("width").as_uint();
	map_info.tileheight = map.attribute("tileheight").as_uint();
	map_info.tilewidth = map.attribute("tilewidth").as_uint();
	map_info.version = map.attribute("version").as_float();

	//know which render value is in the tmx
	const char* render_order = map.attribute("renderorder").as_string();
	if (render_order[0] == 'r')
	{
		if (render_order[6] == 'd')
		{
			map_info.render = Map_info::render_order::right_down;
			LOG("Hem entrat aquiiiiiiiiiiiiiiiiiiiiiiii");
		}
		else
			map_info.render = Map_info::render_order::right_up;
	}
	else if (render_order[0] == 'l')
	{
		if (render_order[5] == 'd')
			map_info.render = Map_info::render_order::left_down;
		else
			map_info.render = Map_info::render_order::left_up;
	}

	//know which orientation value is in the tmx
	const char* orientation = map.attribute("orientation").as_string();
	if (orientation[0] == 'o')
	{
		map_info.orientation = Map_info::map_orientation::orthogonal;
		LOG("Tots som ortogonall wiiiiiiiii");
	}
	else if (orientation[0] == 'h')
	{
		map_info.orientation = Map_info::map_orientation::hexagonal_e;
	}
	else if (orientation[0] == 'i')
	{
		if (orientation[10] == 'e')
			map_info.orientation = Map_info::map_orientation::isometric_e;
		else
		map_info.orientation = Map_info::map_orientation::isometric;
	}

	return true;
}

bool j1Map::LoadTile(const pugi::xml_node& map)
{
	for (pugi::xml_node tileset = map_file.child("map").child("tileset"); tileset; tileset = tileset.next_sibling("tileset"))
	{
		TileSet newtile_set;
		newtile_set.tilesetImage = App->tex->Load(tileset.child("image").attribute("source").as_string());
		newtile_set.name = map.attribute("name").as_string();
		newtile_set.firstgid = map.attribute("firstgid").as_uint();
		newtile_set.tileheight = map.attribute("tileheight").as_uint();
		newtile_set.tilewidth = map.attribute("tilewidth").as_uint();
		newtile_set.margin = map.attribute("margin").as_uint();
		newtile_set.spacing = map.attribute("spacing").as_uint();
		newtile_set.file = map.attribute("source").as_string();
		tile_set.push_back(newtile_set);
	}

	return true;
}

