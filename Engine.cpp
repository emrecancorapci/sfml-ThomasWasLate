#include "Engine.h"

Engine::Engine()
{
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	_window.create(VideoMode(resolution.x, resolution.y),
		"Thomas Was Late", Style::Fullscreen);

	_mainView.setSize(resolution);
	_hudView.reset(
		FloatRect(
		0,
		0,
		resolution.x,
		resolution.y));

	_leftView.setViewport(
		FloatRect(
		.001f,
		.001f,
		.498f,
		.998f));
	_rightView.setViewport(
		FloatRect(
		.5f,
		.001f,
		.499f,
		.998f));
	_bg_leftView.setViewport(
		FloatRect(
			.001f, 
			.001f, 
			.498f, 
			.998f));
	_bg_rightView.setViewport(
		FloatRect(
			.5f, 
			.001f, 
			.499f, 
			.998f));
	_backgroundTexture = TextureHolder::GetTexture("graphics/background.png");
	_backgroundSprite.setTexture(_backgroundTexture);
}

void Engine::run()
{
	Clock clock;

	while (_window.isOpen())
	{
		Time deltaTime = clock.restart();
		_gameTimeTotal += deltaTime;
		float deltaTimeAsSec = deltaTime.asSeconds();

		input();
		update(deltaTimeAsSec);
		draw();
	}
}
