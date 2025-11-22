#pragma once

/**
 * @brief The main game class that controls the overall game flow.
 * 
 * This class manages the game loop, player interaction, world navigation,
 * and combat system. It serves as the central hub for all game operations.
 * 
 * @example
 * Game& game = Game::getInstance();
 * game.run();
 */
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
    
    /**
     * @brief Clears the terminal screen.
     * 
     * This method clears the console screen using system-specific commands
     * to provide a clean interface for the game.
     */
    void clearScreen();
    
    /**
     * @brief Displays the game title screen.
     * 
     * Shows the ASCII art title of the game "Blazing Darkness".
     */
    void showTitle();
    
    /**
     * @brief Displays help information to the player.
     * 
     * Shows available commands and their descriptions for game navigation.
     */
    void showHelp();
    
    /**
     * @brief Displays game over message.
     * 
     * Shows a descriptive message when the player's character dies.
     */
    void showGameOver();
    
    /**
     * @brief Handles combat with enemies.
     * 
     * Manages the combat system including enemy targeting, attack sequences,
     * and win/lose conditions.
     */
    void handleCombat();
    
public:
    /**
     * @brief Constructs a new Game instance.
     * 
     * Initializes the game with default values and prepares the game state.
     */
    Game();
    
    /**
     * @brief Gets the singleton instance of the Game class.
     * 
     * This method provides access to the single instance of the Game class
     * using the singleton pattern.
     * 
     * @return Reference to the singleton Game instance
     * @example
     * Game& game = Game::getInstance();
     */
    static Game& getInstance() {
        static Game instance;
        return instance;
    }
    
    /**
     * @brief Runs the main game loop.
     * 
     * This method starts the game and controls the main execution flow,
     * handling user input, world navigation, and combat.
     * 
     * @throws std::runtime_error If there are issues with game initialization or execution
     */
    void run();
};
