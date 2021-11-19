#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable
{
private:
	vector<Particle> _particles;
	VertexArray _vertices;
	float _duration;
	bool _isRunning = false;

public:
	virtual void draw(RenderTarget& target, RenderStates states) const override;

	void init(int count);
	void emitParticles(Vector2f position);
	void update(float deltaTime);

	bool running();
	
};
