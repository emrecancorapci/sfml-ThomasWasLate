#include "Engine.h"

void Engine::draw()
{
	_window.clear(Color::Black);

	if (!_splitScreen)
	{
		_window.setView(_bg_mainView);
		_window.draw(_backgroundSprite);
		_window.setView(_mainView);
		_window.draw(_vertexLevel, &_textureTiles);

		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());
	}
	else
	{
		// If split-screen
		// Left View
		_window.setView(_bg_leftView);
		_window.draw(_backgroundSprite);
		_window.setView(_leftView);
		_window.draw(_vertexLevel, &_textureTiles);

		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());

		// Right View
		_window.setView(_bg_rightView);
		_window.draw(_backgroundSprite);
		_window.setView(_rightView);
		_window.draw(_vertexLevel, &_textureTiles);


		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());
	}
	// HUD
	_window.setView(_hudView);
	_window.draw(_hud.getLevel());
	_window.draw(_hud.getTime());
	// 491
	_window.display();
}
