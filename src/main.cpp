#include "../include/password_utils.h"
#include "../include/terminal_io.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    int score = score_password(password);
    cout << "Password strength: " << password_classification(score) << " (score: " << score << ")\n";

    return 0;

}
