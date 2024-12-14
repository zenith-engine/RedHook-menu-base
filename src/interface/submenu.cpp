#include "../pch.h"
#include "submenu.hpp"
#include "renderer.hpp"
#include "submenu_handler.hpp"
#include "option/option.hpp"

void submenu::menu_update() {
	update();
	g_renderer->draw_title(submenu::name.c_str());
	g_submenu_handler->current_option_without_breaks = 0;
	g_submenu_handler->total_options_without_breaks = 0;
	g_submenu_handler->total_options = 0;
	std::vector<std::shared_ptr<option>> tempOptions;
	tempOptions.reserve(options.size());
	if (options.size() > 0) {
		int relativeOptionPosition = 0, visibilityOffset = 0;
		for (int i = 0; i < options.size(); i++) {
			if (options.at(i)->is_visible()) {
				tempOptions.push_back(options.at(i));
				visibilityOffset++;
				g_submenu_handler->total_options++;
				if (!options.at(i)->is_break()) {
					if (visibilityOffset <= g_renderer->m_current_option) g_submenu_handler->current_option_without_breaks++;
					g_submenu_handler->total_options_without_breaks++;
				}
			}
		}
		for (int i = g_renderer->m_scroll_offset; i < g_renderer->m_scroll_offset + g_renderer->m_max_options; i++) {
			if (i >= 0 && i < tempOptions.size()) {
				if (relativeOptionPosition >= g_renderer->m_max_options) break;
				tempOptions.at(i).get()->render(relativeOptionPosition);
				if (relativeOptionPosition == g_renderer->m_current_option - g_renderer->m_scroll_offset) {
					option* option = tempOptions.at(i).get();
					if (g_renderer->is_open()) option->render_selected(relativeOptionPosition);
				} relativeOptionPosition++;
			}
		}
	}
}
submenu::~submenu() {}
void submenu::initialize() {}
void submenu::update_once() {}
void submenu::update() {}
void submenu::feature_update() {}