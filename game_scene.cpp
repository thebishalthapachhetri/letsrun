#include "game_scene.h"

#include "base.h"
#include "movingplayer.h"


Game_Scene::Game_Scene()
	: Scene("Game")
{
	

	Game_Object* Base = new base("base");
	_game_objects[Base->id()] = Base;

	Game_Object* Movingplayer = new movingplayer("movingplayer");
	_game_objects[Movingplayer->id()] = Movingplayer;


}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}