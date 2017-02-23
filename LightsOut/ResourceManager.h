/// <summary>
/// @author Darren Sweeney
/// @version 1.0
/// </summary>

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

/// Loads all game assets
/// 
/// Loads game assets that are used in the game and provides
/// a method to return a pointer to the location in memory 
/// it's loaded
class ResourceManager
{
public:
	ResourceManager();

	sf::Font* getGameFont();
	sf::Texture* getStudioTexture();
	sf::Texture* getBackgroundTexture();
	sf::SoundBuffer* getBackingTrackBuffer();
	sf::SoundBuffer* getSelectSoundBuffer();

private:
	// The font used in our game Lights Out.
	sf::Font m_gameFont;
	sf::Texture m_studioLogo;
	sf::Texture m_backgroundTexture;
	sf::SoundBuffer backingSoundBuffer;
	sf::SoundBuffer selectSoundBuffer;
};

extern ResourceManager g_resourceMgr;

#endif