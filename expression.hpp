#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include "token.hpp"

class expr{
public:
    std::string cmd;
    std::string arg;
    TokenType type;
    // Constructor case when both cmd and arg are are rvalues
    expr(
    std::string &&cmd_,
    std::string &&arg_,
    TokenType type_):
    cmd(cmd_),
    arg(arg_),
    type(type_)
    {}

    // Constructor case when only arg is rvalue and cmd is lvalue
    expr(
    std::string &cmd_,
    std::string &&arg_,
    TokenType type_):
    cmd(cmd_),
    arg(arg_),
    type(type_)
    {}

    // Constructor case when only cmd is rvalue and arg is lvalue
    expr(
    std::string &&cmd_,
    std::string &arg_,
    TokenType type_):
    cmd(cmd_),
    arg(arg_),
    type(type_)
    {}
    // Constructor case when neither is rvalue
    expr(
    std::string &cmd_,
    std::string &arg_,
    TokenType type_):
    cmd(cmd_),
    arg(arg_),
    type(type_)
    {}
};


#endif