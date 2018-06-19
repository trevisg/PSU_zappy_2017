//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu header
//

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu {
	public:
		Menu();
		~Menu();
		bool get_menu();
		void event_handler();
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
