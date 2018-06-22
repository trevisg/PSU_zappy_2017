//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Game window methods
//


#include "../include/Game_Window.hpp"

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
	if (bg) {
		sf::Vector2f tile_size  = sf::Vector2f(20, 20);
		sf::RectangleShape the_tile(tile_size);
		the_tile.setFillColor(sf::Color::Blue);
		the_tile.setOutlineThickness(5);
		the_tile.setOutlineColor(sf::Color::Black);
		the_tile.setPosition(pos.x + 10, pos.y + 20);
		gamewindow.draw(the_tile);
	}
}

void 	DrawBoard(int x_size, int y_size)
{
	sf::RectangleShape bg(sf::Vector2f(1920, 1080));
	sf::RectangleShape *bg_ptr = &bg;


	for (int i = 0; i < y_size; ++i) {
		for (int j = 0; j < x_size; ++j) {
			DrawTile(bg_ptr, sf::Vector2f(i, j));
		}
	}

}

bool	GameWindow::start_me()
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
			// DrawBoard(10,10);
			gamewindow.display();
		}
	}
	return (false);
}
