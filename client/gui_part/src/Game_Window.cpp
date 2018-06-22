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

void	GameWindow::setgamesound()
{

}

void 	DrawTile(sf::Vector2f pos)
{
	sf::Vector2f tile_size  = sf::Vector2f(40, 40);
	sf::RectangleShape the_tile(tile_size);
	the_tile.setFillColor(sf::Color::Blue);
	the_tile.setOutlineThickness(3);
	the_tile.setOutlineColor(sf::Color::Black);
	the_tile.setPosition(pos);
	gamewindow.draw(the_tile);
}

void 	DrawBoard(int x_size, int y_size)
{
	int ypos = 0;
	int xpos = 0;
	// sf::RectangleShape bg(sf::Vector2f(gamewindow.getSize().x - 100,
	// 	gamewindow.getSize().y - 100));

	for (int i = 0; i < y_size; ++i) {
		ypos = (gamewindow.getSize().y / 2) - ((y_size * 40) / 2 - (i  * 40));
		for (int j = 0; j < x_size; ++j) {
			xpos = (gamewindow.getSize().x / 2) - ((x_size * 40) / 2  - (j * 40));
			DrawTile(sf::Vector2f(xpos, ypos));
		}
	}

}

bool	GameWindow::start_me(int x_mapsize, int y_mapsize)
{
	gamewindow.create(sf::VideoMode(1920, 1080), "DA G4M3");
	gamewindow.setFramerateLimit(60);
	// gamemusic.play();
	gamewindow.setSize(sf::Vector2u(1920,1080));

	while (gamewindow.isOpen()) {
		 sf::Event event;
		while (gamewindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)) {
				gamewindow.close();
			}
			gamewindow.clear(sf::Color::Black);
			DrawBoard(x_mapsize, y_mapsize);
			gamewindow.display();
		}
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
		gm.start_me(x, y);
	} else {
		fprintf(stderr, "Usage %s int x, int y\t(map size)\n", av[0]);
	}
	return (x < 1 ? 0 : 84);
}
#endif
