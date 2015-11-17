#ifndef VALIDATE_H
#define VALIDATE_H

#include <vector>
#include "token.hpp"
#include "expression.hpp"

void validate(std::vector<token> &tokens, std::vector<expr> &list, bool rep = false, bool short_rep = false);
token pop(std::vector<token> &list);
void syntax_error(int line);

#endif