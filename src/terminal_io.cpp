#include "../include/terminal_io.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

std::string get_password() {
    std::string password;
    termios oldt, newt;

    std::cout << "Enter your password: ";
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDERR_FILENO, TCSANOW, &newt);

    std::getline(std::cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << "\n";
    return password;

}

std::string classify_strength(int score) {
    if (score >= 6) return "\033[1;32mStrong \033[0m";
    if (score >= 4) return "\033[1;33mModerate \033[0m";
    return "\033[1;31mWeak \033[0m";
}
