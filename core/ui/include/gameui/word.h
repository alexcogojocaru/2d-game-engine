#pragma once

#include <ui/icon.h>
#include <vector>

using namespace engine;

namespace core
{
	class Word
	{
	private:
		std::vector<ui::Icon> m_letters;

	public:
		Word();
		Word(const std::vector<sf::Vector2f>& letterCodes, sf::Vector2f& startPos);
	};
}