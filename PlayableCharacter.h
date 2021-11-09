#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	Sprite _sprite;

	bool _isJumping;
	bool _isFalling;
	bool _justJumped;

	float _jumpDuration;
	float _lastJumpTime;

	bool _leftPressed;
	bool _rightPressed;

private:
	float _gravity;
	float _speed = 400;

	Vector2f _position;

	FloatRect _feet;
	FloatRect _head;
	FloatRect _right;
	FloatRect _left;

	Texture _texture;

public:
	void spawn(Vector2f startPosition, float gravity);

	bool virtual handleInput() = 0;

	FloatRect getPosition();

	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	Vector2f getCenter();

	void update(float deltaTime);
};

