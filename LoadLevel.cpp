#include "Engine.h"

void Engine::loadLevel()
{
	_playing = false;

	// Delete  previous level
	for (int i = 0; i < _levelManager.getLevelSize().y; ++i)
		delete[] _arrayLevel[i];

	// Load new level array
	_arrayLevel = _levelManager.nextLevel(_vertexLevel);

	// Sound emitters
	populateEmitters(_fireEmitters, _arrayLevel);

	_timeRemaining = _levelManager.getTimeLimit();

	// Spawn characters
	_thomas.spawn(_levelManager.getStartPosition(), GRAVITY);
	_bob.spawn(_levelManager.getStartPosition(), GRAVITY);

	_newLevelRequired = false;
}
