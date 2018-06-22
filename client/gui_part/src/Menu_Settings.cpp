//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Settings methods
//

#include "../include/Menu_Settings.hpp"

MenuSettings::MenuSettings(int xsize, int ysize)
{
	/** Main settings for Settings rectangle shape on
	* the left side of the menuwindow
	*/
	SettingsSize = sf::Vector2f(xsize, ysize);
	SettingsRect = sf::RectangleShape(SettingsSize);
	SettingsRect.setFillColor(sf::Color::Black);
	SettingsRect.setOutlineThickness(10);
	SettingsRect.setOutlineColor(sf::Color::Blue);
	if (!SettingsFont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load Settings font\n");
	}
	SettingsText.setFont(SettingsFont);
	SettingsText.setString("Settings :");
	SettingsText.setCharacterSize(20);
	SettingsText.setStyle(sf::Text::Underlined);
	SettingsText.setFillColor(sf::Color::Red);
	SettingsText.setPosition(10, 40);
	/** Main settings for Host user input rectangle shape on
	* the left side of the menuwindow
	*/
	ServerHostSettingsSize = sf::Vector2f(100, 20);
	ServerHostSettingsRect = sf::RectangleShape(ServerHostSettingsSize);
	ServerHostSettingsRect.setFillColor(sf::Color::White);
	ServerHostSettingsRect.setOutlineThickness(5);
	ServerHostSettingsRect.setOutlineColor(sf::Color::Red);
	ServerHostSettingsRect.setPosition(20, 100);
	/** Main settings for Port user input rectangle shape on
	* the left side of the menuwindow
	*/
	ServerPortSettingsSize = sf::Vector2f(100, 20);
	ServerPortSettingsRect = sf::RectangleShape(ServerHostSettingsSize);
	ServerPortSettingsRect.setFillColor(sf::Color::White);
	ServerPortSettingsRect.setOutlineThickness(5);
	ServerPortSettingsRect.setOutlineColor(sf::Color::Red);
	ServerPortSettingsRect.setPosition(20, 160);
}

sf::RectangleShape	MenuSettings::getOptsRect()
{
	return (SettingsRect);
}

sf::Text 		MenuSettings::getOptsText()
{
	return (SettingsText);
}

sf::RectangleShape	MenuSettings::getServerPortSettingsRect()
{
	return (ServerPortSettingsRect);
}

sf::Text		MenuSettings::getServerPortSettingsText()
{
	return (ServerPortText);
}


sf::RectangleShape	MenuSettings::getServerHostSettingsRect()
{
	return (ServerHostSettingsRect);
}

sf::Text		MenuSettings::getServerHostSettingsText()
{
	return (ServerHostText);
}

void			MenuSettings::setServerHostSettingsString(sf::String i)
{
	ServerHostInputString = i;
}
