#include "Engine.h"

void Engine::draw()
{
	_window.clear(Color::Black);

	_rippleShader.setUniform("uTime",
		_gameTimeTotal.asSeconds());

	if (!_splitScreen)
	{
		_window.setView(_bg_mainView);
		_window.draw(_backgroundSprite);
		_window.draw(_backgroundSprite, &_rippleShader);

		_window.setView(_mainView);
		_window.draw(_vertexLevel, &_textureTiles);

		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());

		if (_particleSystem.running())
		{
			_window.draw(_particleSystem);
		}
	}
	else
	{
		// If split-screen
		// Left View
		_window.setView(_bg_leftView);
		_window.draw(_backgroundSprite);
		_window.draw(_backgroundSprite, &_rippleShader);

		_window.setView(_leftView);
		_window.draw(_vertexLevel, &_textureTiles);

		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());

		if (_particleSystem.running())
		{
			_window.draw(_particleSystem);
		}

		// Right View
		_window.setView(_bg_rightView);
		_window.draw(_backgroundSprite);
		_window.draw(_backgroundSprite, &_rippleShader);

		_window.setView(_rightView);
		_window.draw(_vertexLevel, &_textureTiles);


		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());

		if (_particleSystem.running())
		{
			_window.draw(_particleSystem);
		}
	}

	// HUD
	_window.setView(_hudView);
	_window.draw(_hud.getLevel());
	_window.draw(_hud.getTime());

	_window.display();
}
