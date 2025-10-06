#include "WorldMap.h"
#include "../entities/Enemy.h"
#include "../items/HealthPotion.h"
#include "../items/StrengthPotion.h"
#include "../common/Logger.h"

WorldMap::WorldMap() : root(nullptr), currentLocation(nullptr) {
    createWorld();
}

WorldMap::~WorldMap() {
    delete root;
}

LocationNode* WorldMap::getCurrentLocation() const {
    return currentLocation;
}

void WorldMap::moveLeft() {
    if (currentLocation && currentLocation->getLeft()) {
        currentLocation = currentLocation->getLeft();
        // currentLocation->getName()
        Logger::getInstance().gameLog("Ви повернули ліворуч, шукаючи щось. Як думаєте, це була гарна ідея?");
    } else {
        Logger::getInstance().gameLog("Ви спробували піти ліворуч, але натрапили на бездонну прірву. Недовго думаючи, ви вирішили розвернутися.");
    }
}

void WorldMap::moveRight() {
    if (currentLocation && currentLocation->getRight()) {
        currentLocation = currentLocation->getRight();
        // currentLocation->getName()
        Logger::getInstance().gameLog("Ви повернули праворуч, шукаючи щось. Як думаєте, це була гарна ідея?");
    } else {
        Logger::getInstance().gameLog("Ви спробували піти праворуч, але натрапили на бездонну прірву. Недовго думаючи, ви вирішили розвернутися.");
    }
}

void WorldMap::createWorld() {
    auto* forest = new LocationNode("Темний ліс", "Густий ліс з високими, стародавніми деревами, що блокують більшу частину сонячного світла.");
    auto* cave = new LocationNode("Печера з павуками", "Темна та волога печера, заповнена павутинням.");
    auto* village = new LocationNode("Село", "Невелике, тихе село з кількома будинками та ринком.");
    auto* mountains = new LocationNode("Морозні гори", "Засніжені вершини з крижаними вітрами.");
    auto* dungeon = new LocationNode("Стародавнє підземелля", "Старе, покинуте підземелля, сповнене скарбів та небезпек.");
    
    // Create connections (binary tree structure)
    village->setLeft(forest);
    village->setRight(mountains);
    forest->setLeft(cave);
    forest->setRight(village);
    mountains->setLeft(village);
    mountains->setRight(dungeon);
    dungeon->setLeft(mountains);
    cave->setRight(forest);
    
    forest->addEnemy(std::make_shared<Enemy>("Гоблін", 2, 15, 4, 2, 25));
    forest->addEnemy(std::make_shared<Enemy>("Вовк", 1, 10, 3, 1, 15));
    
    cave->addEnemy(std::make_shared<Enemy>("Гігантський павук", 3, 20, 5, 3, 35));
    cave->addEnemy(std::make_shared<Enemy>("Рій кажанів", 1, 5, 2, 0, 10));
    
    dungeon->addEnemy(std::make_shared<Enemy>("Воїн скелет", 5, 30, 7, 5, 50));
    dungeon->addEnemy(std::make_shared<Enemy>("Зомбі", 3, 25, 5, 2, 30));
    
    mountains->addEnemy(std::make_shared<Enemy>("Єті", 7, 40, 10, 8, 75));
    
    root = village;
    currentLocation = village;
}
