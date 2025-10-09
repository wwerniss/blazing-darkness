#include "HealthPotion.h"
#include "../entities/Character.h"

HealthPotion::HealthPotion() 
    : Item("Зілля здоров'я", "Магічне зілля, яке відновлює здоров'я.", "Ви використали зілля здоров'я та почуваєте себе краще!", 50),
      healAmount(30) {
}

void HealthPotion::use(Character& user) {
    user.heal(healAmount);
}