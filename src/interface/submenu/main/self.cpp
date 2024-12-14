#include "../../../pch.h"
#include "self.hpp"

using namespace self_menu_vars;

namespace self_menu_vars {
	var vars;
}

void self_menu::initialize() {
	set_name("Home", true);
	set_parent_submenu<main_menu>();
}

void self_menu::update_once() {

}

void self_menu::update() {
}

void self_menu::feature_update() {}

/*Singleton*/
self_menu* _instance;
self_menu* self_menu::get_instance() {
	if (_instance == nullptr) {
		_instance = new self_menu();
		_instance->initialize();
		g_submenu_handler->add_submenu(_instance);
	}
	return _instance;
}
self_menu::~self_menu() { delete _instance; }