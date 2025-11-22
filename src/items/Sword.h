#pragma once

/**
 * @brief A basic sword weapon.
 * 
 * This is a standard sword that provides moderate damage and is more powerful than the stick.
 * It serves as an intermediate weapon in the game progression.
 * 
 * @example
 * Sword sword;
 * player->equipWeapon(&sword);
 */
#include "Weapon.h"

/**
 * @brief A basic sword weapon.
 * 
 * This is a standard sword that provides moderate damage and is more powerful than the stick.
 * It serves as an intermediate weapon in the game progression.
 */
class Sword : public Weapon {
public:
    /**
     * @brief Constructs a new Sword instance.
     * 
     * Initializes the sword with default properties like name, description, damage, and value.
     */
    Sword();
    
    /**
     * @brief Gets the type of item.
     * 
     * Returns "sword" as the type for all sword instances.
     * 
     * @return "sword" as a string
     */
    std::string getType() const override;
};
