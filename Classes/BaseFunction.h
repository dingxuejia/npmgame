//
//  BaseFunction.h
//  一些cocos相关的通用方法
//
//  Created by 丁学佳 on 15/3/19.
//
//

#ifndef __pmgame__BaseFunction__
#define __pmgame__BaseFunction__

#include "cocos2d.h"

class BaseFunction
{
public:
    //int转换为string
    static std::string inttostring(int int_tmp);
    //string转换为int
    static int stringtoint(std::string &str_temp);
};

#endif /* defined(__pmgame__BaseFunction__) */
