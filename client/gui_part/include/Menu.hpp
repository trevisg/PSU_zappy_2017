//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu header
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu {
	public:
		Menu();
		~Menu();
		bool get_menu();
	private:
		sf::IntRect bgpos;
		sf::Font menufont;
		sf::VideoMode mode;
		sf::Sprite bgsprite;
		sf::Texture background;
		sf::String windowtitle;
};

extern sf::RenderWindow menuwindow;
