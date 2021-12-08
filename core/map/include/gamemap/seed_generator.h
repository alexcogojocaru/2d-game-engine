#pragma once

#include <string>

#define WIDTH_THRESHOLD_MAX		30
#define HEIGHT_THRESHOLD_MAX	14

#define WIDTH_THRESHOLD_MIN		10
#define HEIGHT_THRESHOLD_MIN	7

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace map
	{
		struct seed_info
		{
			uint32_t width;
			uint32_t height;
		};

		class SeedGenerator
		{
		private:
			static uint32_t normalize(uint32_t val, uint32_t pivot);

		public:
			static std::string generate();
			static seed_info evaluate(std::string seed);
		};
	}
}