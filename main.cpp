/* 
    Authors:
        Lucas Ljungberg <lucaslj@kth.se>
        Peter Jonsson   <peterjo6@kth.se>
*/

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
    string input_line;
    list<token> tokens;
    int counter = 0;
    while(getline(cin, input_line)){
        search_and_add(input_line, tokens, ++counter);
    }

    list<expr> exp;
    validate(tokens, exp, counter);

    execute(exp);

    return 0;
}