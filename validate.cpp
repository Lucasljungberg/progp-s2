#include "validate.hpp"
#include <iostream>
#include <algorithm>

void validate(std::list<token> &tokens, std::list<expr> &list, int max_line, bool rep, bool short_rep);
token pop(std::list<token> &list);
void syntax_error(int line);

void validate(std::list<token> &tokens, std::list<expr> &list, int max_line, bool rep, bool short_rep){
    token current;
    while (tokens.size() > 0){

        current = pop(tokens);


        if (current.type == NONE){
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

            token arg2 = pop(tokens);

            if (arg2.type == CT){
                std::list<expr> replist;
                validate(tokens, replist, max_line, true);
                for (int x = 0; x < reps; x++){
                    list.insert(list.end(), replist.begin(), replist.end());
                }
            } else {
                std::list<expr> replist;
                tokens.insert(tokens.begin(), arg2);
                validate(tokens, replist, max_line, false, true);
                for (int x = 0; x < reps; x++){
                    list.insert(list.end(), replist.begin(), replist.end());
                }
            }
        } else if(current.type == EMPTY){
            // nop
        } else {
            syntax_error(current.line);
        }

        if (short_rep){
            return;
        }
    };

    if (rep){
        syntax_error(std::max(current.line, max_line-1));
    }

}

token pop(std::list<token> &list){
    token tok(list.front());
    list.pop_front();
    return tok;
}

void syntax_error(int line){
    std::cout << "Syntaxfel på rad " << line << std::endl;
    exit(0);
}