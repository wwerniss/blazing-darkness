#include "src/Game.h"
#include "src/common/Utils.h"

int main() {
    #ifdef _WIN32
        Utils::enableVTMode();
    #endif
    
    Game& game = Game::getInstance();
    game.run();
    
    return 0;
}
