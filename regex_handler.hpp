#ifndef REGEX_HANDLER_HPP
#define REGEX_HANDLER_HPP

#include "token.hpp"
#include <string>
#include <vector>

void search_and_add(std::string &str, std::vector<token> &tokens, int line);
void toupper(std::string &str);

#endif