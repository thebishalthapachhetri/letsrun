#pragma once

#include <map>

class Input
{
public:
	Input();
	~Input();

	enum class Button
	{
		QUIT,

		
		JUMP,

		INCREASE_SPEED,
		DECREASE_SPEED,
		PAUSE,
		HOW_TO_PLAY,
		FAQ,
		SHOW_VERSION,
		FEEDBACK,
		SHOW_CREDITS,
		DEBUG_SHOW_POSITION,
		DEBUG_SHOW_IDS
	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
	};

	void get_input();
	bool is_button_state(Button type, Button_State state);

private:
	std::map<Button, Button_State> _button_state;
};