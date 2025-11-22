#pragma once

/**
 * @brief Base class for all weapons in the game.
 * 
 * This class represents weapons that can be equipped by characters to increase their attack power.
 * Weapons are a specific type of item with damage properties and can be equipped to characters.
 * 
 * @example
 * Weapon* weapon = new Sword("Sword", "A sharp sword", 10, 5);
 * player->equipWeapon(weapon);
 */
#include "Item.h"

/**
 * @brief Base class for all weapons in the game.
 * 
 * This class represents weapons that can be equipped by characters to increase their attack power.
 * Weapons are a specific type of item with damage properties and can be equipped to characters.
 */
class Weapon : public Item {
protected:
    int damage;
    
public:
    /**
     * @brief Constructs a new Weapon instance.
     * 
     * Initializes the weapon with name, description, damage value, and value.
     * 
     * @param name The weapon's name
     * @param desc The weapon's description
     * @param damage The damage value provided by this weapon
     * @param value The value associated with the weapon (e.g., for sale price)
     */
    Weapon(const std::string& name, const std::string& desc, int damage, int value);
    
    /**
     * @brief Uses the weapon (equipping it to a character).
     * 
     * This method equips the weapon to the character, increasing their attack power.
     * The weapon will be added to the character's inventory after equipping.
     * 
     * @param user The character who is using the weapon (equipping it)
     * @throws std::runtime_error If there are issues with weapon equipping or character interaction
     */
    void use(Character& user) override;
    
    /**
     * @brief Gets the type of item.
     * 
     * Returns "weapon" as the type for all weapon instances.
     * 
     * @return "weapon" as a string
     */
    std::string getType() const override { return "weapon"; }
    
    /**
     * @brief Gets the weapon's damage value.
     * 
     * @return The weapon's damage value as an integer
     */
    int getDamage() const { return damage; }
};
