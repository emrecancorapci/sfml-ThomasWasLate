#pragma once
#include <SFML\Audio.hpp>

using namespace sf;

class SoundManager
{
private:
	SoundBuffer _fireBuffer;
	SoundBuffer _fallInFireBuffer;
	SoundBuffer _fallInWaterBuffer;
	SoundBuffer _jumpBuffer;
	SoundBuffer _reachGoalBuffer;

	Sound _fireSound1;
	Sound _fireSound2;
	Sound _fireSound3;
	Sound _fallInFireSound;
	Sound _fallInWaterSound;
	Sound _jumpSound;
	Sound _reachGoalSound;

	int _nextSound = 1;

public:
	SoundManager();

	void playFire(Vector2f emitterLocation, Vector2f listenerLocation);
	void playFallInFire();
	void playJump();
	void playReachGoal();
};

