#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector <Vector2f>& soundEmittersVector,
	int** arrayLevel)
{
	soundEmittersVector.empty();

	FloatRect previousEmitter;

	// Prevents emitters spawn close
	for(int x = 0; x < (int)_levelManager.getLevelSize().x; x++)
	{
		for(int y = 0; y < (int)_levelManager.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2 &&
				!FloatRect(
					x * TILE_SIZE,
					y * TILE_SIZE,
					TILE_SIZE,
					TILE_SIZE).intersects(previousEmitter))
			{
				soundEmittersVector.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

				int range = 6;

				previousEmitter = FloatRect(
					x * TILE_SIZE,
					y * TILE_SIZE,
					TILE_SIZE * range,
					TILE_SIZE * range);
			}
		}
	}
}