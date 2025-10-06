#pragma once

#include "Character.h"
#include <string>

class Player : public Character {
private:
    int experience;
    int experienceToNextLevel;
    
public:
    Player(const std::string& name);
    
    void gainExperience(int amount);
    void levelUp();
    void useItem(size_t index);
    
    // Getters
    int getExperience() const;
    int getExperienceToNextLevel() const;
    int getLevel() const;
    
    std::string getClassName() const override;
};
