#pragma once
#include <string>
#include <iostream>

struct Menus
{
private:
	std::string _choice;
	std::string _formatted_choice;


public:

	void draw_header();
	void draw_separation();
	void draw_footer();

	void draw_main_menu();
	void draw_settings_menu();
	void draw_advanced_settings_menu();

};

