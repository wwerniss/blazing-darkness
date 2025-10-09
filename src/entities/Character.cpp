#include "Character.h"
#include "../common/Logger.h"
#include "../items/Weapon.h"
#include <algorithm>

Character::Character(const std::string& n, int lvl, int hp, int atk, int def)
    : name(n), level(lvl), health(hp), maxHealth(hp), baseAttack(atk), attack(atk), defense(def), 
      equippedWeapon(nullptr) {}

void Character::attackTarget(Character& target) {
    int damage = std::max(1, attack - target.defense / 2);
    target.takeDamage(damage);
    Logger::getInstance().combatLog(
        name + " атакує " + target.getName() + " на " + std::to_string(damage) + " урону!"
    );
}

void Character::takeDamage(int amount) {
    health = std::max(0, health - amount);
}

void Character::heal(int amount) {
    health = std::min(maxHealth, health + amount);
}

bool Character::isAlive() const { 
    return health > 0; 
}

void Character::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
}

void Character::showStatus() const {
    std::cout << "\n=== " << name << " === ";
    std::cout << "Рівень: " << level << " | ";
    std::cout << "Здоров'я: " << health << "/" << maxHealth << " | ";
    std::cout << "Атака: " << attack << " | ";
    std::cout << "Захист: " << defense << std::endl;

    if (equippedWeapon) {
        std::cout << "\nУ ваших руках " << equippedWeapon->getName() << std::endl;
    } else {
        std::cout << "\nУ ваших руках немає жодної зброї!" << std::endl;
    }
    
    int counter = 0;
    if (!inventory.empty()) {
        std::cout << "\nІнвентар:";
        for (const auto& item : inventory) {
            std::cout << "\n" << ++counter << ". " << item->getName() << " (" << item->getDescription() << ")";
        }
        std::cout << "\nНатисніть номер предмету на клавіатурі, щоб використати його.";
    } else {
        std::cout << "\nВаш інвентар порожній.";
    }
    std::cout << std::endl << std::endl;
}

// Getters
std::string Character::getName() const { 
    return name; 
}

int Character::getHealth() const { 
    return health; 
}

int Character::getMaxHealth() const { 
    return maxHealth; 
}

int Character::getAttack() const { 
    return attack; 
}

int Character::getDefense() const { 
    return defense; 
}

void Character::equipWeapon(std::shared_ptr<Weapon> weapon) {
    if (equippedWeapon) {
        unequipWeapon();
    }
    
    equippedWeapon = weapon;
    attack = baseAttack + weapon->getDamage();
    Logger::getInstance().gameLog("Екіпіровано: " + weapon->getName() + 
                                " (+" + std::to_string(weapon->getDamage()) + " до атаки)");
}

void Character::unequipWeapon() {
    if (!equippedWeapon) return;
    
    attack = baseAttack;
    Logger::getInstance().gameLog("Знято: " + equippedWeapon->getName());
    addItem(equippedWeapon);
    equippedWeapon = nullptr;
}

bool Character::hasWeaponEquipped() const {
    return equippedWeapon != nullptr;
}

std::string Character::getEquippedWeaponName() const {
    return hasWeaponEquipped() ? equippedWeapon->getName() : "жодної";
}
