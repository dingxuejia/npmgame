//
//  GameScene.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "GameScene.h"

bool GameScene::init()
{
    _herolayer = HeroLayer::create();
    this->addChild(_herolayer);
    
    _operlayer = OperLayer::create();
    this->addChild(_operlayer);
    return true;
}