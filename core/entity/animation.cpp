#include "include/entity/animation.h"

namespace core
{
    Animation::Animation()
    {

    }

    Animation::Animation(animation_info animInfo) : 
        m_animInfo(animInfo), 
        m_totalTime(0.0f)
    {
        m_currentImage = animInfo.idleInfo.range.start;
    }

    void Animation::update(float deltaTime, uint32_t increment)
    {
        m_totalTime += deltaTime;

        if (m_totalTime >= m_animInfo.switchtime)
        {
            m_totalTime -= m_animInfo.switchtime;
            m_currentImage += increment;

            if (m_currentImage >= m_animInfo.idleInfo.range.end * increment)
            {
                m_currentImage = m_animInfo.idleInfo.range.start;
            }
        }
    }

    sf::IntRect Animation::getTextureBox()
    { 
        return sf::IntRect(m_currentImage * 16, m_animInfo.idleInfo.y * 16, m_animInfo.dimension, m_animInfo.dimension); 
    }

    void Animation::changeAnimation(_frame_info frameInfo)
    {
        if (frameInfo != m_animInfo.idleInfo)
        {
            m_animInfo.idleInfo = frameInfo;
            m_totalTime = 0.0f;
        }
    }
}