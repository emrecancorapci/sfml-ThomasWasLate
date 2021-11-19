#include "Particle.h"

Particle::Particle(Vector2f direction):_velocity(direction){}

void Particle::update(float deltaTimeAsSec)
{
	_position += _velocity * deltaTimeAsSec;
}

void Particle::setPosition(Vector2f position)
{
	_position = position;
}

Vector2f Particle::getPosition()
{
	return _position;
}

