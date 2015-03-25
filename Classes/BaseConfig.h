//
//  BaseConfig.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__BaseConfig__
#define __pmgame__BaseConfig__

#include "cocos2d.h"


enum JudleEnum
{
    Left =1,
    Right =2,
    NotJudle = 0
};

//人物行走方向
enum DirectionEnum
{
    dLeft =-1 ,
    dRight =1
};

enum class HeroStateEnum
{
    Init=1,
    LeftRun=2,
    RightRun=3,
};

//enum CustomEventEnum
//{
//    LeftGo="LeftGo",//向左走
//    RightGo = "RightGo",
//    Jump="Jump",
//    Attack = "Attack"
//};

//物理世界密度
const float Box2dDensity=1;
//物理世界摩擦力
const float Box2dFriction=0;


class BaseConfig
{
public:
    
};

#endif /* defined(__pmgame__BaseConfig__) */
