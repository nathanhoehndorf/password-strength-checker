#pragma once
#include <string>
#include <unordered_set>

int score_password(const std::string& password);
double calculate_entropy(const std::string& password);
bool has_common_pattern(const std::string& password);
std::unordered_set<std::string> load_blacklist(const std::string& filename);
bool is_blacklisted(const std::string& password);