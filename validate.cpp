#include "validate.hpp"
#include <iostream>

void validate(std::vector<token> &tokens, std::vector<expr> &list, bool rep, bool short_rep);
token pop(std::vector<token> &list);
void syntax_error(int line);

void validate(std::vector<token> &tokens, std::vector<expr> &list, bool rep, bool short_rep){
    token current;
    while (tokens.size() > 0){

        current = pop(tokens);

        if (current.type == NONE){
            syntax_error(current.line);
        }

        if (tokens.empty()){
            syntax_error(current.line);
        }

        if (rep && current.type == CT)
            return;

        if (current.type == XY){  

            if(tokens.size() < 2)
                syntax_error(current.line);

            token arg1 = pop(tokens);
            token arg2 = pop(tokens);

            if (arg1.type != ARG){
                syntax_error(arg1.line);    // First argument after XY should be an integer
            }
            if (arg2.type != DOT){
                syntax_error(arg2.line);    // Second argument of XY should be a dot.
            }

            expr new_exp(std::move(current.value), std::move(arg1.value), current.type);
            list.push_back(new_exp);

        } else if(current.type == Z){

            if(tokens.size() < 1)
                syntax_error(current.line);

            token arg1 = pop(tokens);

            if(arg1.type != DOT){
                syntax_error(arg1.line);
            }

            expr new_exp(std::move(current.value), "", current.type);
            list.push_back(new_exp);

        } else if(current.type == CLR){
            if(tokens.size() < 2)
                syntax_error(current.line);

            token arg1 = pop(tokens);
            token arg2 = pop(tokens);

            if(arg1.type != CARG){
                syntax_error(arg1.line);
            }

            if (arg2.type != DOT){
                syntax_error(arg2.line);
            }

            expr new_exp(std::move(current.value), std::move(arg1.value), current.type);
            list.push_back(new_exp);

        } else if(current.type == REP){

            if(tokens.size() < 2)
                syntax_error(current.line);

            token arg1 = pop(tokens);
            if (arg1.type != ARG){
                syntax_error(arg1.line);
            }
            int reps = stoi(arg1.value);

            token arg2 = tokens.front();

            if (arg2.type == CT){
                std::vector<expr> replist;
                tokens.erase(tokens.begin());
                validate(tokens, replist, true);
                for (int x = 0; x < reps; x++){
                    list.insert(list.end(), replist.begin(), replist.end());
                }
            } else {
                std::vector<expr> replist;
                validate(tokens, replist, false, true);
                for (int x = 0; x < reps; x++){
                    list.insert(list.end(), replist.begin(), replist.end());
                }
            }
        } else {
            syntax_error(current.line);
        }

        if (short_rep){
            return;
        }
    };

    if (rep){
        syntax_error(current.line);
    }

}

token pop(std::vector<token> &list){

    token tok(list.front());
    list.erase(list.begin());
    return tok;
}

void syntax_error(int line){
    std::cout << "Syntaxerror på rad " << line << std::endl;
    exit(1);
}