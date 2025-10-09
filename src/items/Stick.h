#pragma once

#include "Weapon.h"

class Stick : public Weapon {
public:
    Stick();
    std::string getType() const override;
};
