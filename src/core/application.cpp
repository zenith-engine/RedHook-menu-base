#include "../pch.h"
#include "application.h"
#include "../util/input/inputs_manager.h"
#include "../interface/renderer.hpp"

void application::initialize(HMODULE _Module)
{
	inputs_manager::initialize();
	g_submenu_handler->initialize();

	ScriptRegister(_Module, []
	{
		HUD::PRINT_HELP_B("<red>Menu Controls\n</red>[F4] Open\n[RIGHT] Move number\n[LEFT] Move number\n[DOWN] Go Down\n[UP] Go Up", 15.0f, true, 1, 0, 0, 0, 0);

		while (true)
		{
			if (g_renderer->is_open())
			{
				g_renderer->render();
				g_submenu_handler->update();
				g_submenu_handler->async_update();
			}
			ScriptWait(0);
		}
	});
}



void application::cleanup(HMODULE _Module)
{
	ScriptUnregister(_Module);

	inputs_manager::cleanup();
}
