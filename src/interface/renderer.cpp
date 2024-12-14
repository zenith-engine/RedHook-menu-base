#include "renderer.hpp"
#include "../util/math.h"

void renderer::render() {
	g_submenu_handler->get_total_options() > m_max_options ? m_render_options = m_max_options : m_render_options = g_submenu_handler->get_total_options();

	m_scaled_x_coord = 0.15f;
	m_size = { m_width, m_header_height * 2 };
	m_position.x = 0.16f;
	m_position.y = 0.1175f;

	if (renderer_title)
		RH_DrawText(NAME, m_scaled_x_coord + m_pos.x, 0.07533f + m_pos.y, 1, 1.0f, m_title_color.r, m_title_color.g, m_title_color.b, m_title_color.a, TextAlignment_Center);

	render_header();
	render_sub_header();
	render_background();
	render_option_highlight();
	render_footer();
}

void renderer::render_header() {
	RH_DrawRect(m_scaled_x_coord + m_pos.x, 0.09733f + m_pos.y, 0.235f, 0.09200f, m_header_color.r, m_header_color.g, m_header_color.b, m_header_color.a);
}

void renderer::render_sub_header() {
	RH_DrawRect(m_scaled_x_coord + m_pos.x, 0.16027f + m_pos.y, 0.235f, 0.03753f, m_sub_header_color.r, m_sub_header_color.g, m_sub_header_color.b, m_sub_header_color.a);
	RH_DrawText(std::format("{} / {}", m_current_option + 1, g_submenu_handler->get_total_options()).c_str(), m_pos.x + m_scaled_x_coord + (0.958f - 0.7f), m_pos.y + 0.14587f, 0, 0.37f, m_sub_menu_title_color.r, m_sub_menu_title_color.g, m_sub_menu_title_color.b, m_sub_menu_title_color.a, TextAlignment_Right);
}

void renderer::render_background() {
	RH_DrawRect(m_scaled_x_coord + m_pos.x, (0.198f + ((0.019f - 0.00040f) * (m_render_options - 1))) + m_pos.y, 0.235f, (0.040f + ((0.037f + 0.00010f) * (m_render_options - 1))), m_background_color.r, m_background_color.g, m_background_color.b, m_background_color.a);
}

void renderer::render_option_highlight() {
	static float CurrentCoord = m_pos.y;

	m_current_rendering_scroll = math::clamp(m_current_option - m_scroll_offset > m_max_options ? m_max_options : (m_current_option - m_scroll_offset) + 1, 0, m_max_options);
	CurrentCoord = lerp(CurrentCoord, (0.161333f + (m_current_rendering_scroll * m_option_height)) + m_pos.y, 0.25f);

	RH_DrawRect(m_scaled_x_coord + m_pos.x, CurrentCoord, 0.235f, 0.03753f, 255, 255, 255, 255);
}

void renderer::render_footer() {
	int index = g_submenu_handler->get_total_options() > m_max_options ? m_max_options : g_submenu_handler->get_total_options();
	RH_DrawRect(m_scaled_x_coord + m_pos.x, ((0.1978f + ((0.03753f - 0.00030f) * index))) + m_pos.y, 0.235f, 0.03753f, m_sub_header_color.r, m_sub_header_color.g, m_sub_header_color.b, m_sub_header_color.a);
}

void renderer::draw_title(const char* title) {
	std::string str = title;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	RH_DrawText(str.c_str(), 0.742f + m_pos.x - (0.01f / 2) - 0.7f, 0.14587f + m_pos.y, 0, 0.37f, m_sub_menu_title_color.r, m_sub_menu_title_color.g, m_sub_menu_title_color.b, m_sub_menu_title_color.a, TextAlignment_Left);
}

float renderer::get_option_y(int pos) {
	return (pos * m_option_height) + m_pos.y + m_header_height / 2 + m_sub_header_height / 2 + m_sub_header_height / 2;
}