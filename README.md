# Blazing Darkness
A console RPG with turn-based combat and procedural generation elements.

You are the one who survived after fleeing your hometown — a name you’ve forgotten due to trauma. The only things you remember are the name Eirin and the taste of ash on your tongue. The village where you woke up is a border settlement on the edge of the Dark Forest, where scouts from the Flame Guild have recently been disappearing.

Documentations: 
[Mechanics [EN]](./docs/mechanics_en.md) | [Mechanics [UA]](./docs/mechanics_ua.md)

## Prerequisites

- CMake (version 3.10 or higher)
- C++17 compatible compiler
- Unix-like system (Linux, macOS, or WSL) (Windows is not tested)

## Building

```bash
chmod 777 ./tools/build.sh 
./tools/build.sh
```

## Running

After building, run the executable:

```bash
./build/BlazingDarkness
or
chmod 777 ./tools/run.sh 
./tools/run.sh
```

## Controls

#### In game
- `Q`: Quit the game
- `S`: Show status
- `E`: Explore location
- `F`: Fight enemies
- `I`: Inventory
- `L`: Move to the left location
- `R`: Move to the right location
- `Q`: Quit game
- `H`: Show help

#### In battle

- `A`: Attack
- `U`: Use item
- `R`: Run

## Project Structure

- `main.cpp`: Entry point of the application
- `CMakeLists.txt`: Build configuration
- `src/`: Source code directory
- `src/common/`: Common code directory
- `src/entities/`: Entities code directory
- `src/items/`: Items code directory
- `src/world/`: World code directory
- `tools/`: Tools directory
- `docs/`: Documentation directory
