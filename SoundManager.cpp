#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	int constexpr SOUND_NUMBER = 7;

	_fireBuffer.loadFromFile("sound/fire1.wav");
	_fallInFireBuffer.loadFromFile("sound/fallinfire.wav");
	_fallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	_jumpBuffer.loadFromFile("sound/jump.wav");
	_reachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	SoundBuffer buffers[SOUND_NUMBER] = {_fireBuffer, _fireBuffer, _fireBuffer,
		_fallInFireBuffer, _fallInWaterBuffer, _jumpBuffer, _reachGoalBuffer};

	Sound sounds[SOUND_NUMBER] = {_fireSound1,_fireSound2,_fireSound3,
		_fallInFireSound,_jumpSound,_reachGoalSound};

	for (int x = 0; x < SOUND_NUMBER; x++)
		sounds[x].setBuffer(buffers[x]);

	float minDistance = 150;
	float attenuation = 15;

	for (int x = 0; x < 3; x++)
	{
		sounds[x].setAttenuation(attenuation);
		sounds[x].setMinDistance(minDistance);
		sounds[x].setLoop(true);
	}
}

void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
	Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

	switch (_nextSound)
	{ // 474
	case 1:
		// ...
		break;
	case 2:
		// ...
		break;
	case 3:
		// ...
		break;
	}

	_nextSound++;

	if (_nextSound > 3)
	{
		_nextSound = 1;
	}
}

