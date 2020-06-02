#include "assets.h"
#include "texture.h"
#include "animated_texture.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
	
	// Cache floor Texture.
	{
		Texture* texture = new Texture("Texture.base", "Assets/base.png", renderer);
		_assets[texture->id()] = texture;
	}
	

	// Cache movingfox Texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* texture = new Animated_Texture("Texture.movingplayer","Assets/movingplayer.png",renderer,frame_count,frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}


	

	// Create player jump texture.
	{
		const int frame_count = 10 ;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* texture = new Animated_Texture("Texture.movingplayer.jump", "Assets/jumper.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}	
}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}