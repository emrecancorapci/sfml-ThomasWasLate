#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Hud
{
private:
	Font _font;
	Text _startText;
	Text _timeText;
	Text _levelText;
public:
	Hud();
	Text getMessage();
	Text getLevel();
	Text getTime();

	void setLevel(String text);
	void setTime(String text);
};

