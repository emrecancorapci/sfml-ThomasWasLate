#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Particle
{
private:
	Vector2f _position;
	Vector2f _velocity;

public:
	Particle(Vector2f direction);

	void update(float deltaTimeAsSec);

	void setPosition(Vector2f position);

	Vector2f getPosition();
};

