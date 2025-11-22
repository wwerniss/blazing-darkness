#pragma once

/**
 * @brief Represents a location in the game world.
 * 
 * This class represents individual locations in the game world, such as forests,
 * villages, or dungeons. Each location contains enemies, items, and connections
 * to other locations in the world map.
 * 
 * @example
 * LocationNode* location = new LocationNode("Forest", "A dark forest");
 * location->addEnemy(std::make_shared<Enemy>("Goblin", 1, 10, 3, 1, 25));
 */
#include <string>
#include <vector>
#include <memory>
#include "../entities/Enemy.h"
#include "../items/Item.h"

// Forward declarations
class Player;

/**
 * @brief Represents a location in the game world.
 * 
 * This class represents individual locations in the game world, such as forests,
 * villages, or dungeons. Each location contains enemies, items, and connections
 * to other locations in the world map.
 */
class LocationNode {
private:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Item>> items;
    LocationNode* left;
    LocationNode* right;
    
public:
    /**
     * @brief Constructs a new LocationNode instance.
     * 
     * Initializes the location with name and description.
     * The left and right pointers are initially set to nullptr.
     * 
     * @param n The location's name
     * @param desc The location's description
     */
    LocationNode(const std::string& n, const std::string& desc);
    
    /**
     * @brief Destructor for the LocationNode class.
     * 
     * Cleans up all enemies and items in this location.
     */
    ~LocationNode();
    
    /**
     * @brief Sets the left child node of this location.
     * 
     * Establishes a connection to another location on the left side of the world map.
     * 
     * @param node The LocationNode to set as left child
     */
    void setLeft(LocationNode* node);
    
    /**
     * @brief Sets the right child node of this location.
     * 
     * Establishes a connection to another location on the right side of the world map.
     * 
     * @param node The LocationNode to set as right child
     */
    void setRight(LocationNode* node);
    
    /**
     * @brief Gets the left child node of this location.
     * 
     * Returns the LocationNode connected to the left side of the world map.
     * 
     * @return Pointer to the left LocationNode or nullptr if none exists
     */
    LocationNode* getLeft() const;
    
    /**
     * @brief Gets the right child node of this location.
     * 
     * Returns the LocationNode connected to the right side of the world map.
     * 
     * @return Pointer to the right LocationNode or nullptr if none exists
     */
    LocationNode* getRight() const;
    
    /**
     * @brief Adds an enemy to this location.
     * 
     * Adds a new enemy to the list of enemies in this location.
     * 
     * @param enemy The enemy to add to the location
     * @throws std::runtime_error If there are issues with adding enemies to location
     */
    void addEnemy(std::shared_ptr<Enemy> enemy);
    
    /**
     * @brief Adds an item to this location.
     * 
     * Adds a new item to the list of items in this location.
     * 
     * @param item The item to add to the location
     * @throws std::runtime_error If there are issues with adding items to location
     */
    void addItem(std::shared_ptr<Item> item);
    
    /**
     * @brief Checks if this location has enemies.
     * 
     * Returns true if there are enemies in this location.
     * 
     * @return True if location has enemies, false otherwise
     */
    bool hasEnemies() const;
    
    /**
     * @brief Gets the enemies in this location.
     * 
     * Returns a reference to the vector of enemies in this location.
     * 
     * @return Reference to the vector of enemies
     */
    std::vector<std::shared_ptr<Enemy>>& getEnemies();
    
    /**
     * @brief Removes an enemy from this location.
     * 
     * Removes the enemy at the specified index from this location.
     * 
     * @param index The index of the enemy to remove
     * @throws std::runtime_error If there are issues with removing enemies from location
     */
    void removeEnemy(size_t index);
    
    /**
     * @brief Gets the name of this location.
     * 
     * @return The location's name as a string
     */
    std::string getName() const;
    
    /**
     * @brief Gets the description of this location.
     * 
     * @return The location's description as a string
     */
    std::string getDescription() const;
    
    /**
     * @brief Explores this location.
     * 
     * Allows the player to explore the current location, potentially discovering items
     * and encountering enemies.
     * 
     * @param player The player character exploring the location
     * @throws std::runtime_error If there are issues with exploration or player interaction
     */
    void explore(Player& player);
};
