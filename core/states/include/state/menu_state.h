#include "state.h"

namespace core
{
	class MenuState : public State
	{
	public:
		MenuState(sf::RenderWindow& window, uint32_t width, uint32_t height);

		void update() override;
		void draw() override;
	};
}