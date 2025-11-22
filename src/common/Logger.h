#pragma once

/**
 * @brief Singleton logger class for game messaging.
 * 
 * This class provides centralized logging functionality for the game, supporting
 * different log levels and color-coded output. It uses ANSI escape sequences for
 * colored terminal output to make messages more visually distinct.
 * 
 * @example
 * Logger& logger = Logger::getInstance();
 * logger.gameLog("Player started the game");
 * logger.combatLog("Player attacked enemy for 10 damage");
 */
#include <string>
#include <iostream>

// Forward declarations
class Character;
class Item;

/**
 * @brief Singleton logger class for game messaging.
 * 
 * This class provides centralized logging functionality for the game, supporting
 * different log levels and color-coded output. It uses ANSI escape sequences for
 * colored terminal output to make messages more visually distinct.
 */
class Logger {
public:
    /**
     * @brief Gets the singleton instance of the Logger class.
     * 
     * This method provides access to the single instance of the Logger class
     * using the singleton pattern.
     * 
     * @return Reference to the singleton Logger instance
     * @example
     * Logger& logger = Logger::getInstance();
     */
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    /**
     * @brief Logs a raw message without any formatting.
     * 
     * Outputs the message directly to the console without any prefixes or colors.
     * 
     * @param message The raw message to output
     */
    void raw(const std::string& message) {
        std::cout << message;
    }

    /**
     * @brief Logs a formatted message with prefix, level, and color.
     * 
     * Outputs a message with the specified color prefix, log level, and message text.
     * The output is terminated with a reset ANSI sequence to prevent color bleeding.
     * 
     * @param prefix The ANSI color code prefix
     * @param level The log level (e.g., "INFO", "ERROR")
     * @param message The actual log message
     */
    void log(const std::string& prefix, const std::string& level, const std::string& message) {
        std::cout << prefix << "[" << level << "] " << message << "\033[0m" << std::endl;
    }

    /**
     * @brief Logs an informational message.
     * 
     * Outputs a green-colored informational message to the console.
     * 
     * @param message The informational message to log
     */
    void info(const std::string& message) {
        log("\033[32m", "INFO", message);
    }
    
    /**
     * @brief Logs an error message.
     * 
     * Outputs a red-colored error message to the console.
     * 
     * @param message The error message to log
     */
    void error(const std::string& message) {
        log("\033[31m", "ERROR", message);
    }
    
    /**
     * @brief Logs a warning message.
     * 
     * Outputs a yellow-colored warning message to the console.
     * 
     * @param message The warning message to log
     */
    void warning(const std::string& message) {
        log("\033[33m", "WARNING", message);
    }
    
    /**
     * @brief Logs a combat-related message.
     * 
     * Outputs a red-colored combat message to the console, typically used for battle events.
     * 
     * @param message The combat-related message to log
     */
    void combatLog(const std::string& message) {
        log("\033[31m", "БІЙ", message);
    }
    
    /**
     * @brief Logs a general game message.
     * 
     * Outputs a magenta-colored game message to the console, typically used for story events.
     * 
     * @param message The game-related message to log
     */
    void gameLog(const std::string& message) {
        log("\033[35m", "ГРА", message);
    }
    
private:
    /**
     * @brief Private constructor for the Logger class.
     * 
     * Prevents direct instantiation of the Logger class and enforces singleton pattern.
     */
    Logger() {}
    
    /**
     * @brief Deleted copy constructor.
     * 
     * Prevents copying of the Logger instance to maintain singleton behavior.
     */
    Logger(const Logger&) = delete;
    
    /**
     * @brief Deleted assignment operator.
     * 
     * Prevents assignment of the Logger instance to maintain singleton behavior.
     */
    Logger& operator=(const Logger&) = delete;
};
