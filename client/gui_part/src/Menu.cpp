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
		fprintf(stderr, "Failed to load menu font\n");
		menuwindow.close();
	}
	if (!background.loadFromFile("assets/textures/trantor.jpg")) {
		fprintf(stderr, "Failed to load background image\n");
		menuwindow.close();
	}
	background.setSmooth(true);
	bgsprite.setTexture(background);
	if (!bgmusic.openFromFile("assets/musics/menu-bg.ogg")) {
		fprintf(stderr, "Failed to load background music\n");
		menuwindow.close();
	}
	bgmusic.setLoop(true);
}

Menu::~Menu()
{
	menuwindow.close();
}

void 	Menu::event_handler()
{
	sf::SoundSource::Status mstatus;

	while (menuwindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			menuwindow.close();
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Q) {
				menuwindow.close();
			} else if (event.key.code == sf::Keyboard::P) {
				 mstatus = bgmusic.getStatus();
				if (mstatus == sf::SoundSource::Playing)
					bgmusic.pause();
				else
					bgmusic.play();
			}
		}
	}
}

bool	Menu::get_menu()
{
	MenuTitle title(400, 0);
	MenuOptions opts(130, 1080);
	MenuNewGame ngame(100, 100);

	bgmusic.play();
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
