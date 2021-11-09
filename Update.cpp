#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

void Engine::update(float deltaTimeAsSec)
{
	if (_newLevelRequired)
	{
		// Will call loadLevel()

		_thomas.spawn(Vector2f(0,0), GRAVITY);
		_bob.spawn(Vector2f(100,0), GRAVITY);

		_timeRemaining = 10;
		_newLevelRequired = false;
	}

	if(_playing)
	{
		// Update characters
		_thomas.update(deltaTimeAsSec);
		_bob.update(deltaTimeAsSec);

		// Countdown Timer
		_timeRemaining -= deltaTimeAsSec;

		// Timeout
		if (_timeRemaining <= 0)
			_newLevelRequired = true;
	}

	if (_splitScreen)
	{
		// Centers views to characters
		_leftView.setCenter(_thomas.getCenter());
		_rightView.setCenter(_bob.getCenter());
	}
	else
	{
		if (_character1)
			_mainView.setCenter(_thomas.getCenter());
		else
			_mainView.setCenter(_bob.getCenter());
	}
}
