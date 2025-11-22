#pragma once

/**
 * @brief Base character class for all game characters.
 * 
 * This is the base class for all characters in the game including players and enemies.
 * It provides common functionality like health management, inventory handling, and combat.
 * 
 * @example
 * Character* character = new Player("Hero");
 * character->attackTarget(*enemy);
 */
#include <string>
#include <vector>
#include <memory>
#include "../items/Item.h"

// Forward declarations
class Item;
class Weapon;

// Base Character class
/**
 * @brief Base character class for all game characters.
 * 
 * This is the base class for all characters in the game including players and enemies.
 * It provides common functionality like health management, inventory handling, and combat.
 */
class Character {
protected:
    std::string name;
    int level;
    int health;
    int maxHealth;
    int baseAttack;
    int attack;
    int defense;
    std::vector<std::shared_ptr<Item>> inventory;
    std::shared_ptr<Weapon> equippedWeapon;
    
public:
    /**
     * @brief Constructs a new Character instance.
     * 
     * Initializes the character with basic attributes like name, level, health, and stats.
     * 
     * @param n The character's name
     * @param lvl The character's level (default: 1)
     * @param hp The character's health points (default: 10)
     * @param atk The character's base attack power (default: 5)
     * @param def The character's defense points (default: 2)
     */
    Character(const std::string& n, int lvl, int hp, int atk, int def);
    
    /**
     * @brief Virtual destructor for the Character class.
     * 
     * Ensures proper cleanup of derived class objects.
     */
    virtual ~Character() = default;
    
    /**
     * @brief Attacks a target character.
     * 
     * Deals damage to the target character based on attack power and defense.
     * 
     * @param target The character to attack
     * @throws std::runtime_error If there are issues with the combat system
     */
    virtual void attackTarget(Character& target);
    
    /**
     * @brief Takes damage from an attack.
     * 
     * Reduces the character's health by the specified amount, ensuring it doesn't go below zero.
     * 
     * @param amount The damage amount to take
     * @throws std::runtime_error If there are issues with health management
     */
    void takeDamage(int amount);
    
    /**
     * @brief Heals the character.
     * 
     * Restores health up to the maximum health value.
     * 
     * @param amount The amount of health to restore
     * @throws std::runtime_error If there are issues with healing system
     */
    void heal(int amount);
    
    /**
     * @brief Checks if the character is alive.
     * 
     * Returns true if the character has more than zero health points.
     * 
     * @return True if character is alive, false otherwise
     */
    bool isAlive() const;
    
    /**
     * @brief Adds an item to the character's inventory.
     * 
     * @param item The item to add to inventory
     * @throws std::runtime_error If there are issues with inventory management
     */
    void addItem(std::shared_ptr<Item> item);
    
    /**
     * @brief Displays the character's status and inventory.
     * 
     * Shows the character's stats, equipped weapon, and available items in inventory.
     * 
     * @throws std::runtime_error If there are issues with status display
     */
    void showStatus() const;
    
    // Weapon methods
    
    /**
     * @brief Equips a weapon to the character.
     * 
     * If a weapon is already equipped, it will be unequipped first.
     * The character's attack power is increased by the weapon's damage value.
     * 
     * @param weapon The weapon to equip
     * @throws std::runtime_error If there are issues with weapon equipping
     */
    void equipWeapon(std::shared_ptr<Weapon> weapon);
    
    /**
     * @brief Unequips the currently equipped weapon.
     * 
     * The weapon is added back to the character's inventory and attack power is reset.
     * 
     * @throws std::runtime_error If there are issues with weapon unequipping
     */
    void unequipWeapon();
    
    /**
     * @brief Checks if a weapon is currently equipped.
     * 
     * @return True if weapon is equipped, false otherwise
     */
    bool hasWeaponEquipped() const;
    
    // Getters
    
    /**
     * @brief Gets the character's name.
     * 
     * @return The character's name as a string
     */
    std::string getName() const;
    
    /**
     * @brief Gets the character's current health.
     * 
     * @return The character's current health points
     */
    int getHealth() const;
    
    /**
     * @brief Gets the character's maximum health.
     * 
     * @return The character's maximum health points
     */
    int getMaxHealth() const;
    
    /**
     * @brief Gets the character's current attack power.
     * 
     * @return The character's current attack power
     */
    int getAttack() const;
    
    /**
     * @brief Gets the character's defense points.
     * 
     * @return The character's defense points
     */
    int getDefense() const;
    
    /**
     * @brief Gets the name of the equipped weapon.
     * 
     * @return The name of the equipped weapon or "жодної" if none is equipped
     */
    std::string getEquippedWeaponName() const;
    
    /**
     * @brief Gets the character's inventory (const version).
     * 
     * @return Const reference to the character's inventory vector
     */
    const std::vector<std::shared_ptr<Item>>& getInventory() const { return inventory; }
    
    /**
     * @brief Gets the character's inventory (non-const version).
     * 
     * @return Reference to the character's inventory vector
     */
    std::vector<std::shared_ptr<Item>>& getInventory() { return inventory; }
    
    /**
     * @brief Gets the character's class name.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * 
     * @return The class name as a string
     * @throws std::runtime_error If the function is not properly overridden in derived classes
     */
    virtual std::string getClassName() const = 0;
};
