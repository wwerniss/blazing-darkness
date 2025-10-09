#pragma once

#include "Item.h"

class Weapon : public Item {
protected:
    int damage;
    
public:
    Weapon(const std::string& name, const std::string& desc, int damage, int value);
    
    void use(Character& user) override;
    std::string getType() const override { return "weapon"; }
    
    int getDamage() const { return damage; }
};
