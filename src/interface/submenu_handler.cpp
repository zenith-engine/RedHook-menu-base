#include "../pch.h"
#include "submenu_handler.hpp"
#include "submenu/home.hpp"

void submenu_handler::initialize()
{
	m_main_submenu = m_current_submenu = main_menu::get_instance();
}

void submenu_handler::cleanup() {
	submenus.clear();
}

void submenu_handler::update() {
	m_current_submenu->menu_update();
	if (m_next_submenu != nullptr) {
		g_renderer->m_current_option = m_next_current_option;
		g_renderer->m_scroll_offset = m_next_scroll_offset;
		m_current_submenu = m_next_submenu;
		m_next_submenu = nullptr;
		m_current_submenu->update_once();
	}
}

void submenu_handler::async_update() {
	for (auto& sub : m_submenus) sub->feature_update();
}

void submenu_handler::set_submenu(submenu* submenu) {
	m_previous_submenu = m_current_submenu;
	m_current_submenu->old_current_option = g_renderer->m_current_option;
	m_current_submenu->old_scroll_offset = g_renderer->m_scroll_offset;
	m_next_current_option = 0;
	m_next_scroll_offset = 0;
	m_next_submenu = submenu;
}

void submenu_handler::set_sub_previous(bool resetPosition) {
	m_previous_submenu = m_current_submenu;
	if (m_current_submenu->get_parent_submenu() == nullptr) {
		g_submenu_handler->set_submenu_main();
		g_renderer->is_opened = false;
	}
	else {
		m_next_submenu = m_current_submenu->get_parent_submenu();
		m_next_current_option = resetPosition ? 0 : m_next_submenu->old_current_option;
		m_next_scroll_offset = resetPosition ? 0 : m_next_submenu->old_scroll_offset;
	}
}
void submenu_handler::set_submenu_main() {
	m_next_submenu = m_main_submenu;
	m_next_current_option = 0;
	m_next_scroll_offset = 0;
}