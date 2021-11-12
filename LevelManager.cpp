#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;
int** LevelManager::nextLevel(VertexArray& LevelArray)
{
	_levelSize = Vector2i(0,0);

	_currentLevel++;
	if (_currentLevel > NUM_LEVELS)
	{
		_currentLevel = 1;
		_timeModifier -= .1f;
	}

	stringstream levelToLoad;
	levelToLoad << "levels/level" << _currentLevel << ".txt";
	switch (_currentLevel)
	{
	case 1:
		_startPosition = Vector2f(100,100);
		_baseTimeLimit = 30.0f;
		break;
	case 2:
		_startPosition = Vector2f(100,3600);
		_baseTimeLimit = 100.0f;
		break;
	case 3:
		_startPosition = Vector2f(1250,0);
		_baseTimeLimit = 30.0f;
		break;
	case 4:
		_startPosition = Vector2f(50,200);
		_baseTimeLimit = 50.0f;
		break;
	}

	// 2 - Get size of file

	ifstream inputFile(levelToLoad.str());
	string s;

	while(getline(inputFile,s))
	{
		++_levelSize.y;
	}
	_levelSize.x = s.length();

	// 3 - Create an empty array

	inputFile.clear();

	// Move file cursor to the beginning of the file
	inputFile.seekg(0, ios::beg);

	// Create array
	int** arrayLevel = new int*[_levelSize.y];

	for (int i = 0; i < _levelSize.y; ++i)
	{
		arrayLevel[i] = new int[_levelSize.x];
	}

	// 4 - Fill the array with data from the file

	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}
		y++;
	}

	inputFile.close();

	// 5
	LevelArray.setPrimitiveType(Quads);
	LevelArray.resize(_levelSize.x * _levelSize.y * VERTS_IN_QUAD);
	int currentVertex = 0;
	for (int x = 0; x < _levelSize.x; x++)
	{
		for (int y = 0; y < _levelSize.y; y++)
		{
			// Vertex positions in the quad
			LevelArray[currentVertex].position = Vector2f(
				x * TILE_SIZE,
				y * TILE_SIZE);
			LevelArray[currentVertex + 1].position = Vector2f(
				(x+1) * TILE_SIZE,
				y * TILE_SIZE);
			LevelArray[currentVertex + 2].position = Vector2f(
				(x+1) * TILE_SIZE,
				(y+1) * TILE_SIZE);
			LevelArray[currentVertex + 3].position = Vector2f(
				x * TILE_SIZE,
				(y+1) * TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			LevelArray[currentVertex + 0].texCoords = Vector2f(
				0, 
				verticalOffset);
			LevelArray[currentVertex + 1].texCoords = Vector2f(
				TILE_SIZE, 
				verticalOffset);
			LevelArray[currentVertex + 2].texCoords = Vector2f(
				TILE_SIZE, 
				TILE_SIZE + verticalOffset);
			LevelArray[currentVertex + 3].texCoords = Vector2f(
				0, 
				TILE_SIZE + verticalOffset);

			// New positions for next vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return arrayLevel;
}

Vector2i LevelManager::getLevelSize()
{
	return _levelSize;
}
int LevelManager::getCurrentLevel()
{
	return _currentLevel;
}
float LevelManager::getTimeLimit()
{
	return _baseTimeLimit * _timeModifier;
}
Vector2f LevelManager::getStartPosition()
{
	return _startPosition;
}
