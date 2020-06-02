#pragma once

#include "game_object.h"
#include "assets.h"
#include <stack>

class movingplayer : public Game_Object
{
public:
	movingplayer(std::string id);
	~movingplayer();
	


	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;

	enum class State
	{
		Moving,
		Jump
		
	};
	void push_state(State state, Assets* assets);
	void pop_state(Assets* assets);
private:
	void handle_enter_state(State state, Assets* assets);
	void handle_exit_state(State state, Assets* assets);
	std::stack<State> _state;
};