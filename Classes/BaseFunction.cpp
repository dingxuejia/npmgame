//
//  BaseFunction.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/19.
//
//

#include "BaseFunction.h"
#include <sstream>

using namespace std;

string BaseFunction::inttostring(int int_tmp)
{
    string str_temp;
    stringstream stream;
    
    stream<<int_tmp;
    str_temp=stream.str();
    
    return str_temp;
}

int BaseFunction::stringtoint(std::string &str_temp)
{
    int int_tmp;
    stringstream stream(str_temp);
    
    stream>>int_tmp;
    
    return int_tmp;
}