/// <summary>
/// @author Darren Sweeney and Liam Hickey
/// @version 1.0
/// </summary>

#ifndef QUIT_SCREEN_H
#define QUIT_SCREEN_H

#include <SFML\Graphics.hpp>
#include "Input\XboxController.h"
#include "Gui\Gui.h"
#include "Gui\Button.h"
#include "Gui\Label.h"
#include "Screen.h"
#include <iostream>

class QuitScreen : public Screen
{
public:
	QuitScreen(sf::Color & focusColorIn, sf::Color &noFocusColorIn, sf::Color &fillColorIn, sf::Sound &selectSound);

	void initialise();
	void update(XboxController& controller) override;
	bool getChangeStateMenu();
	bool getExitGameState();
	void reset() override;

private:
	void noButtonSelected();
	void yesButtonSelected();

	Label *m_quitTitle;
	Button *m_yesButton;
	Button *m_noButton;

	bool m_noButtonSelected;
	bool m_yesButtonSelected;
	bool m_changeToMenuState;
	bool m_exitGame;

	bool transitionIn;
	float interpolation;

	sf::Sound &selectSound;
	sf::Color &focusColor;
	sf::Color &noFocusColor;
	sf::Color &fillColor;
};

#endif