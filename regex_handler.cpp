#include "regex_handler.hpp"
#include <sstream>
#include <locale>

void search_and_add(std::string &str, std::vector<token> &tokens, int line);
void toupper(std::string &str);
bool valid_char(char c);

bool valid_char(char c){
    return ((64 < c && c < 91) | (47 < c && c < 58) | c == 35);   // Letters Numbers # 
}

void search_and_add(std::string &str, std::vector<token> &tokens, int line){
    std::string::iterator iter = str.begin();
    std::string::iterator end = str.end();

    std::stringstream stream;

    toupper(str);

    while (iter != end){
        char current = *iter;
        if (current == 37){         // Comment
            std::string s;
            stream >> s;
            if (!s.empty()){
                token tok(std::move(s), std::move(line));
                tokens.push_back(tok);
            }
            stream.str("");         // Reset stream
            stream.clear();
            return;
        } else if (valid_char(current)){    // Valid characters
            stream << current;
        } else if (current == 46){      // Dot
            std::string s;
            stream >> s;
            if (!s.empty()){
                token tok(std::move(s), std::move(line));
                tokens.push_back(tok);
            }
            stream.str("");
            stream.clear();
            std::string p = ".";
            token dot_tok(std::move(p), std::move(line));
            tokens.push_back(dot_tok);
        } else if (current == 32) {     // Space
            std::string s;
            stream >> s;
            if (!s.empty()){
                token tok(std::move(s), std::move(line));
                tokens.push_back(tok);
            }
            stream.str("");
            stream.clear();
        } else if(current == 34){       // Quote-mark
            std::string s;
            stream << current;
            stream >> s;
            if (!s.empty()){
                token tok(std::move(s), std::move(line));
                tokens.push_back(tok);
            }
            stream.str("");
            stream.clear();
        } else {
            stream << current;
            std::string s; 
            stream >> s;
            if (!s.empty()){
                token tok(std::move(s), std::move(line));
                tokens.push_back(tok);
            }
            stream.str("");
            stream.clear();
        }
        iter++;
    };
    std::string s;
    stream >> s;
    if (!s.empty()){
        token tok(std::move(s), std::move(line));
        tokens.push_back(tok);
    }
}

/*
    If any character in the string is within the range of
    lower-case letters in the ASCII table, it will be 
    converted into upper-case letters.
*/
void toupper(std::string &str){
    std::locale loc;
    for (int x = 0; x < str.size(); x++){
        str[x] = std::toupper(str[x], loc);
    }
}