#pragma once

#include "editor.h"
#include "resource.h"


#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>

Editor::Editor(std::wstring window_name)
{
    _window = FindWindow(NULL, window_name.c_str());
    if(_window == NULL)
    {
        std::cout << "Failed to find window. Window Name: " << window_name.c_str() << std::endl;
        exit(1);
    }

    _menu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
    if(_menu == NULL)
    {
        std::cout << "Failed to create menu." << std::endl;
        exit(1);
    }

    BOOL set_menu_result = SetMenu(_window, _menu);
    if(set_menu_result == 0)
    {
        std::cout << "Failed to set menu." << std::endl;
        exit(1);
    }

    Uint8 event_state_result  = SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
    Uint8 event_state_success = SDL_DISABLE;
    if(event_state_result != event_state_success)
    {
        std::cout << "Failed to enable Windows event state." << std::endl;
        exit(1);
    }    
}

Editor::~Editor()
{
}

INT_PTR CALLBACK Dialog_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
    switch(Message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON1:
            EndDialog(hwnd, IDOK);
            break;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

INT_PTR CALLBACK Dialog_Proc1(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
    switch (Message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            EndDialog(hwnd, IDOK);
            break;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;


}

INT_PTR CALLBACK Dialog_Proc2(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
    switch (Message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            EndDialog(hwnd, IDOK);
            break;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;


}

INT_PTR CALLBACK Dialog_Proc3(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
    switch (Message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            EndDialog(hwnd, IDOK);
            break;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;


}


INT_PTR CALLBACK Dialog_Proc4(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
    switch (Message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            EndDialog(hwnd, IDOK);
            break;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;


}


void Editor::update(Input* input, Scene* , Configuration* config)
{
   

    if(input->is_button_state(Input::Button::SHOW_CREDITS, Input::Button_State::PRESSED))
    {
        DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), _window, Dialog_Proc);
    }

    if (input->is_button_state(Input::Button::HOW_TO_PLAY, Input::Button_State::PRESSED))
    {
        DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2), _window, Dialog_Proc);
    }

    if (input->is_button_state(Input::Button::SHOW_VERSION, Input::Button_State::PRESSED))
    {
        DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG3), _window, Dialog_Proc);
    }

    if (input->is_button_state(Input::Button::FAQ, Input::Button_State::PRESSED))
    {
        DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG4), _window, Dialog_Proc);
    }


    if (input->is_button_state(Input::Button::FEEDBACK, Input::Button_State::PRESSED))
    {
        DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG5), _window, Dialog_Proc);
    }


    if(input->is_button_state(Input::Button::DEBUG_SHOW_IDS, Input::Button_State::PRESSED))
    {
        config->should_display_ids = !config->should_display_ids;
    }

    if (input->is_button_state(Input::Button::DEBUG_SHOW_POSITION, Input::Button_State::PRESSED))
    {
        config->should_display_position = !config->should_display_position;
    }
}



