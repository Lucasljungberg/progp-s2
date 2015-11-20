#include "leonardo.hpp"
#include "regex_handler.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

#define _USE_MATH_DEFINES
#include <cmath>

void execute(std::list<expr> &list);
void print_result();
double round_num(double input, int precision);

void up();
void down();
void right(int &&arg);
void left(int &&arg);
void forw(int &&arg);
void back(int &&arg);
void color(std::string arg);

double old_x = 0;
double old_y = 0;

bool is_down = false;
double x = 0;
double y = 0;
int deg = 0;
std::string clr = "#0000FF";

void execute(std::list<expr> &list){
    for (expr exp :list){
        if (!exp.cmd.compare("UP")) up();
        else if(!exp.cmd.compare("DOWN")) down();
        else if(!exp.cmd.compare("RIGHT")) right(stoi(exp.arg));
        else if(!exp.cmd.compare("LEFT")) left(stoi(exp.arg));
        else if(!exp.cmd.compare("FORW")) forw(stoi(exp.arg));
        else if(!exp.cmd.compare("BACK")) back(stoi(exp.arg));
        else if(!exp.cmd.compare("COLOR")) color(exp.arg);
    }
}

void print_result(){
    std::cout << std::left << std::fixed << std::setw(8) << clr;
    std::cout << std::left << std::fixed << std::setw(8) << std::setprecision(4) << round_num(old_x, 4);
    std::cout << std::left << std::fixed << std::setw(8) << std::setprecision(4) << round_num(old_y, 4);
    std::cout << std::left << std::fixed << std::setw(8) << std::setprecision(4) << round_num(x, 4);
    std::cout << std::left << std::fixed << std::setw(8) << std::setprecision(4) << round_num(y, 4);
    std::cout << std::endl;
}

double round_num(double input, int precision){
    std::stringstream s;
    s << std::setprecision(precision) << std::setiosflags(std::ios_base::fixed) << input;
    s >> input;
    return std::max(0.0000, input);
}


void up(){
    is_down = false;
}

void down(){
    is_down = true;
}

void right(int &&arg){
    deg -= arg;
}

void left(int &&arg){
    deg += arg;
}

void forw(int &&arg){
    old_x = x;
    old_y = y;
    x += arg*cos(M_PI*deg/180);
    y += arg*sin(M_PI*deg/180);
    if (is_down)
        print_result();
}

void back(int &&arg){
    forw(std::move(-arg));
}

void color(std::string arg){
    clr = arg;
}