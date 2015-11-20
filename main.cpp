#include <string>
#include <list>
#include <iostream>

#include "token.hpp"
#include "regex_handler.hpp"
#include "expression.hpp"
#include "validate.hpp"
#include "leonardo.hpp"

using namespace std;

int main(){
    list<string> content_list;
    string input_line;
    int counter = 0;
    while(getline(cin, input_line)){
        content_list.push_back(input_line);
        counter++;
    }

    list<token> tokens;
    int x = 0;
    while (!content_list.empty()){
        search_and_add(content_list.front(), tokens, ++x);
        content_list.pop_front();
    }

    list<expr> exp;
    validate(tokens, exp, counter);

    execute(exp);

    return 0;
}