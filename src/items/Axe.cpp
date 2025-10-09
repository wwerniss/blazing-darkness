#include "Axe.h"

Axe::Axe() : Weapon("Сокира", "Важка бойова сокира", 20, 40) {}

std::string Axe::getType() const {
    return "axe";
}
