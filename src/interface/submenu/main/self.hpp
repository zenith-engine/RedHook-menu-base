#pragma once
#include "../../submenu.hpp"
#include "../../submenu_handler.hpp"
#include "../../option/submenu_option.hpp"
#include "../../submenu/home.hpp"

class self_menu : public submenu
{
public:
	static self_menu* get_instance();

	void initialize() override;
	void update_once() override;
	void update() override;
	void feature_update() override;

	self_menu() : submenu() { }
	~self_menu();
};

namespace self_menu_vars
{
	struct var {
	};
}