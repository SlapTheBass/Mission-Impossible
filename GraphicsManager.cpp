#include "GraphicsManager.h"

std::map<std::string, std::pair<int, std::unique_ptr<sf::Texture>>> GraphicsManager::m_textures;
int GraphicsManager::m_currentId = 0;

GraphicsManager::GraphicsManager()
{
}

int GraphicsManager::AddTexture(std::string filePath)
{
	auto it = m_textures.find(filePath);

	if (it != m_textures.end())
	{
		return it->second.first;
	}

	m_currentId++;
	
	std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(filePath))
	{
		std::cerr << "failed to load texture!";
		return -1;
	}
}