#pragma once

#include <string>
#include <memory>

class Character;

class Item {
protected:
    std::string name;
    std::string description;
    std::string usageMessage;
    int value;
    
public:
    Item(const std::string& n, const std::string& desc, const std::string& usage, int val) 
        : name(n), description(desc), usageMessage(usage), value(val) {}
        
    virtual ~Item() = default;
    
    virtual void use(Character& user) = 0;
    virtual std::string getType() const = 0;
    
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getUsageMessage() const { return usageMessage; }
    int getValue() const { return value; }
};
