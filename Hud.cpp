#include "Hud.h"

Hud::Hud()
{
	//
	const auto resolution = Vector2u(
		VideoMode::getDesktopMode().width,
		VideoMode::getDesktopMode().height);

	_font.loadFromFile("fonts/Roboto-Light.ttf");

	_startText.setFont(_font);
	_startText.setCharacterSize(100);
	_startText.setFillColor(Color::White);
	_startText.setString("Press Enter to Play");

	//
	const FloatRect textRect = _startText.getLocalBounds();

	_startText.setOrigin(
		textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	_startText.setPosition(
		resolution.x / 2.0f, 
		resolution.y / 2.0f);

	_timeText.setFont(_font);
	_timeText.setCharacterSize(75);
	_timeText.setFillColor(Color::White);
	_timeText.setPosition(resolution.x - 150, 0);
	_timeText.setString("-----");

	_levelText.setFont(_font);
	_levelText.setCharacterSize(75);
	_levelText.setFillColor(Color::White);
	_levelText.setPosition(25, 0);
	_levelText.setString("1");
}

Text Hud::getLevel()
{
	return _levelText;
}

Text Hud::getMessage()
{
	return _startText;
}

Text Hud::getTime()
{
	return _timeText;
}

void Hud::setLevel(String text)
{
	_levelText.setString(text);
}

void Hud::setTime(String text)
{
	_timeText.setString(text);
}

