#include "RadioButton.h"

RadioButton::RadioButton(const std::string & textIn, Widget * parent, sf::Vector2f & positionIn, 
	std::vector<RadioButton *> & radGroup, int characterSize, float boxWidth, float boxHeight) 
		: Label(textIn, parent, characterSize), m_otherButtons(radGroup)
{
	widgetPos = positionIn;
	m_box.setPosition(widgetPos);
	m_box.setSize(sf::Vector2f(boxWidth, boxHeight));
	m_box.setFillColor(sf::Color::White);
	m_box.setOutlineColor(sf::Color::White);
	m_box.setOutlineThickness(3.f);
	sf::Vector2f textOffset(widgetPos.x + m_box.getGlobalBounds().width / 2.f, widgetPos.y - m_box.getGlobalBounds().height / 2.f);
	Label::setPosition(textOffset);
}

bool RadioButton::processInput(XboxController & controller)
{
	if (!m_hasFocus)
	{
		m_box.setOutlineColor(sf::Color::Cyan);
		return false;
	}
	else
	{
		m_box.setOutlineColor(sf::Color::Magenta);
	}
	if (controller.isButtonPressed(XBOX360_UP)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_up != nullptr)
		{
			m_up->promoteFocus();
			demoteFocus();
			return true;
		}
	}
	else if (controller.isButtonPressed(XBOX360_DOWN)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_down != nullptr)
		{
			m_down->promoteFocus();
			demoteFocus();
			return true;
		}
	}
	else if (controller.isButtonPressed(XBOX360_LEFT)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_left != nullptr)
		{
			m_left->promoteFocus();
			demoteFocus();
			return true;
		}
	}
	else if (controller.isButtonPressed(XBOX360_RIGHT)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_right != nullptr)
		{
			m_right->promoteFocus();
			demoteFocus();
			return true;
		}
	}
	else if (controller.isButtonPressed(XBOX360_A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		for (RadioButton * radioButton : m_otherButtons)
		{
			radioButton->deActivate();
		}
		m_state = true;
		m_box.setFillColor(sf::Color::Blue);
	}
}

void RadioButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_box);
	Label::draw(target, states);
}

void RadioButton::add(RadioButton * radioButtonIn)
{
	m_otherButtons.push_back(radioButtonIn);
}

void RadioButton::deActivate()
{
	m_box.setFillColor(sf::Color::White);
	m_state = false;
}

bool RadioButton::getState()
{
	return m_state;
}