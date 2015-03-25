//
//  BaseData.h
//  基础数据类，管理游戏中的全局数据
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__BaseData__
#define __pmgame__BaseData__

#include "cocos2d.h"

class BaseData
{
public:
    int static inline getPmValue(){return _pmvalue;};
    void static inline setPmValue(int value){_pmvalue = value;};
private:
    int static _pmvalue;
};

#endif /* defined(__pmgame__BaseData__) */
