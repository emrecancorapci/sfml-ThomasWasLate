#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>


class TextureHolder
{
private:
	std::map <std::string, sf::Texture> _textures;
	static TextureHolder* _instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif
