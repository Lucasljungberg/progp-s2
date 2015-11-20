#ifndef VALIDATE_H
#define VALIDATE_H

#include <list>
#include "token.hpp"
#include "expression.hpp"

void validate(std::list<token> &tokens, std::list<expr> &list, int max_line, bool rep = false, bool short_rep = false);
token pop(std::list<token> &list);
void syntax_error(int line);

#endif