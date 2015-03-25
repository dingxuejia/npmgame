//
//  HeroBaseData.cpp
//  npmgame
//
//  Created by 丁学佳 on 15/3/24.
//
//

#include "HeroBaseData.h"

static HeroBaseData* _heroBaseData=nullptr;

HeroBaseData* HeroBaseData::getInstence()
{
    if(!_heroBaseData)
    {
        _heroBaseData = new (std::nothrow) HeroBaseData();
        CCASSERT(_heroBaseData, "FATAL: Not enough memory");
        _heroBaseData->init();
    }
    return _heroBaseData;
}

//从存储数据的文件中读取数据进行初始化
void HeroBaseData::init()
{
    //读取数据
    //************
    //************
    //
    
    //暂时以固定数据代替
    _heroHp=5;
    _nowLevel = 1;
    _nowPm = 100;
    _isJump=false;
    _isAlive=true;
}