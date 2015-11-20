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
    int counter = 0;
    while(getline(cin, input_line)){
        content_list.push_back(input_line);
        counter++;
    }

    vector<token> tokens;
    for (int x = 0; x < content_list.size(); x++){
        search_and_add(content_list[x], tokens, x+1);
    }

    vector<expr> exp;
    validate(tokens, exp, counter);

    execute(exp);

    return 0;
}