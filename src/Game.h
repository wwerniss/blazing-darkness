#pragma once

#include <memory>
#include <iostream>
#include "entities/Player.h"
#include "world/WorldMap.h"
#include "common/Logger.h"
#include "common/Utils.h"

class Game {
private:
    bool isRunning;
    std::unique_ptr<Player> player;
    std::unique_ptr<WorldMap> world;
    bool hasSlept; // Track if player has already slept
    void clearScreen();
    void showTitle();
    void showHelp();
    void showGameOver();
    void handleCombat();
    void showInventory();
    
public:
    Game();
    
    static Game& getInstance() {
        static Game instance;
        return instance;
    }
    
    void run();
};
