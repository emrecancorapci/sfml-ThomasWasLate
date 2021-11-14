#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	FloatRect detectionZone = character.getPosition();
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Zone around thomas
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// Limit below zero
	startX = startX < 0 ? 0 : startX;                                               
	startY = startY < 0 ? 0 : startY;
	if (endX >= _levelManager.getLevelSize().x)
		endX = _levelManager.getLevelSize().x;
	if (endY >= _levelManager.getLevelSize().y)
		endY = _levelManager.getLevelSize().y;

	// Out of map
	FloatRect level(
		0,
		0,
		_levelManager.getLevelSize().x * TILE_SIZE,
		_levelManager.getLevelSize().y * TILE_SIZE);

	if(!character.getPosition().intersects(level))
		character.spawn(_levelManager.getStartPosition(), GRAVITY);

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Start Position
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Collided with...
			if(_arrayLevel[y][x] == lava || _arrayLevel[y][x] == water)
			{
				if(character.getHead().intersects(block))
				{
					character.spawn(_levelManager.getStartPosition(), GRAVITY);

					// Sound
					if (_arrayLevel[y][x] == lava)
					{
						// Lava sound
					}
					else
					{
						// Water sound
					}
				}
			}
			if(_arrayLevel[y][x] == ground)
			{
				if(character.getRight().intersects(block))
					character.stopRight(block.left);
				else if(character.getLeft().intersects(block))
					character.stopLeft(block.left);
				if(character.getFeet().intersects(block))
					character.stopFalling(block.top);
				else if(character.getHead().intersects(block))
					character.stopJump();
			}
			if(_arrayLevel[y][x] == goal)
				reachedGoal = true;
		}
	}
	return reachedGoal;
}
