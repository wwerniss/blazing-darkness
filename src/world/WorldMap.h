#pragma once

#include "LocationNode.h"
#include <memory>

class WorldMap {
private:
    LocationNode* root;
    LocationNode* currentLocation;
    
    void createWorld();
    
public:
    WorldMap();
    ~WorldMap();
    
    LocationNode* getCurrentLocation() const;
    void moveLeft();
    void moveRight();
};
