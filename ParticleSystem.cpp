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

		_particles.push_back(Particle(direction));
	} // 532

}
