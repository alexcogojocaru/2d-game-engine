#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <map>

namespace engine
{
	namespace resources
	{
		class TextureManager
		{
		private:
			static std::shared_ptr<TextureManager> s_instance;
			std::map<std::string, sf::Texture> m_textures;

		public:
			TextureManager(std::map<std::string, std::string> texturePaths);

			void addTexture(std::string textureName, std::string texturePath);
			const sf::Texture& getTexture(std::string key);
			static std::shared_ptr<TextureManager> getInstance(std::map<std::string, std::string> texturePaths);
		};
	}
}