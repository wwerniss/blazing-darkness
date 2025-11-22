#pragma once

/**
 * @brief Player character class.
 * 
 * This class represents the player character in the game, extending the base Character
 * class with additional functionality like experience tracking, leveling up, and item usage.
 * 
 * @example
 * Player player("Hero");
 * player.gainExperience(100);
 * player.levelUp();
 */
#include "Character.h"
#include <string>

/**
 * @brief Player character class.
 * 
 * This class represents the player character in the game, extending the base Character
 * class with additional functionality like experience tracking, leveling up, and item usage.
 */
class Player : public Character {
private:
    int experience;
    int experienceToNextLevel;
    
public:
    /**
     * @brief Constructs a new Player instance.
     * 
     * Initializes the player with default attributes and prepares for gameplay.
     * 
     * @param name The player's name (default: "Hero")
     */
    Player(const std::string& name);
    
    /**
     * @brief Gains experience points.
     * 
     * Increases the player's experience and checks if a level up is required.
     * 
     * @param amount The amount of experience to gain
     * @throws std::runtime_error If there are issues with experience tracking or level up logic
     */
    void gainExperience(int amount);
    
    /**
     * @brief Levels up the player character.
     * 
     * Increases the player's level and improves their stats (health, attack, defense).
     * The experience required for the next level increases after each level up.
     * 
     * @throws std::runtime_error If there are issues with level up logic or stat adjustment
     */
    void levelUp();
    
    /**
     * @brief Uses an item from the player's inventory.
     * 
     * Removes the item from inventory and applies its effect to the player.
     * 
     * @param index The index of the item in the inventory (0-based)
     * @throws std::runtime_error If there are issues with item usage or inventory management
     */
    void useItem(size_t index);
    
    // Getters
    
    /**
     * @brief Gets the player's current experience points.
     * 
     * @return The player's experience points
     */
    int getExperience() const;
    
    /**
     * @brief Gets the experience points required for the next level.
     * 
     * @return The experience needed to reach the next level
     */
    int getExperienceToNextLevel() const;
    
    /**
     * @brief Gets the player's current level.
     * 
     * @return The player's level
     */
    int getLevel() const;

    /**
     * @brief Gets the player's current attack power.
     * 
     * @return The player's current attack power
     */
    int getAttack() const;
    
    /**
     * @brief Gets the player's class name.
     * 
     * @return "Adventurer" as the player's class name
     */
    std::string getClassName() const override;
};
