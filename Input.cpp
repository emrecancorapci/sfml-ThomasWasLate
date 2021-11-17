#include "Engine.h"

void Engine::input()
{
	Event event{};

	while(_window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Escape key
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				_window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				_playing = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				_character1 = !_character1;
			}
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				_splitScreen = !_splitScreen;
			}
		}
	}

	if(_thomas.handleInput())
	{
		_soundManager.playJump();
	}

	if (_bob.handleInput())
	{
		_soundManager.playJump();
	}
};
