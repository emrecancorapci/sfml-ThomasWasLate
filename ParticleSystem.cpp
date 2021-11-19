#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

using namespace sf;
using namespace std;

void ParticleSystem::init(int count)
{
	_vertices.setPrimitiveType(Points);
	_vertices.resize(count);

	for (int i = 0; i < count; i++)
	{
		srand(time(0) + i);
		float angle = (rand() % 360) * 3.14f / 180.f;
		float speed = (rand() % 600) + 600.f;

		Vector2f direction;

		direction = Vector2f(cos(angle) * speed, sin(angle) * speed);

		_particles.emplace_back(direction);
	}
}

void ParticleSystem::update(float deltaTime)
{
	_duration -= deltaTime;
	int currentVertex = 0;

	for(auto i = _particles.begin(); i!=_particles.end(); ++i)
	{
		i->update(deltaTime);
		_vertices[currentVertex++].position = i->getPosition();
	}

	if (_duration < 0) _isRunning = false;
}

void ParticleSystem::emitParticles(Vector2f position)
{
	_isRunning = true;
	_duration = 2;

	int currentVertex = 0;

	for(auto it = _particles.begin(); it != _particles.end(); ++it)
	{
		_vertices[currentVertex++].color = Color::Yellow;
		it->setPosition(position);
	}
}

void ParticleSystem::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_vertices,states);
}

bool ParticleSystem::running()
{
	return _isRunning;
}

