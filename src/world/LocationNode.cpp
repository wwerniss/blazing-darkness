#include "LocationNode.h"
#include "../entities/Player.h"
#include "../common/Logger.h"

LocationNode::LocationNode(const std::string& n, const std::string& desc)
    : name(n), description(desc), left(nullptr), right(nullptr) {}
    
LocationNode::~LocationNode() {
    delete left;
    delete right;
}

void LocationNode::setLeft(LocationNode* node) { 
    left = node; 
}

void LocationNode::setRight(LocationNode* node) { 
    right = node; 
}

LocationNode* LocationNode::getLeft() const { 
    return left; 
}

LocationNode* LocationNode::getRight() const { 
    return right; 
}

void LocationNode::addEnemy(std::shared_ptr<Enemy> enemy) {
    enemies.push_back(enemy);
}

void LocationNode::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}

bool LocationNode::hasEnemies() const { 
    return !enemies.empty(); 
}

std::vector<std::shared_ptr<Enemy>>& LocationNode::getEnemies() { 
    return enemies; 
}

void LocationNode::removeEnemy(size_t index) {
    if (index < enemies.size()) {
        enemies.erase(enemies.begin() + index);
    }
}

std::string LocationNode::getName() const { 
    return name; 
}

std::string LocationNode::getDescription() const { 
    return description; 
}

void LocationNode::explore(Player& player) {
    if (!enemies.empty()) {
        Logger::getInstance().combatLog("Ви озирнулися навколо і помітили " + std::to_string(enemies.size()) + " монстрів.");
        for (const auto& enemy : enemies) {
            Logger::getInstance().combatLog("- " + enemy->getName() + " (Lvl " + std::to_string(enemy->getHealth()) + "/" + std::to_string(enemy->getMaxHealth()) + ")");
        }
    } else if (!items.empty()) {
        Logger::getInstance().gameLog("Ви озирнулися навколо та знайшли предмети:");
        for (const auto& item : items) {
            player.addItem(item);
            Logger::getInstance().gameLog("- " + item->getName() + " (" + item->getDescription() + ")");
        }
        items.clear();
    } else {
        Logger::getInstance().gameLog("Це місце здається порожнім... Нічого цікавого.");
    }
}
