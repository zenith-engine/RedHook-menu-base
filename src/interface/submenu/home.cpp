#include "home.hpp"
#include "main/self.hpp"

using namespace main_menu_vars;

namespace main_menu_vars {
	var vars;
}

void main_menu::initialize() {
	set_name("Home", true);

	this->add_option(submenu_option("Self")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Player")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Vehicle")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Weapon")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Misc")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Protection")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Teleport")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Network")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Recovery")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("ScriptHook")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Spawner")
		.add_submenu<self_menu>());

	this->add_option(submenu_option("Settings")
		.add_submenu<self_menu>());
}

void main_menu::update_once() {

}

void main_menu::update() {
}

void main_menu::feature_update() {}

/*Singleton*/
main_menu* _instance;
main_menu* main_menu::get_instance() {
	if (_instance == nullptr) {
		_instance = new main_menu();
		_instance->initialize();
		g_submenu_handler->add_submenu(_instance);
	}
	return _instance;
}
main_menu::~main_menu() { delete _instance; }