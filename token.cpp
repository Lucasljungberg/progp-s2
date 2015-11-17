#include "token.hpp"
#include "regex_handler.hpp"
#include <iostream>

TokenType find_type(std::string str, int line){
    if(match(str, "^(right)|(left)|(forw)|(back)$")){
        return XY;
    }else if(match(str, "^(up)|(down)$")){
        return Z;
    }else if(match(str, "^rep$")){
        return REP;
    }else if(match(str, "^color$")){
        return CLR;
    }else if(match(str, "^\\s?\\d+$")){
        return ARG;
    }else if(match(str, "^\\s?#[0-9A-Fa-f]{6}$")){
        return CARG;
    }else if(match(str, "\\.")){
        return DOT;
    }else if(match(str, '"')){
        return CT;
    }else{
        return NONE;
    }
}