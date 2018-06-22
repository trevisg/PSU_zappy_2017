//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu header
//

#ifndef MENU_HPP_

#include "../include/Menu_Title.hpp"
#include "../include/Menu_NewGame.hpp"
#include "../include/Menu_Settings.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu {
	public:
		Menu();
		~Menu();
		bool get_menu();
		void key_press_handler(sf::Event::KeyEvent ev);
		void event_handler(MenuSettings *, MenuNewGame *);
		void text_entered_handler(sf::Event, MenuSettings *);
		void mouse_click_handler(sf::Event::MouseButtonEvent,
					MenuSettings *, MenuNewGame *);
		void draw_menu(MenuTitle *, MenuSettings *, MenuNewGame *);
	private:
		sf::VideoMode	mode;
		sf::Event	event;
		sf::IntRect	bgpos;
		sf::Music	bgmusic;
		sf::Font	menufont;
		sf::Sprite	bgsprite;
		sf::Texture	background;
		sf::String	windowtitle;
};

extern sf::RenderWindow menuwindow;
#endif /* !MENU_HPP_ */
