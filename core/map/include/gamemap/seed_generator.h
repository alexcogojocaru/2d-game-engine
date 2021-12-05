#pragma once

#include <string>

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace map
	{
		class SeedGenerator
		{
		public:
			static std::string generate(uint32_t width, uint32_t height);
		};
	}
}