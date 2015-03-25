//
//  gameInit.cpp
//  npmgame
//
//  Created by 丁学佳 on 15/3/25.
//
//

#include "gameInit.h"

void gameInit::gameInitialise()
{
    dataTools::addGameDataXml();//如果没有配置文件，则添加配置文件
    
    HeroBaseData::getInstence();//初始化英雄基本数据
}