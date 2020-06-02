#pragma once

#include "game_object.h"
#include "text.h"


Game_Object::Game_Object(std::string id, std::string texture_id)
	: _translation(0, 0), _velocity(0, 0)
{
	_id = id;
	_texture_id = texture_id;

	_x = 0;
	_y = 0;

	_width  = 100;
	_height = 100;

	_flip = SDL_FLIP_NONE;
}
Game_Object::~Game_Object()
{
}

std::string Game_Object::id()
{
	return _id;
}

void Game_Object::simulate_physics(Uint32 milliseconds_to_simulate, Assets*)
{
	Vector_2D velocity = _velocity;
	velocity.scale((float)milliseconds_to_simulate);

	_translation += velocity;
}

void Game_Object::render(Uint32, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	SDL_Rect destination;
	destination.x = (int)_translation.x();
	destination.y = (int)_translation.y();
	destination.w = _width;
	destination.h = _height;

	const float PI = 3.14159265f;
	if(_velocity.magnitude() > 0)
	{
		if(abs(_velocity.angle()) <= (PI / 2.f))
		{
			_flip = SDL_FLIP_NONE;
		}
		else
		{
			_flip = SDL_FLIP_HORIZONTAL;
		}
	}

	Texture* texture = (Texture*)assets->get_asset(_texture_id);
	texture->render(renderer, nullptr, &destination, _flip);



	if(config->should_display_ids)
	{
		SDL_Color text_color;
		text_color.r = 255;
		text_color.g = 255;
		text_color.b = 0;
		text_color.a = 255;

		Text id(renderer, _id.c_str(), text_color, "ID.Text");

		id.render(renderer, _translation + Vector_2D((float)_width / 2, (float)_height));
	}



	if (config->should_display_position)
	{
		SDL_Color text_color;
		text_color.r = 255;
		text_color.g = 255;
		text_color.b = 0;
		text_color.a = 255;

		Text id(renderer, _id.c_str(), text_color, "ID._translation");

		id.render(renderer, _translation + Vector_2D((float)_width / 2, (float)_height));
	}


}

Vector_2D Game_Object::translation()
{
	return _translation;
}