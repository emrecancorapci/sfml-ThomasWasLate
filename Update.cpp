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

		loadLevel();
	}

	if(_playing)
	{
		// Update characters
		_thomas.update(deltaTimeAsSec);
		_bob.update(deltaTimeAsSec);

		// Collision Detection
		if(detectCollisions(_thomas) && detectCollisions(_bob))
		{
			_newLevelRequired = true;
			_soundManager.playReachGoal();
		}
		else
			detectCollisions(_bob);

		// Jump on each other
		if(_bob.getFeet().intersects(_thomas.getHead()))
			_bob.stopFalling(_thomas.getHead().top);
		if(_thomas.getFeet().intersects(_bob.getHead()))
			_thomas.stopFalling(_bob.getHead().top);

		// Countdown Timer
		_timeRemaining -= deltaTimeAsSec;

		// Timeout
		if (_timeRemaining <= 0)
			_newLevelRequired = true;
	}

	// vector<Vector2f>::iterator it; //512

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
