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

bool	GameWindow::start_me()
{
	gamewindow.create(sf::VideoMode(1920, 1080), "DA G4M3");
	gamewindow.setFramerateLimit(60);
	// gamemusic.play();
	while (gamewindow.isOpen()) {
		 sf::Event event;
		while (gamewindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape)) {
				gamewindow.close();
			}
		}
	}
	return (false);
}
