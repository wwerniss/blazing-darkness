#pragma once

/**
 * @brief Enemy character class.
 * 
 * This class represents enemy characters in the game, extending the base Character
 * class with experience reward functionality. Enemies are defeated by the player
 * and provide experience points upon defeat.
 * 
 * @example
 * Enemy enemy("Goblin", 1, 15, 3, 1, 25);
 * enemy.attackTarget(player);
 */
#include "Character.h"

/**
 * @brief Enemy character class.
 * 
 * This class represents enemy characters in the game, extending the base Character
 * class with experience reward functionality. Enemies are defeated by the player
 * and provide experience points upon defeat.
 */
class Enemy : public Character {
private:
    int experienceReward;
    
public:
    /**
     * @brief Constructs a new Enemy instance.
     * 
     * Initializes the enemy with basic attributes and experience reward value.
     * 
     * @param name The enemy's name
     * @param lvl The enemy's level (default: 1)
     * @param hp The enemy's health points (default: 10)
     * @param atk The enemy's attack power (default: 3)
     * @param def The enemy's defense points (default: 1)
     * @param exp The experience reward for defeating this enemy (default: 20)
     */
    Enemy(const std::string& name, int lvl, int hp, int atk, int def, int exp);
    
    /**
     * @brief Gets the experience reward for defeating this enemy.
     * 
     * This value represents how much experience the player gains when defeating this enemy.
     * 
     * @return The experience reward amount
     */
    int getExperienceReward() const;
    
    /**
     * @brief Gets the enemy's class name.
     * 
     * @return "Enemy" as the enemy's class name
     */
    std::string getClassName() const override;
};
