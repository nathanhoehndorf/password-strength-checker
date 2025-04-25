#include "password_utils.h"
#include "terminal_io.h"

#include <iostream>
#include <string>

using namespace std;


string password_classification(int score) {
    if (score >= 7) return "Strong";
    if (score >= 4) return "Medium";
    return "Weak";
}

int main() {
    
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    int score = score_password(password);
    cout << "Password strength: " << password_classification(score) << " (score: " << score << ")\n";

    return 0;

}