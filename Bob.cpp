#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	_sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	_jumpDuration = .25f;
}

bool Bob::handleInput()
{
	_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
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

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		_leftPressed = true;
	}
	else
	{
		_leftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		_rightPressed = true;
	}
	else
	{
		_rightPressed = false;
	}

	return _justJumped;
}

