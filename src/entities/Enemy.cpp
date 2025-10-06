#include "Enemy.h"

Enemy::Enemy(const std::string& name, int lvl, int hp, int atk, int def, int exp)
    : Character(name, lvl, hp, atk, def), experienceReward(exp) {}

int Enemy::getExperienceReward() const { 
    return experienceReward; 
}

std::string Enemy::getClassName() const {
    return "Enemy";
}
