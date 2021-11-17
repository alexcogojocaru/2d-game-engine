#pragma once

#include "icon_properties.h"
#include "healthbar.h"
#include "word.h"

namespace core
{
    namespace texture_properties
    {
        const std::string HEALTH_TEXTURE    = "health";
        const std::string ICON_TEXTURE      = "icons";
        const std::string SPRITE_TEXTURE    = "texture";

        #ifdef __linux__
            const std::string SPRITE_TEXTURE_PATH   = "/home/alex/Desktop/2d-game-engine/tileset.png";
            const std::string ICON_TEXTURE_PATH     = "/home/alex/Desktop/2d-game-engine/UI_Font_A.png";
            const std::string HEALTH_TEXTURE_PATH   = "/home/alex/Desktop/2d-game-engine/HeartSprites.png";
        #else
            const std::string SPRITE_TEXTURE_PATH   = "tileset.png";
            const std::string ICON_TEXTURE_PATH     = "UI_Font_A.png";
            const std::string HEALTH_TEXTURE_PATH   = "HeartSprites.png";
        #endif
    }
}