#include "Stick.h"

Stick::Stick() : Weapon("Палиця", "Проста дерев'яна палиця", 5, 2) {}

std::string Stick::getType() const {
    return "stick";
}
