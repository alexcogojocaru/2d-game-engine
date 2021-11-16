#include <iostream>
#include "include/resources_pool/texture_manager.h"

namespace engine
{
	namespace resources
	{
		std::shared_ptr<TextureManager> TextureManager::s_instance = nullptr;

		TextureManager::TextureManager(std::map<std::string, std::string> texturePaths)
		{
			for (auto& elem : texturePaths)
			{
				addTexture(elem.first, elem.second);
			}
		}

		void TextureManager::addTexture(std::string textureName, std::string texturePath)
		{
			sf::Texture texture;
			if (!texture.loadFromFile(texturePath))
			{
				std::cout << "can't load texture " + textureName << std::endl;
			}

			m_textures.insert(std::pair<std::string, sf::Texture>(textureName, texture));
		}

		const sf::Texture& TextureManager::getTexture(std::string key)
		{
			return std::ref(m_textures[key]);
		}

		std::shared_ptr<TextureManager> TextureManager::getInstance(std::map<std::string, std::string> texturePaths)
		{
			if (s_instance == nullptr)
			{
				s_instance = std::make_shared<TextureManager>(texturePaths);
			}

			return s_instance;
		}

		std::shared_ptr<TextureManager> TextureManager::getInstance()
		{
			return s_instance;
		}
	}
}