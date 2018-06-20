//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Settings methods
//

#include "../include/Menu_Settings.hpp"

MenuSettings::MenuSettings(int xsize, int ysize)
{
	SettingsPos = sf::Vector2f(xsize, ysize);
	SettingsRect = sf::RectangleShape(SettingsPos);
	SettingsRect.setFillColor(sf::Color::Black);
	SettingsRect.setOutlineThickness(10);
	SettingsRect.setOutlineColor(sf::Color::Red);
	if (!SettingsFont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load Settings font\n");
	}
	SettingsText.setFont(SettingsFont);
	SettingsText.setString("Settings :");
	SettingsText.setCharacterSize(20);
	SettingsText.setStyle(sf::Text::Underlined);
	SettingsText.setFillColor(sf::Color::Red);
	SettingsText.setPosition(10, 40);
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
