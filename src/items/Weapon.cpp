#include "Weapon.h"
#include "../entities/Character.h"
#include <typeinfo>

Weapon::Weapon(const std::string& name, const std::string& desc, int damage, int value)
    : Item(name, desc, "", value), damage(damage) {
    usageMessage = "Ви почуваєтеся сильніше!";
}

void Weapon::use(Character& user) {
    try {
        user.unequipWeapon();
        user.equipWeapon(std::make_shared<Weapon>(*this));
    } catch (const std::exception& e) {
        user.addItem(std::make_shared<Weapon>(*this));
    }
}
