#pragma once

#include <SFML/Graphics.hpp>

#include "Arbiter/AI/Blackboard.h"
#include "Arbiter/AI/Kinematic.h"
#include "Arbiter/AI/Utility/Brain.h"
#include "Arbiter/AI/Steering/Steering.h"

namespace arbiter
{
    class Entity
    {
    public:
        Entity();
        void Update(float dt);
        void Render(sf::RenderTarget& target);

        float currentHealth = 10.0f, maxHealth = 100.0f;
        float currentEnergy = 2.0f, maxEnergy = 100.0f;
        float currentHunger = 1.1f, maxHunger = 100.0f;
        float currentThirst = 1.0f, maxThirst = 100.0f;

        float medCount = 1.0f;
        float foodCount = 1.0f;
        float waterCount = 1.0f;

        Blackboard blackboard;
        Kinematic kinematic;
        Brain agent;
        Steering steering;

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::CircleShape m_debugCircle;
    };
}



