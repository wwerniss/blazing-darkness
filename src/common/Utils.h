#pragma once

/**
 * @brief Utility class with common game functions.
 * 
 * This class provides various utility functions that are used throughout the game,
 * including terminal control, random number generation, and input handling.
 * 
 * @example
 * int randomValue = Utils::getRandomInt(1, 10);
 * bool success = Utils::chance(75);
 */
#include <string>
#include <iostream>

/**
 * @brief Utility class with common game functions.
 * 
 * This class provides various utility functions that are used throughout the game,
 * including terminal control, random number generation, and input handling.
 */
class Utils {
public:
    /**
     * @brief Sets raw mode for terminal input.
     * 
     * Enables or disables raw mode, which allows for non-blocking character input
     * and direct terminal control.
     * 
     * @param enable True to enable raw mode, false to disable
     * @throws std::runtime_error If there are issues with terminal mode setting
     */
    static void setRawMode(bool enable);
    
    /**
     * @brief Enables VT (Virtual Terminal) mode.
     * 
     * This function enables ANSI escape sequence support in the terminal,
     * allowing for advanced text formatting and cursor control.
     * 
     * @throws std::runtime_error If there are issues with VT mode enabling
     */
    static void enableVTMode();
    
    /**
     * @brief Moves the terminal cursor to a specific position.
     * 
     * Moves the terminal cursor to the specified row and column position.
     * 
     * @param row The target row position (0-indexed)
     * @param col The target column position (0-indexed)
     * @throws std::runtime_error If there are issues with cursor positioning
     */
    static void moveCursor(int row, int col);
    
    /**
     * @brief Clears the current terminal line.
     * 
     * Clears all content from the current terminal line and moves cursor to beginning.
     * 
     * @throws std::runtime_error If there are issues with terminal line clearing
     */
    static void clearLine();
    
    /**
     * @brief Gets the terminal height.
     * 
     * Returns the current height of the terminal window in characters.
     * 
     * @return The terminal height as an integer
     * @throws std::runtime_error If there are issues with terminal size detection
     */
    static int getTerminalHeight();
    
    /**
     * @brief Draws a footer line in the terminal.
     * 
     * Displays a footer message at the bottom of the terminal window.
     * 
     * @param text The text to display in the footer
     * @throws std::runtime_error If there are issues with terminal output or footer drawing
     */
    static void drawFooter(const std::string& text);
    
    /**
     * @brief Gets a character from input without blocking.
     * 
     * Reads a single character from terminal input if available, returns -1 if no input.
     * This is useful for real-time game input handling.
     * 
     * @return The character read, or -1 if no character is available
     * @throws std::runtime_error If there are issues with input reading
     */
    static int getCharNonBlock();
    
    /**
     * @brief Gets a random integer within a range.
     * 
     * Returns a random integer between min and max (inclusive).
     * 
     * @param min The minimum value (inclusive)
     * @param max The maximum value (inclusive)
     * @return A random integer in the specified range
     * @throws std::runtime_error If there are issues with random number generation
     */
    static int getRandomInt(int min, int max);
    
    /**
     * @brief Checks if a random chance succeeds.
     * 
     * Returns true with the specified percentage probability.
     * For example, chance(75) returns true 75% of the time.
     * 
     * @param percentage The probability percentage (0-100)
     * @return True if the random chance succeeds, false otherwise
     * @throws std::runtime_error If there are issues with random number generation or probability calculation
     */
    static bool chance(int percentage);
    
    /**
     * @brief Pauses execution for a specified time.
     * 
     * Sleeps the program for the specified number of milliseconds.
     * This is used to control game timing and pacing.
     * 
     * @param ms The number of milliseconds to sleep
     * @throws std::runtime_error If there are issues with sleep functionality or timing
     */
    static void sleep(int ms);
};
