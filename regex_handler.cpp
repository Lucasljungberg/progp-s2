#include "regex_handler.hpp"
#include <regex>

bool match(std::string str, std::string reg);
bool match(const char str_char, std::string reg);
bool match(std::string str, const char reg_char);
bool match(const char str_char, const char reg_char);

void search_and_add(std::string str, std::vector<token> &tokens, std::string reg, int line);


bool match(std::string str, std::string reg){
    std::regex re(reg, std::regex::icase);
    return std::regex_match(str, re);
}

bool match(const char str_char, std::string reg){
    std::string str(1, str_char);
    return match(str, reg);
}

bool match(std::string str, const char reg_char){
    std::string reg(1, reg_char);
    return match(str, reg);
}

bool match(const char str_char, const char reg_char){
    std::string str(1, str_char);
    std::string reg(1, reg_char);
    return match(str, reg);
}

void search_and_add(std::string str, std::vector<token> &tokens, std::string reg, int line){
    // Create regex from string. Also makes the regex case-insesnsitive
    std::regex re(reg, std::regex_constants::icase);

    // Initiate the iterator for the given interval
    std::sregex_iterator iter(str.begin(), str.end(), re);
    // Initiates an empty iterator to compare to so we know when the iterator is empty
    std::sregex_iterator end;

    while(iter != end){
        std::smatch current_match = *iter;  // smatch == match<string>
        if (match(current_match.str(), '%'))
            break;
        token tok(current_match.str(), std::move(line));
        tokens.push_back(tok);
        iter++; // Increase pointer
    }
}