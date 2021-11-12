#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class LevelManager
{
private:
	Vector2i _levelSize;
	Vector2f _startPosition;
	float _timeModifier = 1;
	float _baseTimeLimit = 0;
	int _currentLevel = 0;
	const int NUM_LEVELS = 4;
public:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float getTimeLimit();
	Vector2f getStartPosition();
	int** nextLevel(VertexArray& LevelArray);
	Vector2i getLevelSize();
	int getCurrentLevel();
};

