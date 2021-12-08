#pragma once

#include "icon_properties.h"
#include "healthbar.h"
#include "word.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    namespace texture_properties
    {
        const std::string HEALTH_TEXTURE                = "health";
        const std::string ICON_TEXTURE                  = "icons";
        const std::string SPRITE_TEXTURE                = "texture";
        const std::string MENU_BACKGROUND_TEXTURE       = "bg";

        const std::string SPRITE_TEXTURE_PATH           = "tileset.png";
        const std::string ICON_TEXTURE_PATH             = "UI_Font_A.png";
        const std::string HEALTH_TEXTURE_PATH           = "HeartSprites.png";
        const std::string MENU_STATE_BACKGROUND_PATH    = "mist-bg.png";
    }
}