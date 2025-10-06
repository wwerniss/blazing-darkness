#include "Character.h"
#include "../common/Logger.h"
#include <algorithm>

Character::Character(const std::string& n, int lvl, int hp, int atk, int def)
    : name(n), level(lvl), health(hp), maxHealth(hp), attack(atk), defense(def) {}

void Character::attackTarget(Character& target) {
    int damage = std::max(1, attack - target.defense / 2);
    target.takeDamage(damage);
    Logger::getInstance().combatLog(
        name + " атакує " + target.getName() + " на " + std::to_string(damage) + " урону!"
    );
}

void Character::takeDamage(int amount) {
    health = std::max(0, health - amount);
}

void Character::heal(int amount) {
    health = std::min(maxHealth, health + amount);
}

bool Character::isAlive() const { 
    return health > 0; 
}

void Character::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
}

void Character::showStatus() const {
    std::cout << "\n=== " << name << " === ";
    std::cout << "Рівень: " << level << " | ";
    std::cout << "Здоров'я: " << health << "/" << maxHealth << " | ";
    std::cout << "Атака: " << attack << " | ";
    std::cout << "Захист: " << defense << std::endl;
    
    if (!inventory.empty()) {
        std::cout << "\nІнвентар:";
        for (const auto& item : inventory) {
            std::cout << "\n- " << item->getName() << " (" << item->getDescription() << ")";
        }
    }
    std::cout << std::endl;
}

// Getters
std::string Character::getName() const { 
    return name; 
}

int Character::getHealth() const { 
    return health; 
}

int Character::getMaxHealth() const { 
    return maxHealth; 
}

int Character::getAttack() const { 
    return attack; 
}

int Character::getDefense() const { 
    return defense; 
}
