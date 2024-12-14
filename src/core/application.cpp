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
		HUD::PRINT_HELP_B("<red>No Clip Controls\n</red>[F4] On/Off\n[WASD] Move\n[Ctrl] Go Down\n[Space] Go Up\n[Q] Speed-\n[E] Speed+\n[Shift] Speed Boost", 15.0f, true, 1, 0, 0, 0, 0);

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