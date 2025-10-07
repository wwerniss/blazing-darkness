# Blazing Darkness - Technical Documentation

## Overview
Blazing Darkness is a text-based role-playing game (RPG) implemented in C++. The game features a player character that can explore different locations, engage in combat with enemies, collect items, and level up.

## Core Architecture

### Main Components

1. **Game**
   - Central game controller
   - Manages game state and main game loop
   - Handles player input and game flow
   - Coordinates between different game systems

2. **World**
   - Manages game locations and navigation
   - Implements a node-based world map
   - Handles location transitions and exploration

3. **Entities**
   - Base character system with attributes (health, attack, defense)
   - Player character with experience and leveling
   - Enemy system with different types and behaviors

4. **Items**
   - Base item system with properties and effects
   - Consumable items (e.g., health potions)
   - Inventory management

## Detailed Component Documentation

### Game Class
- **Responsibilities**:
  - Game initialization and cleanup
  - Main game loop management
  - Input handling
  - Game state management
  - Combat system orchestration

- **Key Methods**:
  - `run()`: Main game loop
  - `handleCombat()`: Manages combat encounters
  - `showInventory()`: Displays player's inventory
  - `showHelp()`: Shows available commands

### World System

#### WorldMap
- Manages the game world as a graph of connected locations
- Handles player movement between locations
- Tracks current player position

#### LocationNode
- Represents a single location in the game world
- Contains:
  - Name and description
  - Connected locations (left/right)
  - Enemies present
  - Items available for collection

### Entity System

#### Character (Base Class)
- Core attributes:
  - Health/Max Health
  - Attack power
  - Defense
  - Level
- Common functionality:
  - Combat actions
  - Damage calculation
  - Status effects

#### Player
- Extends Character with:
  - Experience points
  - Level progression
  - Inventory management
  - Special abilities

#### Enemy
- Extends Character with:
  - Experience reward on defeat
  - AI behavior patterns
  - Loot tables

### Item System

#### Item (Base Class)
- Properties:
  - Name
  - Description
  - Value
  - Usage message
- Virtual methods:
  - `use(Character&)`: Applies item effects
  - `getType()`: Returns item type

#### HealthPotion
- Restores health when used
- Configurable heal amount
- Single-use item

## Game Mechanics

### Combat System
- Turn-based combat
- Damage calculation: `damage = attacker's attack - (defender's defense / 2)`
- Experience gain on enemy defeat
- Level progression with stat increases

### Exploration
- Move between connected locations
- Discover items and enemies
- Location-based events and encounters

### Inventory Management
- Collect and use items
- Limited inventory capacity
- Item stacking for stackable items

## Technical Implementation Details

### Memory Management
- Smart pointers (`std::shared_ptr`, `std::unique_ptr`) for automatic memory management
- RAII principles followed throughout the codebase

### Design Patterns
- Singleton pattern for Game and Logger
- Factory pattern for item creation
- Observer pattern for game events

### Dependencies
- Standard C++17 or later
- No external dependencies (standard library only)

## Data Flow
1. Player inputs command
2. Game processes input and updates state
3. World updates based on player actions
4. Entity interactions are resolved
5. Game renders new state to the console

## Error Handling
- Input validation
- Resource loading checks
- Graceful handling of edge cases
- Logging of important game events

## Performance Considerations
- Efficient data structures for game state
- Minimal memory allocations during gameplay
- Optimized rendering for text-based interface

## Extension Points
1. Adding new item types
2. Implementing new enemy behaviors
3. Expanding the world map
4. Adding new game mechanics (e.g., quests, crafting)

## Known Limitations
- Single-threaded implementation
- Basic AI for enemies
- Limited world persistence