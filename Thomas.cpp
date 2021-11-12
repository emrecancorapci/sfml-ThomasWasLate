#include "Thomas.h"
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

	_leftPressed = Keyboard::isKeyPressed(Keyboard::A);
	_rightPressed = Keyboard::isKeyPressed(Keyboard::D);

	return _justJumped;
}