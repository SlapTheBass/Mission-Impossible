#pragma once

#include "PCH.h"

class GraphicsManager
{
public:
	GraphicsManager();

	static int AddTexture(std::string filePath);

	static void RemoveTexture(int textureID);

	static sf::Texture& GetTexture(int textureID);

private:
	static std::map<std::string, std::pair<int, std::unique_ptr<sf::Texture>>> m_textures;

	static int m_currentId;
};

