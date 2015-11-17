#include <string>
#include <vector>
#include <iostream>

#include "token.hpp"
#include "regex_handler.hpp"
#include "expression.hpp"
#include "validate.hpp"
#include "leonardo.hpp"

using namespace std;

int main(){
    vector<string> content_list;
    string input_line;
    while(getline(cin, input_line)){
        content_list.push_back(input_line);
    }

    vector<token> tokens;
    for (int x = 0; x < content_list.size(); x++){
        search_and_add(content_list[x], tokens, "([A-Za-z]+(?![\\d#]))|([1-9]\\d*(?![\"\\w]))|(\\.)|(#[A-Fa-f0-9]{6}(?![\"\\w]))|(\\%)|(\")", x+1);
    }

    vector<expr> exp;
    validate(tokens, exp);

    execute(exp);

    return 0;
}