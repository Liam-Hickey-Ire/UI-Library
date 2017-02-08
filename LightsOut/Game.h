/// <summary>
/// @author Darren Sweeney and Liam Hickey
/// @version 1.0
/// </summary>

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "ResourceManager.h"
#include "MainMenuScreen.h"
#include "OpitionsScreen.h"
#include "QuitScreen.h"
#include "GamePlay.h"

class Game
{
public:
	Game();
	void run();

protected:
	void update(double dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);

	sf::RenderWindow m_window;

	enum class GameState
	{
		MainMenu,
		Options,
		Quit,
		GamePlay
	};
	GameState currentGameState = GameState::MainMenu;

	XboxController xboxController;
	
	MainMenuScreen mainMenuScreen;
	OptionsScreen optionsScreen;
	QuitScreen quiteScreen;
	GamePlay gamePlayScreen;

	sf::Sound m_backingTrack;
};

#endif