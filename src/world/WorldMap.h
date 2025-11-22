#pragma once

/**
 * @brief Manages the game world and location navigation.
 * 
 * This class handles the entire game world structure, including creating locations,
 * managing current location tracking, and allowing navigation between locations.
 * 
 * @example
 * WorldMap world;
 * world.moveLeft();
 * LocationNode* location = world.getCurrentLocation();
 */
#include "LocationNode.h"
#include <memory>

/**
 * @brief Manages the game world and location navigation.
 * 
 * This class handles the entire game world structure, including creating locations,
 * managing current location tracking, and allowing navigation between locations.
 */
class WorldMap {
private:
    LocationNode* root;
    LocationNode* currentLocation;
    
    /**
     * @brief Creates the initial world structure.
     * 
     * Sets up all the locations in the game world with their connections and properties.
     * This method is called during initialization to build the complete world map.
     * 
     * @throws std::runtime_error If there are issues with world creation or location setup
     */
    void createWorld();
    
public:
    /**
     * @brief Constructs a new WorldMap instance.
     * 
     * Initializes the world map and creates the complete location structure.
     */
    WorldMap();
    
    /**
     * @brief Destructor for the WorldMap class.
     * 
     * Cleans up all allocated memory for location nodes in the world map.
     */
    ~WorldMap();
    
    /**
     * @brief Gets the current location in the world.
     * 
     * Returns a pointer to the current LocationNode that the player is in.
     * 
     * @return Pointer to the current LocationNode
     */
    LocationNode* getCurrentLocation() const;
    
    /**
     * @brief Moves the player to the left location.
     * 
     * Changes the current location to the one on the left in the world map structure.
     * If there is no left location, it does nothing.
     * 
     * @throws std::runtime_error If there are issues with location navigation
     */
    void moveLeft();
    
    /**
     * @brief Moves the player to the right location.
     * 
     * Changes the current location to the one on the right in the world map structure.
     * If there is no right location, it does nothing.
     * 
     * @throws std::runtime_error If there are issues with location navigation
     */
    void moveRight();
};
