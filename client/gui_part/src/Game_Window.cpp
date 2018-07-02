//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Game window methods
//


#include "../include/Game_Window.hpp"
#include <iostream>

sf::RenderWindow gamewindow;

GameWindow::GameWindow()
{
	std::string server_host = std::string("127.0.0.1");
	std::string server_port = std::string("2222");

	_client.connect_to(server_host, server_port) ?
	std::cerr << "Successfully connected to "
	<< server_host << ":" << server_port << "\n" :
	std::cerr << "Error connection to graph API\n";

	if (!_font.loadFromFile("assets/fonts/elasis.ttf")) {
		std::cerr << "Failed to load font\n";
		exit(EXIT_FAILURE);
	}
	_titletext.setFont(_font);
	_titletext.setCharacterSize(20);
	_titletext.setFillColor(sf::Color::Red);
	_titletext.setStyle(sf::Text::Bold | sf::Text::Underlined);
	_titletext.setString("Trantor Map");
	_titletext.setPosition(800, 0);
}

void	GameWindow::_setgame_sound()
{

}

void	DrawTrantorian(sf::Vector2f pos, sf::Vector2f tile_size)
{
	sf::RectangleShape	the_player(tile_size);
	sf::Texture		player_texture;

	if (!player_texture.loadFromFile("assets/textures/trantorian.png")) {
		fprintf(stderr, "Failed to load player texture\n");
		gamewindow.close();
	}
	sf::Color outline(155,89,182 ,1);
	sf::Color fillcolor(103,58,183);
	the_player.setFillColor(fillcolor);
	the_player.setOutlineThickness(3);
	the_player.setOutlineColor(sf::Color::Black);
	the_player.setPosition(pos);
	the_player.setTexture(&player_texture);
	gamewindow.draw(the_player);
}

void 	DrawTile(sf::Vector2f pos, sf::Vector2f tile_size)
{
	sf::RectangleShape the_tile(tile_size);
	sf::Texture 	   tile_texture;
	sf::Color outline(155,89,182 ,1);
	// sf::Color fillcolor(103,58,183);

	tile_texture.loadFromFile("assets/textures/moon.jpeg");
	the_tile.setTexture(&tile_texture);
	// the_tile.setFillColor(fillcolor);
	the_tile.setOutlineThickness(3);
	the_tile.setOutlineColor(sf::Color::Black);
	the_tile.setPosition(pos);
	gamewindow.draw(the_tile);
}

bool 	GameWindow::_is_there_a_player_here(int y, int x)
{
	bool rt = false;
	if (_team_details.size()) {
		for (uint i = 1; i != _team_details.size(); ++i) {
			if (std::stoi(_team_details[i]["x"]) == x
			&& std::stoi(_team_details[i]["y"]) == y) {
				rt = true;
				break;
			}
		}
	}
	return(rt);
}

void 	GameWindow::_DrawBoard(int x_size, int y_size)
{
	sf::Vector2f pos;
	sf::Vector2f tile_size =  sf::Vector2f(40, 40);

	for (int i = 0; i < y_size; ++i) {
		pos.y = (gamewindow.getSize().y / 2)
		- ((y_size * 40) / 2 - (i  * 40));
		for (int j = 0; j < x_size; ++j) {
			pos.x = (gamewindow.getSize().x / 2)
			- ((x_size * 40) / 2  - (j * 40));
			DrawTile(pos, tile_size);
			if (_is_there_a_player_here(i, j)) {
				DrawTrantorian(pos, tile_size);
			}
		}

	}

}

sf::Text	GameWindow::_init_text(std::string team_name)
{
	sf::Text team_text;
	sf::Font font;

	if (!font.loadFromFile("assets/fonts/elasis.ttf")) {
		std::cerr << "Failed to load font\n";
		exit(EXIT_FAILURE);
	}
	team_text.setFont(font);
	team_text.setString(team_name);
	team_text.setCharacterSize(20);
	team_text.setFillColor(sf::Color::White);
	return (team_text);

}

void	GameWindow::_set_team_names()
{
	_teams_names = _client.get_teamnames();
}

sf::Vector2u 	GameWindow::_set_map_size()
{
	sf::Vector2u rt;
	std::map<std::string, std::string> resp = _client.get_map_size();
	if (resp.find("x") != resp.end()
	&& resp.find("y") != resp.end()) {
		rt.x = std::stoi(resp["x"]);
		rt.y = std::stoi(resp["y"]);
	} else {
		rt.x = 0;
		rt.y = 0;
	}
	return (rt);
}

void	GameWindow::_set_team_details()
{
	if (_teams_names.size()) {
		_team_details = _client.get_team_details(_teams_names[0]);
		std::cerr << "Received team "
		<< _team_details[0]["teamname"] << " Informations\n";
			std::cerr << _team_details.size() <<"\n";
	}
}

void	GameWindow::_event_handler(sf::Event event)
{
	if (event.type == sf::Event::Closed ||
	(event.type == sf::Event::KeyPressed &&
	event.key.code == sf::Keyboard::Escape)) {
		gamewindow.close();
	} else if (event.type == sf::Event::KeyPressed &&
	event.key.code == sf::Keyboard::Up) {
		std::cout << "Up key pressed\n";
		_set_team_names();
	} else if (event.type == sf::Event::KeyPressed &&
	event.key.code == sf::Keyboard::Down) {
		std::cout << "Down key pressed\n";
		_set_team_details();
	} else if (event.type == sf::Event::Resized) {
		sf::FloatRect visibleArea(0, 0, event.size.width,
						event.size.height);
		gamewindow.setView(sf::View(visibleArea));
	}
}

void 	GameWindow::_DrawTeams(std::vector<std::string> _teams_names)
{
	sf::Text text;
	sf::Font font;

	if (!font.loadFromFile("assets/fonts/elasis.ttf")) {
		std::cerr << "Failed to load font\n";
		exit(EXIT_FAILURE);
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setString("Teams :");
	gamewindow.draw(text);
	text.setFillColor(sf::Color::White);
	text.setString(_teams_names[0]);
	text.setCharacterSize(20);
	text.setPosition(20, 70);
	gamewindow.draw(text);
	text.setCharacterSize(15);
	for (uint k = 1; k != _team_details.size(); ++k) {
		text.setString("X : " + _team_details[k]["x"]);
		text.setPosition((k * 100), 130);
		gamewindow.draw(text);
		text.setString("Y : " + _team_details[k]["y"]);
		text.setPosition((k * 100), 230);
		gamewindow.draw(text);
		text.setString("$:" + _team_details[k]["ttl"]);
		text.setPosition((k * 100), 330);
		gamewindow.draw(text);
	}
}

bool	GameWindow::_start_me()
{
	sf::Vector2u win_size(700, 800);
	sf::VideoMode win_mode(win_size.x, win_size.y);

	gamewindow.create(win_mode, "PSU_zappy_2017");
	gamewindow.setFramerateLimit(60);
	gamewindow.setSize(win_size);
	sf::Vector2u map_size = _set_map_size();
	while (gamewindow.isOpen()) {
		 sf::Event event;
		while (gamewindow.pollEvent(event)) {
			_event_handler(event);
		}
		gamewindow.clear(sf::Color::Black);
		gamewindow.draw(_titletext);
		if ( map_size.x && map_size.y){
			_DrawBoard(map_size.x, map_size.y);
		}
		if (_teams_names.size() && _team_details.size()) {
			_DrawTeams(_teams_names);
		}
		gamewindow.display();
	}
	return (false);
}

#ifdef TESTGAME
int main(void)
{
	GameWindow 	gw;

	gw._start_me();
	return (0);
}
#endif
