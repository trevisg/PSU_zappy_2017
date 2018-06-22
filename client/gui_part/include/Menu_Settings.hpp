//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Settings header
//

#ifndef MENU_SETTINGS_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	MenuSettings
{
	public:
		MenuSettings(int xsize, int ysize);
		sf::RectangleShape	getOptsRect();
		sf::Text		getOptsText();
		sf::RectangleShape	getServerPortSettingsRect();
		sf::Text		getServerPortSettingsText();
		void			setServerPortSettingsText(sf::Text txt);
		sf::String 		getServerPortSettingsString();
		void			setServerPortSettingsString(sf::String);
		sf::RectangleShape	getServerHostSettingsRect();
		void			setServerHostSettingsText(sf::Text txt);
		sf::Text		getServerHostSettingsText();
		void			setServerHostSettingsString(sf::String);
		sf::String		getServerHostSettingsString();
	private:
		sf::Texture		SettingsTextures;
		sf::Sprite		SettingsSprite;
		sf::Vector2f		SettingsSize;
		sf::RectangleShape 	SettingsRect;
		sf::Font		SettingsFont;
		sf::Text 		SettingsText;
		sf::Vector2f		ServerPortSettingsSize;
		sf::RectangleShape 	ServerPortSettingsRect;
		sf::Font		ServerPortFont;
		sf::Text 		ServerPortText;
		sf::String		ServerPortInputString;
		sf::Vector2f		ServerHostSettingsSize;
		sf::RectangleShape 	ServerHostSettingsRect;
		sf::Text 		ServerHostText;
		sf::String		ServerHostInputString;
		sf::Vector2f		HelpSettingsSize;
		sf::RectangleShape 	HelpSettingsRect;
};

#endif /* !MENU_NEWGAME_HPP_ */
