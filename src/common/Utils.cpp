#include "Utils.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <random>

#ifdef _WIN32
    #include <windows.h>
#endif

void Utils::setRawMode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable line buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

#ifdef _WIN32
void Utils::enableVTMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif

void Utils::moveCursor(int row, int col) {
    std::cout << "\033[" << row << ';' << col << 'H';
}

void Utils::clearLine() {
    std::cout << "\033[2K";
}

int Utils::getTerminalHeight() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom + 1;   // координаты 0‑based → строка 1‑based
#else
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return ws.ws_row;
#endif
}

void Utils::drawFooter(const std::string& text) {
    int rows = getTerminalHeight();
    moveCursor(rows, 1);
    clearLine();
    std::cout << text;
    std::cout.flush();

    moveCursor(1, 1);
}

int Utils::getCharNonBlock() {
    int bytes = 0;
    char ch;
    fd_set set;
    struct timeval timeout = {0, 0};

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    if (select(STDIN_FILENO + 1, &set, nullptr, nullptr, &timeout) > 0) {
        bytes = read(STDIN_FILENO, &ch, 1);
        if (bytes == 1) return static_cast<unsigned char>(ch);
    }
    return -1; 
}

int Utils::getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

bool Utils::chance(int percentage) {
    return getRandomInt(1, 100) <= percentage;
}

void Utils::sleep(int ms) {
#ifdef _WIN32
    _sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
