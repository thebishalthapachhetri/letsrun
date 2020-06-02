#pragma once

#include "movingplayer.h"

movingplayer::movingplayer(std::string id)
	: Game_Object(id, "Texture.movingplayer")
{
	//_x = 3250;
	//_y = 5000;
	//for not going forward
	_translation = Vector_2D(150, 255);
	//_velocity = Vector_2D(0.02f, 0);
	_state.push(State::Moving);
	_height = 150;
	_width = 150;
	

}
movingplayer::~movingplayer()
{
}

void movingplayer::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer,Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void movingplayer::simulate_AI(Uint32, Assets* assets, Input* input)
{
	switch (_state.top())
	{
	case State::Moving:
		if (input->is_button_state(Input::Button::JUMP, Input::Button_State::DOWN))
		{
			push_state(State::Jump, assets);
		}

		break;

	case State::Jump:
		/*if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}*/
		if (input->is_button_state(Input::Button::JUMP, Input::Button_State::RELEASED))
		{
			pop_state(assets);

		}
		break;
	}
	//_translation = Vector_2D(0,0);

	//jumping for the fox
	if (input->is_button_state(Input::Button::JUMP, Input::Button_State::DOWN))
	{
		_translation = Vector_2D(150, 30);
	}

	if (input->is_button_state(Input::Button::JUMP, Input::Button_State::RELEASED))
	{
		_translation = Vector_2D(150, 255);
	}

	
	

	
}

void movingplayer::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
}
void movingplayer::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void movingplayer::handle_enter_state(State state, Assets* )
{
	switch (state)
	{
	case State::Moving:
		_texture_id = "Texture.movingplayer";
		break;
	case State::Jump:
	{
		_texture_id = "Texture.movingplayer.jump";
		   const int walking_channel = 1;
		break;
	}

	}
}

void movingplayer::handle_exit_state(State state, Assets*)
{
	switch (state)
	{
	case State::Moving:
		break;

	case State::Jump:
		break;
	}
	
}