#include "../../pch.h"
#include "submenu_option.hpp"
#include "../../util/input/inputs_manager.h"

void submenu_option::render_selected(int position) {
	current_op();
	if (input::is_key_just_pressed(KEY_NUMPAD_5) && Requirement()) {
		function();
		g_submenu_handler->set_submenu(submenus);
	}
};

void submenu_option::render(int position) {
	on_update(this);

	RGBA color = g_renderer->is_selected(position) ? g_renderer->m_highlighted_option_color : g_renderer->m_menu_text_color;
	RH_DrawText(name.c_str(), 0.742f + g_renderer->m_pos.x - (0.01f / 2) - 0.7f + (g_renderer->is_selected(position) ? 0.0025f : 0.f), ((position + 2) * 0.037f + 0.11f) + g_renderer->m_pos.y + 0.001f, 0, g_renderer->m_text_scale, color.r, color.g, color.b, color.a, TextAlignment_Left);
	RH_DrawText(">", (0.742f + g_renderer->m_pos.x - (0.01f / 2) - 0.7f) + 0.22f, ((position + 2) * 0.037f + 0.112f) + g_renderer->m_pos.y + 0.001f + 0.012f, 0, 0.025f, color.r, color.g, color.b, color.a, TextAlignment_Right);
}