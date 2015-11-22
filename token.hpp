#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenType{
    XY,         // LEFT RIGHT BACK FORW
    Z,          // UP DOWN
    CLR,        // COLOR
    ARG,        // Integer
    CARG,       // #[6 Hex-decimal Integers]
    DOT,        // .
    CT,         // "
    REP,        // REP
    EMPTY,      // Not needed
    NONE        // Everything else
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