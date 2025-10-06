#pragma once

#include "Character.h"

class Enemy : public Character {
private:
    int experienceReward;
    
public:
    Enemy(const std::string& name, int lvl, int hp, int atk, int def, int exp);
    
    int getExperienceReward() const;
    
    std::string getClassName() const override;
};
