#pragma once

#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword();
    std::string getType() const override;
};
