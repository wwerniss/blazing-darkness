#pragma once

#include <string>
#include <memory>

// Forward declaration
class Character;

// Base Item class
class Item {
protected:
    std::string name;
    std::string description;
    int value;
    
public:
    Item(const std::string& n, const std::string& desc, int val) 
        : name(n), description(desc), value(val) {}
        
    virtual ~Item() = default;
    
    virtual void use(Character& user) = 0;
    virtual std::string getType() const = 0;
    
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getValue() const { return value; }
};
