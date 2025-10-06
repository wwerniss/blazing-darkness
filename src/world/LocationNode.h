#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../entities/Enemy.h"
#include "../items/Item.h"

// Forward declarations
class Player;

class LocationNode {
private:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Item>> items;
    LocationNode* left;
    LocationNode* right;
    
public:
    LocationNode(const std::string& n, const std::string& desc);
    ~LocationNode();
    
    void setLeft(LocationNode* node);
    void setRight(LocationNode* node);
    
    LocationNode* getLeft() const;
    LocationNode* getRight() const;
    
    void addEnemy(std::shared_ptr<Enemy> enemy);
    void addItem(std::shared_ptr<Item> item);
    
    bool hasEnemies() const;
    std::vector<std::shared_ptr<Enemy>>& getEnemies();
    void removeEnemy(size_t index);
    
    std::string getName() const;
    std::string getDescription() const;
    
    void explore(Player& player);
};
