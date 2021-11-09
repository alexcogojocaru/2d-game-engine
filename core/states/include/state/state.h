#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace core
{
	class State
	{
	private:

	public:
		State();
	
		virtual void update() = 0;
		virtual void draw() = 0;
	};
}