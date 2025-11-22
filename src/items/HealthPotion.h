#pragma once

/**
 * @brief A healing potion item.
 * 
 * This class represents a health potion that restores a character's health when used.
 * It's one of the most common consumable items in the game.
 * 
 * @example
 * HealthPotion potion;
 * potion.use(player);
 */
#include "Item.h"

/**
 * @brief A healing potion item.
 * 
 * This class represents a health potion that restores a character's health when used.
 * It's one of the most common consumable items in the game.
 */
class HealthPotion : public Item {
private:
    int healAmount;
    
public:
    /**
     * @brief Constructs a new HealthPotion instance.
     * 
     * Initializes the health potion with default properties like name, description,
     * usage message, value, and heal amount.
     */
    HealthPotion();
    
    /**
     * @brief Virtual destructor for the HealthPotion class.
     * 
     * Ensures proper cleanup of derived class objects.
     */
    ~HealthPotion() override = default;
    
    /**
     * @brief Uses the health potion on a character.
     * 
     * Heals the character by the potion's heal amount and removes it from inventory.
     * 
     * @param user The character who is using the potion
     * @throws std::runtime_error If there are issues with potion usage or character interaction
     */
    void use(Character& user) override;
    
    /**
     * @brief Gets the type of item.
     * 
     * Returns "HealthPotion" as the type for all health potion instances.
     * 
     * @return "HealthPotion" as a string
     */
    std::string getType() const override { return "HealthPotion"; }
    
    /**
     * @brief Gets the heal amount provided by this potion.
     * 
     * @return The heal amount as an integer
     */
    int getHealAmount() const { return healAmount; }
};
