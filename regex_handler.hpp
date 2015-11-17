#ifndef REGEX_HANDLER_HPP
#define REGEX_HANDLER_HPP

#include "token.hpp"
#include <string>
#include <vector>

bool match(std::string str, std::string reg);
bool match(const char str_char, std::string reg);
bool match(std::string str, const char reg_char);
bool match(const char str_char, const char reg_char);

void search_and_add(std::string str, std::vector<token> &tokens, std::string reg, int line);

#endif