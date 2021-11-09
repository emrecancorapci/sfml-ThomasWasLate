#include "PlayableCharacter.h"

#include <iostream>

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	_position = startPosition;
	_gravity = gravity;
	_sprite.setPosition(_position);
}

void PlayableCharacter::update(float deltaTime)
{
	// Move
	if (_rightPressed)
	{
		_position.x += _speed * deltaTime;
	}

	if (_leftPressed)
	{
		_position.x -= _speed * deltaTime;
	}

	// Jump
	if (_isJumping)
	{
		_lastJumpTime += deltaTime;

		if (_lastJumpTime < _jumpDuration)
		{
			_position.y -= _gravity * 2 * deltaTime;
		}
		else
		{
			_isJumping = false;
			_isFalling = true;
		}
	}

	// Gravity
	if (_isFalling)
	{
		_position.y += _gravity * deltaTime;
	}

	FloatRect r = getPosition();

	// Feet
	_feet = FloatRect(
		r.left + 3,
		r.top + r.height - 1,
		r.width - 6,
		1);

	// Head
	_head = FloatRect(
		r.left,
		r.top + (r.height * .3f),
		r.width,
		1);

	// Right
	_right = FloatRect(
		r.left + r.width -2,
		r.top + r.height * .35f,
		1,
		r.height * .3f);

	// Left
	_left = FloatRect(
		r.left,
		r.top + r.height * .5,
		1,
		r.height * .3);

	_sprite.setPosition(_position);
}

FloatRect PlayableCharacter::getPosition()
{
	return _sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return _position +Vector2f(_sprite.getGlobalBounds().width / 2,
							   _sprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet()
{
	return _feet;
}

FloatRect PlayableCharacter::getHead()
{
	return _head;
}

FloatRect PlayableCharacter::getLeft()
{
	return _left;
}

FloatRect PlayableCharacter::getRight()
{
	return _right;
}

Sprite PlayableCharacter::getSprite()
{
	return _sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	_position.y = position - getPosition().height;
	_sprite.setPosition(_position);
	_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	_position.x = position - getPosition().height;
	_sprite.setPosition(_position);
	_isFalling = false;
}

void PlayableCharacter::stopLeft(float position)
{
	_position.x = position - _sprite.getGlobalBounds().width;
	_sprite.setPosition(_position);
}

void PlayableCharacter::stopJump()
{
	_isJumping = false;
	_isFalling = true;
}
