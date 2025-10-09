#pragma once

#include "Weapon.h"

class Axe : public Weapon {
public:
    Axe();
    std::string getType() const override;
};
