#include "leonardo.hpp"
#include "regex_handler.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

#define _USE_MATH_DEFINES
#include <cmath>

void execute(std::vector<expr> &list);
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

bool moved = false;
bool is_down = false;
double x = 0;
double y = 0;
double deg = 0;
std::string clr = "#0000FF";

void execute(std::vector<expr> &list){
    for (expr exp :list){
        if (match(exp.cmd, "up")) up();
        else if(match(exp.cmd, "down")) down();
        else if(match(exp.cmd, "right")) right(stoi(exp.arg));
        else if(match(exp.cmd, "left")) left(stoi(exp.arg));
        else if(match(exp.cmd, "forw")) forw(stoi(exp.arg));
        else if(match(exp.cmd, "back")) back(stoi(exp.arg));
        else if(match(exp.cmd, "color")) color(exp.arg);

        if(moved && is_down){
            print_result();
        }
        moved = false;
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
    return input;
}


void up(){
    is_down = false;
}

void down(){
    is_down = true;
}

void right(int &&arg){
    deg += arg;
}

void left(int &&arg){
    deg -= arg;
}

void forw(int &&arg){
    old_x = x;
    old_y = y;
    x += arg*cos(M_PI*deg/180);
    y -= arg*sin(M_PI*deg/180);
    moved = true;
}

void back(int &&arg){
    old_x = x;
    old_y = y;
    x -= arg*cos(M_PI*deg/180);
    y += arg*sin(M_PI*deg/180);
    moved = true;
}

void color(std::string arg){
    clr = arg;
}