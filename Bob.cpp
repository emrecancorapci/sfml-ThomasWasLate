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

	_leftPressed = Keyboard::isKeyPressed(Keyboard::Left);
	_rightPressed = Keyboard::isKeyPressed(Keyboard::Right);

	return _justJumped;
}

