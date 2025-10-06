#pragma once

#include <string>
#include <iostream>

class Utils {
public:
    static void setRawMode(bool enable);
    static void enableVTMode();
    static void moveCursor(int row, int col);
    static void clearLine();
    static int getTerminalHeight();
    static void drawFooter(const std::string& text);
    static int getCharNonBlock();
    static int getRandomInt(int min, int max);
    static bool chance(int percentage);
    static void sleep(int ms);
};
