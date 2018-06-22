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

void 	DrawTile(sf::RectangleShape *bg, sf::Vector2f pos)
{
	if (bg && pos.x) {
		sf::Vector2f tile_size  = sf::Vector2f(20, 20);
		sf::RectangleShape the_tile(tile_size);
		the_tile.setFillColor(sf::Color::Blue);
		the_tile.setOutlineThickness(5);
		the_tile.setOutlineColor(sf::Color::Black);
		the_tile.setPosition(20, 20);
		gamewindow.draw(the_tile);
	}
}

void 	DrawBoard(int x_size, int y_size)
{
	sf::RectangleShape bg(sf::Vector2f(gamewindow.getSize().x - 100,
		gamewindow.getSize().y - 100));
	sf::RectangleShape *bg_ptr = &bg;


	for (int i = 0; i < y_size; ++i) {
		for (int j = 0; j < x_size; ++j) {
			DrawTile(bg_ptr, sf::Vector2f(i, j));
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
		gm.start_me(atoi(av[1]), atoi(av[2]));
	} else {
		fprintf(stderr, "Usage %s int x, int y\t(map size)\n", av[0]);
	}
	return (x < 1 ? 0 : 84);
}
#endif
