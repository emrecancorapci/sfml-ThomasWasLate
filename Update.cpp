#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

void Engine::update(float deltaTimeAsSec)
{
	if(_playing)
	{
		_timeRemaining -= deltaTimeAsSec;

		if (_timeRemaining <= 0)
		{
			_newLevelRequired = true;
		}
	}
}
