#ifndef REGEX_HANDLER_HPP
#define REGEX_HANDLER_HPP

#include "token.hpp"
#include <string>
#include <list>

void search_and_add(std::string &str, std::list<token> &tokens, int line);
void toupper(std::string &str);

#endif