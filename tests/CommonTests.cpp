#include <gtest/gtest.h>
#include "../src/entities/Player.h"
#include "../src/items/Weapon.h"
#include "../src/items/HealthPotion.h"
#include "../src/entities/Enemy.h"
#include "../src/world/WorldMap.h"
#include "../src/items/Weapon.h"
#include <memory>
#include <typeinfo>

/*
   - EXPECT_EQ(a, b) - проверяет равенство a и b
   - EXPECT_NE(a, b) - проверяет, что a не равно b
   - EXPECT_TRUE(condition) - проверяет, что условие истинно
   - EXPECT_FALSE(condition) - проверяет, что условие ложно
   - и другие макросы из Google Test
*/

// Тест на инициализацию игрока
TEST(PlayerTest, Initialization) {
    Player player("Тестовый игрок");
    
    EXPECT_GT(player.getHealth(), 0);
    EXPECT_GT(player.getMaxHealth(), 0);
    EXPECT_GE(player.getAttack(), 0);
}

// Тест на использование оружия
TEST(ItemTest, WeaponUsage) {
    Weapon sword("Меч", "Острый меч", 15, 10);
    
    EXPECT_EQ(sword.getName(), "Меч");
    EXPECT_EQ(sword.getDamage(), 15);
    
    Player player("Тестовый игрок");
    
    player.equipWeapon(std::make_shared<Weapon>(sword));
    
    EXPECT_GT(player.getAttack(), 15);
}

// Тест на использование зелья здоровья
TEST(ItemTest, HealthPotionUsage) {
    HealthPotion potion;
    
    Player player("Тестовый игрок");
    int initialHealth = player.getHealth();
    int damage = 20;
    player.takeDamage(damage);
    
    EXPECT_LT(player.getHealth(), initialHealth);
    
    potion.use(player);
    
    EXPECT_GE(player.getHealth(), initialHealth - damage);
    EXPECT_LE(player.getHealth(), player.getMaxHealth());
    
    EXPECT_EQ(potion.getName(), "Зілля здоров'я");
    EXPECT_GT(potion.getHealAmount(), 0);
}

// Тест на урон от монстров
TEST(CombatTest, EnemyDamage) {
    Player player("Тестовый игрок");
    Enemy goblin("Гоблин", 1, 20, 5, 2, 10);
    
    int initialHealth = player.getHealth();
    
    goblin.attackTarget(player);
    
    int expectedMinDamage = 1;
    int expectedMaxDamage = goblin.getAttack() - (player.getDefense() / 2);
    
    EXPECT_LT(player.getHealth(), initialHealth);
    EXPECT_GE(player.getHealth(), initialHealth - expectedMaxDamage);
    EXPECT_LE(player.getHealth(), initialHealth - expectedMinDamage);
    
    if (player.getHealth() > 0) {
        EXPECT_TRUE(player.isAlive());
    }
    
    while (goblin.isAlive()) {
        player.attackTarget(goblin);
    }
    EXPECT_FALSE(goblin.isAlive());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}