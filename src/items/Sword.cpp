#include "Sword.h"

Sword::Sword() : Weapon("Меч", "Гострий сталевий меч", 15, 50) {}

std::string Sword::getType() const {
    return "sword";
}
