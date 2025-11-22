#pragma once

/**
 * @brief Base class for all game items.
 * 
 * This is the base class for all items in the game including weapons, potions,
 * and other consumable or equippable objects. It provides common functionality
 * for item management and usage.
 * 
 * @example
 * Item* item = new HealthPotion("Health Potion", "Restores 10 HP", "Healed for 10 HP", 10);
 * item->use(player);
 */
#include <string>
#include <memory>

class Character;

/**
 * @brief Base class for all game items.
 * 
 * This is the base class for all items in the game including weapons, potions,
 * and other consumable or equippable objects. It provides common functionality
 * for item management and usage.
 */
class Item {
protected:
    std::string name;
    std::string description;
    std::string usageMessage;
    int value;
    
public:
    /**
     * @brief Constructs a new Item instance.
     * 
     * Initializes the item with basic attributes like name, description, usage message, and value.
     * 
     * @param n The item's name
     * @param desc The item's description
     * @param usage The message to display when the item is used
     * @param val The value associated with the item (e.g., healing amount)
     */
    Item(const std::string& n, const std::string& desc, const std::string& usage, int val) 
        : name(n), description(desc), usageMessage(usage), value(val) {}
        
    /**
     * @brief Virtual destructor for the Item class.
     * 
     * Ensures proper cleanup of derived class objects.
     */
    virtual ~Item() = default;
    
    /**
     * @brief Uses the item on a character.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * It applies the item's effect to the character who uses it.
     * 
     * @param user The character who is using the item
     * @throws std::runtime_error If there are issues with item usage or character interaction
     */
    virtual void use(Character& user) = 0;
    
    /**
     * @brief Gets the type of item.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * It returns a string identifying the specific type of item.
     * 
     * @return The type of the item as a string
     * @throws std::runtime_error If the function is not properly overridden in derived classes
     */
    virtual std::string getType() const = 0;
    
    /**
     * @brief Gets the item's name.
     * 
     * @return The item's name as a string
     */
    std::string getName() const { return name; }
    
    /**
     * @brief Gets the item's description.
     * 
     * @return The item's description as a string
     */
    std::string getDescription() const { return description; }
    
    /**
     * @brief Gets the usage message for this item.
     * 
     * @return The usage message as a string
     */
    std::string getUsageMessage() const { return usageMessage; }
    
    /**
     * @brief Gets the item's value.
     * 
     * The value represents different properties depending on the item type
     * (e.g., healing amount for potions, damage for weapons).
     * 
     * @return The item's value as an integer
     */
    int getValue() const { return value; }
};
