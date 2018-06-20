//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Settings header
//

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
		sf::Vector2f		SettingsPos;
		sf::RectangleShape 	SettingsRect;
		sf::Font		SettingsFont;
		sf::Text 		SettingsText;
		sf::Vector2f		ServerPortSettingsPos;
		sf::RectangleShape 	ServerPortSettingsRect;
		sf::Font		ServerPortFont;
		sf::Text 		ServerPortText;
		sf::String		ServerPortInputString;
		sf::Vector2f		ServerHostSettingsPos;
		sf::RectangleShape 	ServerHostSettingsRect;
		sf::Text 		ServerHostText;
		sf::String		ServerHostInputString;
		sf::Vector2f		HelpSettingsPos;
		sf::RectangleShape 	HelpSettingsRect;
};
