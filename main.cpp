#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool is_blacklisted(const string& password) {
    vector<string> blacklist = {
        "password", "123456", "123456789", "qwerty", "abc123", "letmein", "admin"
    };
    string lower_pw = password;
    transform(lower_pw.begin(), lower_pw.end(), lower_pw.begin(), ::tolower);

    return find(blacklist.begin(), blacklist.end(), lower_pw) != blacklist.end();
}

bool has_repeated_pattern(const string& password) {
    if (password.length() < 4) return false;
    for (size_t i = 0; i < password.length()-1; ++i) {
        if (password[i] == password[i+1]) return true;
    }
    return false;
}

int score_password(const string& password) {
    int score = 0;

    int pass_length = password.length();

    if (pass_length >= 6) {
        if (pass_length % 2 == 0) {
            score += (pass_length / 2) - 1;
        } else {
            score += ((pass_length - 1) / 2) - 1;
        }
    }

    if (any_of(password.begin(), password.end(), ::isupper)) score++;
    if (any_of(password.begin(), password.end(), ::islower)) score++;
    if (any_of(password.begin(), password.end(), ::isdigit)) score++;
    if (any_of(password.begin(), password.end(), [](char ch) {
        return !isalnum(ch);
    }));

    if (is_blacklisted(password)) score -= 3;
    if (has_repeated_pattern(password)) score -= 1;

    return score;
    
}

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