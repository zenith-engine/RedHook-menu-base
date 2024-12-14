#pragma once
#include "../pch.h"
#include "submenu_handler.hpp"

class renderer
{
public:
	static void initialize();
	static void update();

public:
	void render();
	void render_header();
	void render_sub_header();
	void render_background();
	void render_option_highlight();
	void render_footer();

public:

	RGBA m_header_color = { 255, 255, 255, 255 };
	RGBA m_sub_header_color = { 0, 0, 0, 210 };
	RGBA m_title_color = { 255, 255, 255, 255 };
	RGBA m_sub_menu_title_color = { 255, 255, 255, 255 };
	RGBA m_background_color = { 0, 0, 0, 190 };
	RGBA m_menu_text_color = { 255, 255, 255, 255 };
	RGBA m_highlighted_option_color = { 0, 0, 0, 255 };
	RGBA m_c_outline = { 255, 255, 255, 255 };
	RGBA m_c_primary = { 0, 0, 0, 255 };
	RGBA m_c_option = { 255, 255, 255, 255 };

	float m_width = 0.235f;
	float m_bg_opacity = 45;
	float m_line_Width = 0.0009f;
	float m_header_height = 0.083f;
	float m_render_options;
	float m_option_height = 0.037f;
	float m_sub_header_height = m_option_height;
	float m_footer_height = m_option_height;
	std::string m_tooltip = "";
	int m_2d_layer;
	int m_toggle_style;
	float* m_opacity = 0;

	float m_text_scale = 0.35f;

	float m_dialog_header_height = 0.0415f;
	float m_dialog_footer_height = 0.01725f;

	int m_max_options = 14;
	int m_current_option = 0;
	int m_previous_option = 0;
	int m_current_rendering_scroll;
	int m_scroll_offset;
	int m_break_scroll;

	Vector2 m_pos;
	Vector2 m_size;
	Vector2 m_position;

	inline static float m_scaled_x_coord;

	bool is_selected(int sub) {
		return m_current_rendering_scroll == (sub + 1);
	}

	bool is_opened = false;
	bool m_closing = false;

	bool is_open() const {
		return this->is_opened;
	}

	void open() {
		is_opened = true;
		m_closing = false;
	}
	void close() {
		m_closing = true;
		is_opened = false;
	}
	void toggle_open() { if (is_opened) close(); else open(); }

	void draw_title(const char* title);

	float lerp(float a, float b, float t) {
		return a + t * (b - a);
	}

	float get_option_y(int pos);

	bool renderer_title = false;
};

inline renderer* g_renderer;