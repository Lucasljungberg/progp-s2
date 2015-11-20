#include "token.hpp"
#include "regex_handler.hpp"

bool is_number(std::string str){
    if (str.empty()){
        return false;
    }else if (str[0] == '0'){
        return false;
    }
    for (char c :str){
        if (!(47 < c && c < 58)){       // Check if interval for number
            return false;
        }
    }
    return true;
}

bool is_color(std::string str){
    if (str[0] != '#'){
        return false;
    }
    else if(str.size() != 7){
        return false;        
    }
    for (int x = 1; x < str.size(); x++){
        if (!(47 < str[x] && str[x] < 58) && !(64 < str[x] && str[x] < 71)){
            return false;
        }
    }
    return true;
}

TokenType find_type(std::string str, int line){
    if(!str.compare("FORW") | !str.compare("BACK") | !str.compare("LEFT") | !str.compare("RIGHT")){
        return XY;
    }else if(!str.compare("DOWN") | !str.compare("UP")){
        return Z;
    }else if(!str.compare("REP")){
        return REP;
    }else if(!str.compare("COLOR")){
        return CLR;
    }else if(is_number(str)){
        return ARG;
    }else if(is_color(str)){
        return CARG;
    }else if(!str.compare(".")){
        return DOT;
    }else if(!str.compare("\"")){
        return CT;
    }else if(str.empty()){
        return EMPTY;
    }else{
        return NONE;
    }
}