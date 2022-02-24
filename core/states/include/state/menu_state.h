#include "state.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	class MenuState : public State
	{
	private:
		sf::Sprite m_background;
		int currentWord;

	public:
		MenuState(sf::RenderWindow& window, uint32_t width, uint32_t height);

		void update(float deltaTime) override;
		void draw() override;
	};
}