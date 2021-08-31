#include "PCH.h"

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

void GraphicsManager::RemoveTexture(int textureID)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->second.first == textureID)
		{
			m_textures.erase(it->first);
		}
	}
}

// Gets a texture from the texture manager from an ID.
sf::Texture& GraphicsManager::GetTexture(int textureID)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->second.first == textureID)
		{
			return *it->second.second;
		}
	}
}