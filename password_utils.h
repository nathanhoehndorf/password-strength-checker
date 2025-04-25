#pragma once
#include <string>

int score_password(const std::string& password);
double calculate_entropy(const std::string& password);
bool has_common_pattern(const std::string& password);
bool is_blacklisted(const std::string& password);