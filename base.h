#pragma once
#include "game_object.h"

class base : public Game_Object
{
public:
	base(std::string id);
	~base();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
};