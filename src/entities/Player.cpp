#include "Player.h"
#include "../common/Logger.h"

Player::Player(const std::string& name) 
    : Character(name, 1, 20, 5, 3), experience(0), experienceToNextLevel(100) {}

void Player::gainExperience(int amount) {
    experience += amount;
    Logger::getInstance().gameLog("Отримано " + std::to_string(amount) + " очок досвіду!");
    
    if (experience >= experienceToNextLevel) {
        levelUp();
    }
}

void Player::levelUp() {
    level++;
    maxHealth += 5;
    health = maxHealth;
    attack += 2;
    defense += 1;
    experience -= experienceToNextLevel;
    experienceToNextLevel = static_cast<int>(experienceToNextLevel * 1.5);
    
    Logger::getInstance().gameLog("Рівень підвищений! Тепер ваш рівень " + std::to_string(level) + "!");
}

void Player::useItem(size_t index) {
    if (index < inventory.size()) {
        inventory[index]->use(*this);
        inventory.erase(inventory.begin() + index);
    } else {
        Logger::getInstance().warning("Недійсний індекс предмету!");
    }
}

// Getters
int Player::getExperience() const { 
    return experience; 
}

int Player::getExperienceToNextLevel() const { 
    return experienceToNextLevel; 
}

int Player::getLevel() const { 
    return level; 
}

std::string Player::getClassName() const {
    return "Adventurer";
}
