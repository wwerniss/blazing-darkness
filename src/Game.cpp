#include "Game.h"
#include <unistd.h> // for usleep

Game::Game() : isRunning(false) {}

void Game::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::showTitle() {
    std::cout << "__________.__                .__                 ________                __                                              " << std::endl;
    std::cout << "\\______   \\  | _____  _______|__| ____    ____   \\______ \\ _____ _______|  | __ ____   ____   ______ ______          " << std::endl;
    std::cout << " |    |  _/  | \\__  \\ \\___   /  |/    \\  / ___\\   |    |  \\\\__  \\\\_  __ \\  |/ //    \\_/ __ \\ /  ___//  ___/  " << std::endl;
    std::cout << " |    |   \\  |__/ __ \\_/    /|  |   |  \\/ /_/  >  |    `   \\/ __ \\|  | \\/    <|   |  \\  ___/ \\___ \\ \\___ \\    " << std::endl;
    std::cout << " |______  /____(____  /_____ \\__|___|  /\\___  /  /_______  (____  /__|  |__|_ \\___|  /\\___  >____  >____  >          " << std::endl;
    std::cout << "        \\/          \\/      \\/       \\//_____/           \\/     \\/           \\/    \\/     \\/     \\/     \\/    " << std::endl;
}

void Game::showHelp() {
    std::cout << "\n=== Команди ===\n"
              << "[S]how status\n"
              << "[E]xplore location\n"
              << "[F]ight enemies\n"
              << "[I]nventory\n"
              << "[L]eft - Move to the left location\n"
              << "[R]ight - Move to the right location\n"
              << "[V]illage - Return to the village\n"
              << "[Q]uit game\n"
              << "[H]elp - Show this help\n" << std::endl;
}

void Game::showGameOver() {
    Logger::getInstance().combatLog("Стікаючи кров’ю, ви намагалися втекти, але зрозуміли, що більше не зможете цього зробити. Ваші пригоди добігли кінця...");
}

void Game::handleCombat() {
    auto location = world->getCurrentLocation();
    if (!location->hasEnemies()) {
        Logger::getInstance().gameLog("Тут немає ворогів, з якими можна було б битися!");
        return;
    }
    
    auto& enemies = location->getEnemies();
    bool playerTurn = true;

    Logger::getInstance().gameLog("Ви розпочали бій!");
    
    while (!enemies.empty() && player->isAlive()) {
        Logger::getInstance().gameLog("Твоє шосте чуття підказує тобі, що ти маєш " + std::to_string(player->getHealth()) + " HP.");
        std::cout << "Вороги: ";
        for (size_t i = 0; i < enemies.size(); ++i) {
            std::cout << "[" << (i+1) << "] " << enemies[i]->getName() 
                      << " (HP: " << enemies[i]->getHealth() 
                      << "/" << enemies[i]->getMaxHealth() << ") ";
        }

        std::cout << std::endl;
        
        if (playerTurn) {
            char choice;
            do {
                choice = std::tolower(Utils::getCharNonBlock());
            } while (choice == -1);
            
            if (choice == 'a') {
                std::cout << "Якого ворога ви хочете атакувати? (1-" << enemies.size() << ")\n";
                int target = 0;
                char input;
                
                do {
                    input = Utils::getCharNonBlock();
                    if (input >= '1' && input <= '9') {
                        target = input - '0';
                        // std::cout << target << std::endl;
                        break;
                    }
                } while (input == -1);
                
                if (target > 0 && target <= static_cast<int>(enemies.size())) {
                    player->attackTarget(*enemies[target-1]);
                    
                    // Check if enemy is defeated
                    if (!enemies[target-1]->isAlive()) {
                        int exp = std::static_pointer_cast<Enemy>(enemies[target-1])->getExperienceReward();
                        player->gainExperience(exp);
                        Logger::getInstance().combatLog(enemies[target-1]->getName() + " зазнав поразки!");
                        location->removeEnemy(target-1);
                    }
                } else {
                    Logger::getInstance().warning("Недійсна ціль!");
                    continue;
                }
            } else if (choice == 'U' || choice == 'u') {
                // Handle item usage
                Logger::getInstance().gameLog("Використання предметів ще не реалізовано!");
                continue;
            } else if (choice == 'R' || choice == 'r') {
                if (Utils::chance(70)) {
                    Logger::getInstance().gameLog("Ви успішно втекли!");
                    return;
                } else {
                    Logger::getInstance().gameLog("Вам не вдалося втекти!");
                }
            } else {
                Logger::getInstance().warning("Невідома команда!");
                continue;
            }
        } else {
            // Enemy turn
            for (auto& enemy : enemies) {
                if (enemy->isAlive()) {
                    enemy->attackTarget(*player);
                    
                    if (!player->isAlive()) {
                        showGameOver();
                        isRunning = false;
                        return;
                    }
                }
            }
        }
        
        playerTurn = !playerTurn;
        
        Utils::sleep(1000);
    }
    
    if (enemies.empty()) {
        Logger::getInstance().combatLog("Всі вороги переможені!");
    }
}

void Game::showInventory() {
    Logger::getInstance().gameLog("Інвентар не реалізовано ще!");
}

void Game::run() {
    clearScreen();
    showTitle();
    std::cout << "\n";
    std::cout << "Blazing Darkness | Version 0.1 | Made by wwerniss\n";
    std::cout << "Введіть ім'я персонажа: ";
    std::string playerName;
    std::getline(std::cin, playerName);
    
    if (playerName.empty()) {
        playerName = "Герой";
    }
    
    player = std::make_unique<Player>(playerName);
    world = std::make_unique<WorldMap>();
    isRunning = true;

    std::cout << "Гра: [E] - Досліджувати [F] - Розпочати бій [S] - Статус [I] - Інвентар [L] - Ліворуч [R] - Праворуч [H] - Допомога [Q] - Вийти \nБій: [A] - Атакувати [U] - Використати предмет [R] - Втекти" << "\n";

    Logger::getInstance().gameLog(playerName + " прокину(вся/лась) в маленькому будинку...");
    Utils::sleep(2000);
    Logger::getInstance().gameLog("Двері зі скрипом відчиняються, ви виходите і бачите село з кількома будинками та крамницями.");
    Utils::sleep(2000);
    Logger::getInstance().gameLog("Останнє, що ви пам'ятаєте, це ім'я Ейрін та вашу вдалу втечу від монстрів.");
    Utils::sleep(2000);
    Logger::getInstance().gameLog("Ви готові розпочати свою пригоду! Чекаємо на ваші дії...");
    
    Utils::setRawMode(true);
    while (isRunning) {
        // Show current location
        auto location = world->getCurrentLocation();
        Logger::getInstance().gameLog("Перед вами " + location->getName() + ". " + location->getDescription());
        
        if (location->hasEnemies()) {
            Logger::getInstance().combatLog("Раптом ви почули шелест. Тут є вороги! (Натисніть «F», щоб розпочати бій)");
        }
        
        // Get single character input
        char input;
        do {
            input = std::tolower(Utils::getCharNonBlock());
        } while (input == -1);
        
        // Process input
        switch (input) {
            case 'e':
                location->explore(*player);
                break;
            case 'f':
                handleCombat();
                break;
            case 's':
                player->showStatus();
                break;
            case 'i':
                showInventory();
                break;
            case 'l':
                world->moveLeft();
                break;
            case 'r':
                world->moveRight();
                break;
            case 'h':
                showHelp();
                break;
            case 'q':
                isRunning = false;
                Logger::getInstance().gameLog("Дякуємо за гру!");
                break;
            default:
                Logger::getInstance().warning("Невідома команда. Натисніть 'H' для допомоги.");
        }
        
        // Small delay to prevent high CPU usage
        usleep(100000); // 100ms
    }
    
    // Clean up
    Utils::setRawMode(false);
}
