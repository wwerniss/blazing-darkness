#pragma once

/**
 * @brief A basic stick weapon.
 * 
 * This is the most basic weapon in the game, providing minimal damage.
 * It serves as a starting weapon for new players or when no better weapons are available.
 * 
 * @example
 * Stick stick;
 * player->equipWeapon(&stick);
 */
#include "Weapon.h"

/**
 * @brief A basic stick weapon.
 * 
 * This is the most basic weapon in the game, providing minimal damage.
 * It serves as a starting weapon for new players or when no better weapons are available.
 */
class Stick : public Weapon {
public:
    /**
     * @brief Constructs a new Stick instance.
     * 
     * Initializes the stick with default properties like name, description, damage, and value.
     */
    Stick();
    
    /**
     * @brief Gets the type of item.
     * 
     * Returns "stick" as the type for all stick instances.
     * 
     * @return "stick" as a string
     */
    std::string getType() const override;
};
