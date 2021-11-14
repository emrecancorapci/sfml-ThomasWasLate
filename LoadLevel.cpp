#include "Engine.h"

void Engine::loadLevel()
{
	_playing = false;

	// Delete  previous
	for (int i = 0; i < _levelManager.getLevelSize().y; ++i)
		delete[] _arrayLevel[i];

	_arrayLevel = _levelManager.nextLevel(_vertexLevel);
	_timeRemaining = _levelManager.getTimeLimit();

	_thomas.spawn(_levelManager.getStartPosition(), GRAVITY);
	_bob.spawn(_levelManager.getStartPosition(), GRAVITY);

	_newLevelRequired = false;
}
