#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <map>

namespace engine
{
	namespace resources
	{
		/// <summary>
		/// Interface for texture manager
		///		addTexture - loads a new texture in memory and adds it in the pool
		///		getTexture - returns a loaded texture that matches the provided key	
		/// </summary>
		class AbstractTextureManager
		{
		public:
			virtual void addTexture(std::string, std::string) = 0;
			virtual const sf::Texture& getTexture(std::string) = 0;
		};

		class TextureManager : public AbstractTextureManager
		{
		private:
			static std::shared_ptr<TextureManager>	s_instance;
			std::map<std::string, sf::Texture>		m_textures;

		public:
			TextureManager(std::map<std::string, std::string> texturePaths);

			void				addTexture(std::string textureName, std::string texturePath);
			const sf::Texture&	getTexture(std::string key);
			sf::Texture			getCopyTexture(std::string key);
			sf::Texture*		getPtrTexture(std::string key);

			static std::shared_ptr<TextureManager>	getInstance(std::map<std::string, std::string> texturePaths);
			static std::shared_ptr<TextureManager>	getInstance();
		};
	}
}