#pragma once

#include <SFML/Graphics.hpp>
#include <map>

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace constants
	{
#define ICON_NUMBER_ONE_X 1
		const sf::Vector2f ICON_NUMBER_ONE				= sf::Vector2f(1, 0);
		const sf::Vector2f ICON_NUMBER_TWO				= sf::Vector2f(2, 0);
		const sf::Vector2f ICON_NUMBER_THREE			= sf::Vector2f(3, 0);
		const sf::Vector2f ICON_NUMBER_FOUR				= sf::Vector2f(4, 0);
		const sf::Vector2f ICON_NUMBER_FIVE				= sf::Vector2f(5, 0);
		const sf::Vector2f ICON_NUMBER_SIX				= sf::Vector2f(6, 0);
		const sf::Vector2f ICON_NUMBER_SEVEN			= sf::Vector2f(7, 0);
		const sf::Vector2f ICON_NUMBER_EIGHT			= sf::Vector2f(8, 0);
		const sf::Vector2f ICON_NUMBER_NINE				= sf::Vector2f(9, 0);
		const sf::Vector2f ICON_NUMBER_ZERO				= sf::Vector2f(10, 0);

		const sf::Vector2f LETTER_CAPITAL_A				= sf::Vector2f(11, 0);
		const sf::Vector2f LETTER_CAPITAL_B				= sf::Vector2f(14, 0);
		const sf::Vector2f LETTER_CAPITAL_C				= sf::Vector2f(16, 0);
		const sf::Vector2f LETTER_CAPITAL_D				= sf::Vector2f(0, 1);
		const sf::Vector2f LETTER_CAPITAL_E				= sf::Vector2f(2, 1);
		const sf::Vector2f LETTER_CAPITAL_F				= sf::Vector2f(4, 1);
		const sf::Vector2f LETTER_CAPITAL_G				= sf::Vector2f(6, 1);
		const sf::Vector2f LETTER_CAPITAL_H				= sf::Vector2f(8, 1);
		const sf::Vector2f LETTER_CAPITAL_I				= sf::Vector2f(10, 1);
		const sf::Vector2f LETTER_CAPITAL_J				= sf::Vector2f(12, 1);
		const sf::Vector2f LETTER_CAPITAL_K				= sf::Vector2f(14, 1);
		const sf::Vector2f LETTER_CAPITAL_L				= sf::Vector2f(16, 1);
		const sf::Vector2f LETTER_CAPITAL_M				= sf::Vector2f(0, 2);
		const sf::Vector2f LETTER_CAPITAL_N				= sf::Vector2f(2, 2);
		const sf::Vector2f LETTER_CAPITAL_O				= sf::Vector2f(6, 2);
		const sf::Vector2f LETTER_CAPITAL_P				= sf::Vector2f(8, 2);
		const sf::Vector2f LETTER_CAPITAL_Q				= sf::Vector2f(10, 2);
		const sf::Vector2f LETTER_CAPITAL_R				= sf::Vector2f(12, 2);
		const sf::Vector2f LETTER_CAPITAL_S				= sf::Vector2f(14, 2);
		const sf::Vector2f LETTER_CAPITAL_T				= sf::Vector2f(16, 2);
		const sf::Vector2f LETTER_CAPITAL_U				= sf::Vector2f(0, 3);
		const sf::Vector2f LETTER_CAPITAL_V				= sf::Vector2f(2, 3);
		const sf::Vector2f LETTER_CAPITAL_W				= sf::Vector2f(4, 3);
		const sf::Vector2f LETTER_CAPITAL_X				= sf::Vector2f(6, 3);
		const sf::Vector2f LETTER_CAPITAL_Y				= sf::Vector2f(8, 3);
		const sf::Vector2f LETTER_CAPITAL_Z				= sf::Vector2f(10, 3);

		const sf::Vector2f PUNCTUATION_EXCLAMATION_MARK = sf::Vector2f(13, 3);
		const sf::Vector2f PUNCTUATION_QUSTION_MARK		= sf::Vector2f(15, 3);
		const sf::Vector2f PUNCTUATION_DOT				= sf::Vector2f(11, 4);
	}
}