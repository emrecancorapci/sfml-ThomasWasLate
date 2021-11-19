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

	// Random fire emitters
	for(auto it = _fireEmitters.begin();
	    it != _fireEmitters.end(); ++it)
	{
		float posX = (*it).x;
		float posY = (*it).y;

		FloatRect localRect(
			posX - 250, 
			posY - 250, 
			500, 
			500);

		if (_thomas.getPosition().intersects(localRect))
		{
			_soundManager.playFire(Vector2f(posY,posY), _thomas.getCenter());
		}
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

	_frameSinceLastHUDUpdate++;
	if (_frameSinceLastHUDUpdate > _targetFramePerHUDUpdate)
	{
		stringstream time;
		stringstream level;

		time << static_cast<int>(_timeRemaining);
		_hud.setTime(time.str());

		level << "Level:" << _levelManager.getCurrentLevel();
		_hud.setLevel(level.str());

		_frameSinceLastHUDUpdate = 0;
	}

	if (_particleSystem.running())
	{
		_particleSystem.update(deltaTimeAsSec);
	}
}
