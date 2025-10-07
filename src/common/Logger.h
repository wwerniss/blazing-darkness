#pragma once

#include <string>
#include <iostream>

// Forward declarations
class Character;
class Item;

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    
    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }
    
    void error(const std::string& message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }
    
    void warning(const std::string& message) {
        std::cout << "[WARNING] " << message << std::endl;
    }
    
    void combatLog(const std::string& message) {
        std::cout << "\033[31m[БІЙ] " << message << "\033[0m" << std::endl;
    }
    
    void gameLog(const std::string& message) {
        std::cout << "\033[35m[ГРА] " << message << "\033[0m" << std::endl;
    }
    
private:
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
