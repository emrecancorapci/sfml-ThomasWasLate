#include "Thomas.h"

#include <iostream>

#include "TextureHolder.h"

Thomas::Thomas()
{
	_sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	_jumpDuration = .45f;
}

inline bool Thomas::handleInput()
{
	_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		// Jump if not jumping
		if (!_isJumping && !_isFalling)
		{
			_isJumping = true;
			_lastJumpTime = 0;
			_justJumped = true;
		}
	}
	else
	{
		_isJumping = false;
		_isFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		std::cout << "A Pressed" << std::endl;
		_leftPressed = true;
	}
	else
	{
		_leftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		std::cout << "D Pressed" << std::endl;
		_rightPressed = true;
	}
	else
	{
		_rightPressed = false;
	}

	return _justJumped;
}