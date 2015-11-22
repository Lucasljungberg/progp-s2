#ifndef LEONARDO_HPP
#define LEONARDO_HPP

#include <list>
#include <string>
#include "expression.hpp"

void execute(std::list<expr> &list);
void print_result();
double round_num(double input);

void up();
void down();
void right(int &&arg);
void left(int &&arg);
void forw(int &&arg);
void back(int &&arg);
void color(std::string &&arg);


#endif
