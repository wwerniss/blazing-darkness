#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../items/Item.h"

// Forward declarations
class Item;

// Base Character class
class Character {
protected:
    std::string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int defense;
    std::vector<std::shared_ptr<Item>> inventory;
    
public:
    Character(const std::string& n, int lvl, int hp, int atk, int def);
    virtual ~Character() = default;
    
    virtual void attackTarget(Character& target);
    void takeDamage(int amount);
    void heal(int amount);
    bool isAlive() const;
    
    void addItem(std::shared_ptr<Item> item);
    void showStatus() const;
    
    // Getters
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
    int getDefense() const;
    
    virtual std::string getClassName() const = 0;
};
