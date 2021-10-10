#pragma once

#include "../graphics.h"

namespace engine
{
    namespace core
    {
        struct _directions 
        {
            int8_t up;
            int8_t right;

            _directions() 
            {
                up = right = 0;
            }
        };

        class AbstractInput
        {
        public:
            virtual _directions handler() = 0;
        };
        
    } // namespace core

} // namespace engine