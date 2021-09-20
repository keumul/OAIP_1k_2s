#pragma once
#include<iostream> 
#include<string>
struct Symbol
{
    std::string info;
    Symbol* next;
};
void create(Symbol** begin, Symbol** end, std::string p);
void view(Symbol* begin);
void delto(Symbol** begin, Symbol** p);