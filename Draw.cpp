#include "Engine.h"

void Engine::draw()
{
	_window.clear(Color::Black);

	if (!_splitScreen)
	{
		_window.setView(_bg_mainView);
		_window.draw(_backgroundSprite);
		_window.setView(_mainView);

		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());
	}
	else
	{
		// If split-screen

		_window.setView(_bg_leftView);
		_window.draw(_backgroundSprite);
		_window.setView(_leftView);

		// Left View
		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());

		_window.setView(_bg_rightView);
		_window.draw(_backgroundSprite);
		_window.setView(_rightView);

		// Right View
		_window.draw(_thomas.getSprite());
		_window.draw(_bob.getSprite());
	}

	_window.setView(_hudView);

	_window.display();
}
