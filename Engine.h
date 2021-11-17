#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "Hud.h"

using namespace sf;

class Engine
{
private:
	TextureHolder _textureHolder;

	Thomas _thomas;
	Bob _bob;

	enum tile_type {air, ground, lava, water, goal};

	LevelManager _levelManager;
	SoundManager _soundManager;
	Hud _hud;

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

	// Main Functions
	void input();
	void update(float deltaTimeAsSec);
	void draw();

	// Level Load
	void loadLevel();

	// Collision Detection
	bool detectCollisions(PlayableCharacter& character);

	// Sound Emitters
	void populateEmitters(vector <Vector2f>& soundEmittersVector, int** arrayLevel);
	vector <Vector2f> _fireEmitters;

	// Hud
	int _frameSinceLastHUDUpdate = 0;
	int _targetFramePerHUDUpdate = 500;


public:
	Engine();

	void run();
};
