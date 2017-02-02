#include "Slider.h"

/// <summary>
/// Constructor function for the slider class
/// </summary>
/// <param name="text">Text to be displayed by the inherited Label</param>
/// <param name="parent">parent widget for the class</param>
/// <param name="position">position of the slider</param>
/// <param name="characterSize">Size of the font used for drawing the text</param>
/// <param name="sliderWidth">Width of the slider</param>
/// <param name="sliderHeight">Height of the slider</param>
Slider::Slider(const std::string& text, Widget* parent, sf::Vector2f &position,
	int characterSize, float sliderWidth, float sliderHeight)
	: Label(text, parent, characterSize), m_barBaseWidth(sliderWidth), m_barSize(m_barBaseWidth), m_barBaseHeight(sliderHeight)
{
	widgetPos = position;

	// Base under the moving slider bar
	m_base.setSize(sf::Vector2f(m_barBaseWidth, m_barBaseHeight));
	m_base.setOutlineColor(sf::Color::Red);
	m_base.setFillColor(sf::Color::Blue);
	m_base.setOutlineThickness(2);
	m_base.setPosition(widgetPos);

	// The slider bar the player changes
	m_bar.setSize(sf::Vector2f(m_barSize, m_barBaseHeight));
	m_bar.setOutlineColor(sf::Color::Red);
	m_bar.setPosition(widgetPos);

	Label::setPosition(position - sf::Vector2f(0.0f, 30.0f));
}

/// <summary>
/// Processes the input from a controller / keyboard and updates the CheckBox as well as other widgets
/// </summary>
/// <param name="controller">Controller object used for checking input</param>
/// <returns>Bool to tell whether the input was used or not</returns>
bool Slider::processInput(XboxController &controller)
{
	if (!m_hasFocus)
	{
		m_base.setOutlineColor(sf::Color::Cyan); // Set the outline color to Cyan if the Widget is out of focus
		return false;
	}
	if (m_hasFocus)
	{
		m_base.setOutlineColor(sf::Color::Magenta); // Otherwise set the color to Magenta
		if (controller.isButtonHeldDown(XBOX360_RIGHT) // Right input
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(m_barSize < m_barBaseWidth)
				m_barSize += 1.0f; // Increase the bar size
			increase(); // Call the associated callback function
			m_bar.setSize(sf::Vector2f(m_barSize, m_barBaseHeight)); // Set the new size of the bar
			return true;
		}
		else if (controller.isButtonHeldDown(XBOX360_LEFT) // Left input
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (m_barSize > 0)
				m_barSize -= 1.0f; // Decrease the bar size
			decrease(); // Call the associtaed callback function
			m_bar.setSize(sf::Vector2f(m_barSize, m_barBaseHeight)); // Set the new size of the bar
			return true;
		}
		else if (controller.isButtonPressed(XBOX360_UP)  // Up input
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (m_up != nullptr)
			{
				m_up->promoteFocus(); // Set the button above *this to be in focus
				demoteFocus(); // Set the slider to be out of focus
				return true;
			}
		}
		else if (controller.isButtonPressed(XBOX360_DOWN) // Down input (See up input)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (m_down != nullptr)
			{
				m_down->promoteFocus();
				demoteFocus();
				return true;
			}
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void Slider::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// Call the super class overridden draw function.
	Label::draw(target, states);

	// Draw the slider.
	target.draw(m_base);
	target.draw(m_bar, states);
}