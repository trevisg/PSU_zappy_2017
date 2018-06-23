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
	// if (!gamemusic.openFromFile("assets/musics/game-bg.ogg")) {
	// 	fprintf(stderr, "Failed to load game music\n");
	// }
}

void	GameWindow::_setgame_sound()
{

}

void 	DrawTile(sf::Vector2f pos, sf::Vector2f tile_size)
{
	sf::RectangleShape the_tile(tile_size);

	sf::Color outline(155,89,182 ,1);
	sf::Color fillcolor(103,58,183);

	the_tile.setFillColor(fillcolor);
	the_tile.setOutlineThickness(3);
	the_tile.setOutlineColor(sf::Color::Black);
	the_tile.setPosition(pos);
	gamewindow.draw(the_tile);
}

void 	DrawBoard(int x_size, int y_size)
{
	int ypos = 0;
	int xpos = 0;
	sf::Vector2f tile_size =  sf::Vector2f(40, 40);

	for (int i = 0; i < y_size; ++i) {
		ypos = (gamewindow.getSize().y / 2) - ((y_size * 40) / 2 - (i  * 40));
		for (int j = 0; j < x_size; ++j) {
			xpos = (gamewindow.getSize().x / 2) - ((x_size * 40) / 2  - (j * 40));
			DrawTile(sf::Vector2f(xpos, ypos), tile_size);
		}
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
	} else if (event.type == sf::Event::Resized) {
		sf::FloatRect visibleArea(0, 0, event.size.width,
						event.size.height);
		gamewindow.setView(sf::View(visibleArea));
	}
}

void 	GameWindow::_set_bg()
{
	float ScaleX;
	float ScaleY;

	if (!_bg_texture.loadFromFile("assets/textures/gamebg.jpg")) {
		fprintf(stderr, "Error loadding background\n");
	}
	ScaleX = (float) gamewindow.getSize().x / _bg_texture.getSize().x;
	ScaleY = (float) gamewindow.getSize().y / _bg_texture.getSize().y;
	_bg_texture.setSmooth(true);
	_bg_sprite.setTexture(_bg_texture);
 	_bg_sprite.setScale(ScaleX, ScaleY);
}

bool	GameWindow::_start_me(int x_mapsize, int y_mapsize)
{
	sf::Vector2u win_size(700, 800);
	sf::VideoMode win_mode(win_size.x, win_size.y);

	gamewindow.create(win_mode, "PSU_zappy_2017");
	gamewindow.setFramerateLimit(60);
	gamewindow.setSize(win_size);
	// _set_bg();

	while (gamewindow.isOpen()) {
		 sf::Event event;
		while (gamewindow.pollEvent(event)) {
			_event_handler(event);
		}
		gamewindow.clear(sf::Color::Black);
		// gamewindow.draw(_bg_sprite);
		DrawBoard(x_mapsize, y_mapsize);
		gamewindow.display();
	}
	return (false);
}

#ifdef TESTGAME
int main(int ac, char **av)
{
	GameWindow 	gm;
	int		x;
	int		y;

	if (ac >= 2 && (x = atoi(av[1])) > 0 && (y = atoi(av[1])) > 0) {
		gm._start_me(x, y);
	} else {
		fprintf(stderr, "Usage %s int x, int y\t(map size)\n", av[0]);
	}
	return (x < 1 ? 0 : 84);
}
#endif
