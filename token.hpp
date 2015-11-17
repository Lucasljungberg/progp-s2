#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenType{
    XY,
    Z,
    CLR,
    ARG,
    CARG,
    DOT,
    CT,
    REP,
    NONE
};

TokenType find_type(std::string str, int line);

struct token {
    std::string value;
    int line;
    TokenType type;

    token(){}
    token(
        std::string &&value_,
        int &&line_)
    :
    value(value_),
    line(line_)
    {
        type = find_type(value, line);
    }
};



#endif