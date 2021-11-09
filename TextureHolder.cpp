#include "TextureHolder.h"
#include <cassert>

TextureHolder* TextureHolder::_instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(_instance == nullptr);
	_instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	auto& m = _instance->_textures;

	auto kvp = m.find(filename);

	if(kvp != m.end())
	{
		return kvp -> second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}
