#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	int constexpr SOUND_NUMBER = 7;

	// Load sounds to buffers
	_fireBuffer.loadFromFile("sound/fire1.wav");
	_fallInFireBuffer.loadFromFile("sound/fallinfire.wav");
	_fallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	_jumpBuffer.loadFromFile("sound/jump.wav");
	_reachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	// Assign buffers to sounds
	_fireSound1.setBuffer(_fireBuffer);
	_fireSound2.setBuffer(_fireBuffer);
	_fireSound3.setBuffer(_fireBuffer);
	_fallInFireSound.setBuffer(_fallInFireBuffer);
	_fallInWaterSound.setBuffer(_fallInWaterBuffer);
	_jumpSound.setBuffer(_jumpBuffer);
	_reachGoalSound.setBuffer(_reachGoalBuffer);

	/*
	 const SoundBuffer buffers[SOUND_NUMBER] = {_fireBuffer, _fireBuffer, _fireBuffer,
		_fallInFireBuffer, _fallInWaterBuffer, _jumpBuffer, _reachGoalBuffer};

	Sound sounds[SOUND_NUMBER] = {_fireSound1,_fireSound2,_fireSound3,
		_fallInFireSound,_jumpSound,_reachGoalSound};

	for (int x = 0; x < SOUND_NUMBER; x++)
		sounds[x].setBuffer(buffers[x]);
	*/

	const float minDistance = 150;
	const float attenuation = 15;

	/*
	 for (int x = 0; x < 3; x++)
	{
		sounds[x].setAttenuation(attenuation);
		sounds[x].setMinDistance(minDistance);
		sounds[x].setLoop(true);
	}
	*/

	_fireSound1.setAttenuation(attenuation);
	_fireSound1.setMinDistance(minDistance);
	_fireSound1.setLoop(true);
	
	_fireSound2.setAttenuation(attenuation);
	_fireSound2.setMinDistance(minDistance);
	_fireSound2.setLoop(true);
	
	_fireSound3.setAttenuation(attenuation);
	_fireSound3.setMinDistance(minDistance);
	_fireSound3.setLoop(true);

}

void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
	Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

	// Move the source of the sounds
	switch (_nextSound)
	{
	case 1:
		_fireSound1.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (_fireSound1.getStatus() == Sound::Status::Stopped)
		{
			_fireSound1.play();
		}
		break;
	case 2:
		_fireSound2.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (_fireSound2.getStatus() == Sound::Status::Stopped)
		{
			_fireSound2.play();
		}
		break;
	case 3:
		_fireSound3.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (_fireSound3.getStatus() == Sound::Status::Stopped)
		{
			_fireSound3.play();
		}
		break;
	default: break;
	}

	_nextSound++;

	if (_nextSound > 3)
	{
		_nextSound = 1;
	}
}

void SoundManager::playFallInFire()
{
	_fallInFireSound.setRelativeToListener(true);
	_fallInFireSound.play();
}

void SoundManager::playFallInWater()
{
	_fallInWaterSound.setRelativeToListener(true);
	_fallInWaterSound.play();
}

void SoundManager::playJump()
{
	_jumpSound.setRelativeToListener(true);
	_jumpSound.play();
}

void SoundManager::playReachGoal()
{
	_reachGoalSound.setRelativeToListener(true);
	_reachGoalSound.play();
}

