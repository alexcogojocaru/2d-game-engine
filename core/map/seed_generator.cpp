#include <iostream>
#include <random>
#include <ctime>
#include "include/gamemap/seed_generator.h"

namespace core
{
	namespace map
	{
		uint32_t SeedGenerator::normalize(uint32_t val, uint32_t pivot)
		{
			return (val < pivot) ? val + pivot : val;
		}

		std::string SeedGenerator::generate()
		{
			uint32_t width	= normalize(rand() % WIDTH_THRESHOLD_MAX, WIDTH_THRESHOLD_MIN);
			uint32_t height = normalize(rand() % HEIGHT_THRESHOLD_MAX, HEIGHT_THRESHOLD_MIN);

			return "w" + std::to_string(width) + "h" + std::to_string(height);
		}

		seed_info SeedGenerator::evaluate(std::string seed)
		{
			seed_info info;
			int startIndex = 1;

			for (int idx = 1; idx < seed.size(); idx++)
			{
				if (std::isalpha(seed[idx]))
				{
					info.width = atoi(seed.substr(startIndex, idx - 1).c_str());
					startIndex = idx + 1;
				}
			}

			info.height = atoi(seed.substr(startIndex, seed.size()).c_str());

			return info;
		}
	}
}