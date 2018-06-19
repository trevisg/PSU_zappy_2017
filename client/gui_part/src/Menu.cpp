//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu methods
//

#include "../include/Menu.hpp"
#include "../include/Menu_Title.hpp"
#include "../include/Menu_Options.hpp"
#include "../include/Menu_NewGame.hpp"

Menu::Menu()
{
	windowtitle = sf::String("ZAPPY 2K17");
	mode = sf::VideoMode(1920, 1080);
	menuwindow.create(mode, windowtitle);
	menuwindow.setFramerateLimit(60);
	if (!menufont.loadFromFile("assets/fonts/tantor.ttf")) {
		fprintf(stderr, "Failed to load font\n");
		menuwindow.close();
	}
	if (!background.loadFromFile("assets/textures/trantor.jpg")) {
		fprintf(stderr, "Failed to load background\n");
		menuwindow.close();
	}
	background.setSmooth(true);
	bgsprite.setTexture(background);
}

Menu::~Menu()
{
	menuwindow.close();
}

void 	event_handler()
{
	sf::Event event;

	while (menuwindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			menuwindow.close();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
				menuwindow.close();
			}
		}
	}
}

bool	Menu::get_menu()
{
	MenuTitle title(400, 0);
	MenuOptions opts(130, 1080);
	MenuNewGame ngame(100, 100);

	while (menuwindow.isOpen()) {
		event_handler();
		menuwindow.clear(sf::Color::Black);
		menuwindow.draw(bgsprite);
		menuwindow.draw(opts.getOptsRect());
		menuwindow.draw(opts.getOptsText());
		menuwindow.draw(ngame.getNewGameRect());
		menuwindow.draw(title.get_menutitletext());
		menuwindow.display();
	}
	return (false);
}
