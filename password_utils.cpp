#include "password_utils.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <regex>
#include <vector>

bool has_upper(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::isupper);
}

bool has_lower(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::islower);
}

bool has_digits(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::isdigit);
}

bool has_symbol(const std::string& password) {
    return std::any_of(password.begin(), password.end(), [](char ch) {
        return !isalnum(ch);
    });
}

// change to more verbose list
bool is_blacklisted(const std::string& password) {
    std::vector<std::string> blacklist = {
        "password", "123456", "123456789", "qwerty", "abc123", "letmein", "admin"
    };
    std::string lower_pw = password;
    std::transform(lower_pw.begin(), lower_pw.end(), lower_pw.begin(), ::tolower);
    return std::find(blacklist.begin(), blacklist.end(), lower_pw) != blacklist.end();
}

bool has_common_pattern(const std::string& password) {
    std::regex repeat_pattern("(.)\\1{2,}");
    std::regex sequential_pattern("abc|123|qwe|xyz", std::regex_constants::icase);
    return std::regex_search(password, repeat_pattern) || std::regex_search(password, sequential_pattern);
}

double calculate_entropy(const std::string& password) {
    std::map<char, int> freq;
    for (char c : password) freq[c]++;
    double entropy = 0.0;
    for (const auto& [ch, count] : freq) {
        double p = static_cast<double>(count) / password.length();
        entropy -= p * std::log2(p);
    }
    return entropy * password.length();
}

int score_password(const std::string& password) {
    int score = 0;
    int pass_length = password.length();

    if (pass_length >= 6) {
        if (pass_length % 2 == 0) {
            score += (pass_length / 2) - 1;
        } else {
            score += ((pass_length - 1) / 2) - 1;
        }
    }

    if (has_upper(password)) score++;
    else score --;
    if (has_lower(password)) score++;
    else score--;
    if (has_digits(password)) score++;
    else score--;
    if (has_symbol(password)) score++;
    else score--;

    if (is_blacklisted(password)) score -= 4;
    if (has_common_pattern(password)) score -= 1;

    double entropy = calculate_entropy(password);
    if (entropy < 28) {
        score--;
    } else if (entropy > 35 && entropy < 60) {
        score++;
    } else if (entropy < 128) {
        score += 2;
    } else {
        score += 3;
    }

    return score;
    
}