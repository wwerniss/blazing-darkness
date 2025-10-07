#pragma once

#include "Item.h"

class HealthPotion : public Item {
private:
    int healAmount;
    
public:
    HealthPotion();
    ~HealthPotion() override = default;
    
    void use(Character& user) override;
    std::string getType() const override { return "HealthPotion"; }
    
    int getHealAmount() const { return healAmount; }
};