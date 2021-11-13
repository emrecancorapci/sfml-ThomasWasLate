#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"

using namespace sf;

class Engine
{
private:
	TextureHolder textureHolder;

	Thomas _thomas;
	Bob _bob;

	enum tile_type {air, ground, lava, water, goal};

	LevelManager _levelManager;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	RenderWindow _window;

	// Main view
	View _mainView;
	View _leftView;
	View _rightView;

	// Background view
	View _bg_mainView;
	View _bg_leftView;
	View _bg_rightView;

	// Hud view
	View _hudView;

	// Sprite and Texture
	Sprite _backgroundSprite;
	Texture _backgroundTexture;

	// View settings
	bool _playing = false;
	bool _character1 = true;
	bool _splitScreen = false;

	// Time
	float _timeRemaining = 10;
	Time _gameTimeTotal;
	bool _newLevelRequired = true;

	// Level Tiles
	VertexArray _vertexLevel;
	int** _arrayLevel;
	Texture _textureTiles;

	void input();
	void update(float deltaTimeAsSec);
	void draw();
	void loadLevel();

	// Collision Detection
	bool detectCollisions(PlayableCharacter& character);

public:
	Engine();

	void run();
};
