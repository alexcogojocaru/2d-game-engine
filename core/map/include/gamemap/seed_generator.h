#pragma once

#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif

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