//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu methods
//

#include "Menu.hpp"
#include <iostream>

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

void	Menu::text_entered_handler(sf::Event ev, MenuSettings *opts)
{
	static std::string	str;
	const  std::string	hostmod("127.0.0.1");
	sf::Text		txt;

	if (ev.text.unicode < 128 && (opts || !opts)) {
		str += static_cast<char>(ev.text.unicode);
		if (str.length() == hostmod.length()) {
			std::cout << str << std::endl;
			txt.setString(str);
		}
	}
}

void	Menu::mouse_click_handler(sf::Event::MouseButtonEvent ev,
			MenuSettings *opts, MenuNewGame *ngame)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(menuwindow);
	sf::Vector2f worldPos = menuwindow.mapPixelToCoords(pixelPos);
	sf::FloatRect newgamebounds = ngame->getnewgamebutton().getGlobalBounds();
	sf::FloatRect optsbounds = opts->getOptsRect().getGlobalBounds();
	bool start_game_click = newgamebounds.contains(worldPos.x, worldPos.y);
	bool server_options_click = optsbounds.contains(worldPos.x, worldPos.y);

	if (ev.button == sf::Mouse::Button::Left && opts) {
		if (start_game_click) {
			bgmusic.pause();
			int x_mapsize = 5;
			int y_mapsize = 5;
			if (!(ngame->getGameWindow()->_start_me(x_mapsize,
			y_mapsize))) {
				bgmusic.play();
			}
		} else if (server_options_click) {
			std::cout << "Click on options\n";
		}
	}
}

void	Menu::key_press_handler(sf::Event::KeyEvent ev)
{
	sf::SoundSource::Status mstatus;

	if (ev.code == sf::Keyboard::Escape) {
		menuwindow.close();
	} else if (ev.code == sf::Keyboard::F1) {
		 mstatus = bgmusic.getStatus();
		if (mstatus == sf::SoundSource::Playing)
			bgmusic.pause();
		else
			bgmusic.play();
	}
}

void 	Menu::event_handler(MenuSettings *opts, MenuNewGame *ngame)
{
	while (menuwindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			menuwindow.close();
		} else if (event.type == sf::Event::KeyPressed) {
			key_press_handler(event.key);
		} else if (event.type == sf::Event::MouseButtonPressed) {
			mouse_click_handler(event.mouseButton, opts, ngame);
		} else if (event.type == sf::Event::TextEntered) {
			text_entered_handler(event, opts);
		} else if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width,
							event.size.height);
			menuwindow.setView(sf::View(visibleArea));
		}
	}
}

void	Menu::draw_menu(MenuTitle *title, MenuSettings *opts,
			MenuNewGame *ngame)
{
	menuwindow.draw(bgsprite);
	menuwindow.draw(opts->getOptsRect());
	menuwindow.draw(opts->getOptsText());
	menuwindow.draw(opts->getServerHostSettingsRect());
	menuwindow.draw(opts->getServerPortSettingsRect());
	// menuwindow.draw(ngame->getnewgamebutton());
	// menuwindow.draw(ngame->getNewGameText());
	menuwindow.draw(title->get_menuTitleText());
	menuwindow.draw(title->get_menuHelpText());
}

bool	Menu::get_menu()
{
	MenuTitle title(880, 0);
	MenuSettings opts(140, 1080);
	MenuNewGame ngame(100, 30);
	MenuTitle *title_ptr = &title;
	MenuSettings *opts_ptr = &opts;
	MenuNewGame *ngame_ptr = &ngame;

	bgmusic.play();
	while (menuwindow.isOpen()) {
		event_handler(opts_ptr, ngame_ptr);
		menuwindow.clear(sf::Color::Black);
		draw_menu(title_ptr, opts_ptr, ngame_ptr);
		menuwindow.display();
	}
	return (false);
}
