#include "ansilib.h"

void __ANSI_FRONTCOLOR_SET_NOR(size_t parameter)
{
    std::cout<<"\033["<<parameter<<"m";
}

void __ANSI_FRONTCOLOR_SET_ADV(size_t color_code)
{
    std::cout<<"\033[48;5;"<<color_code<<"m";
}