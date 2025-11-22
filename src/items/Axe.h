#pragma once

/**
 * @brief A powerful axe weapon.
 * 
 * This is a heavy weapon that provides high damage but potentially slower attack speed.
 * It's more powerful than the sword and stick, serving as a strong mid-game weapon.
 * 
 * @example
 * Axe axe;
 * player->equipWeapon(&axe);
 */
#include "Weapon.h"

/**
 * @brief A powerful axe weapon.
 * 
 * This is a heavy weapon that provides high damage but potentially slower attack speed.
 * It's more powerful than the sword and stick, serving as a strong mid-game weapon.
 */
class Axe : public Weapon {
public:
    /**
     * @brief Constructs a new Axe instance.
     * 
     * Initializes the axe with default properties like name, description, damage, and value.
     */
    Axe();
    
    /**
     * @brief Gets the type of item.
     * 
     * Returns "axe" as the type for all axe instances.
     * 
     * @return "axe" as a string
     */
    std::string getType() const override;
};
