#include "input.h"

#include "resource.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_syswm.h>

#include <iostream>



Input::Input()
{
}
Input::~Input()
{
}

void Input::get_input()
{
	_button_state[Button::INCREASE_SPEED] = Button_State::UP;
	_button_state[Button::DECREASE_SPEED] = Button_State::UP;
	_button_state[Button::PAUSE] = Button_State::UP;
	_button_state[Button::SHOW_CREDITS]   = Button_State::UP;
	_button_state[Button::SHOW_VERSION] = Button_State::UP;
	_button_state[Button::HOW_TO_PLAY] = Button_State::UP;
	_button_state[Button::FAQ] = Button_State::UP;
	_button_state[Button::FEEDBACK] = Button_State::UP;
	_button_state[Button::DEBUG_SHOW_IDS] = Button_State::UP;
	_button_state[Button::DEBUG_SHOW_POSITION] = Button_State::UP;

	for(auto button_state : _button_state)
	{
		if(button_state.second == Button_State::PRESSED)
		{
			_button_state[button_state.first] = Button_State::DOWN;
		}
		else if(button_state.second == Button_State::RELEASED)
		{
			_button_state[button_state.first] = Button_State::UP;
		}
	}

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			_button_state[Button::QUIT] = Button_State::PRESSED;
			break;

		case SDL_SYSWMEVENT:
			if(event.syswm.msg->msg.win.wParam == ID_FILE_EXIT)
			{
				_button_state[Button::QUIT] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_PLAYER_INCREASESPEED)
			{
				_button_state[Button::INCREASE_SPEED] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_PLAYER_DECREASESPEED)
			{
				_button_state[Button::DECREASE_SPEED] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_PLAYER_PAUSE)
			{
				_button_state[Button::PAUSE] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_CREDITS_DEVELOPERS)
			{
				_button_state[Button::SHOW_CREDITS] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_HELP_HOWTOPLAY)
			{
				_button_state[Button::HOW_TO_PLAY] = Button_State::PRESSED;
			}

			else if (event.syswm.msg->msg.win.wParam == ID_EXTRA_VISITFORUM)
			{
				_button_state[Button::FAQ] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_FAQ_FEEDBACK)
			{
				_button_state[Button::FEEDBACK] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_CREDITS_SHOWVERSION)
			{
				_button_state[Button::SHOW_VERSION] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_DEBUG_TOGGLEDISPLAYID)
			{
				_button_state[Button::DEBUG_SHOW_IDS] = Button_State::PRESSED;
			}

			else if (event.syswm.msg->msg.win.wParam == ID_DEBUG_SHOWPOSITION)
			{
				_button_state[Button::DEBUG_SHOW_POSITION] = Button_State::PRESSED;
			}
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.scancode)
			{
			
			case SDL_SCANCODE_SPACE:
				if (!is_button_state(Button::JUMP, Button_State::DOWN))
				{
					_button_state[Button::JUMP] = Button_State::PRESSED;
				}
				break;
			
			
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.scancode)
			{
			
			case SDL_SCANCODE_SPACE:
				_button_state[Button::JUMP] = Button_State::RELEASED;
				break;
			}
			break;
		}
	}
}
bool Input::is_button_state(Button type, Button_State state)
{
	if(_button_state.find(type) == _button_state.end())
	{
		if(state == Button_State::UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return _button_state.find(type)->second == state;
}