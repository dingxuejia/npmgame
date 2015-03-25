//
//  GameScene.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__GameScene__
#define __pmgame__GameScene__

#include "cocos2d.h"
#include "stdio.h"
#include "HeroLayer.h"
#include "OperLayer.h"
#include "InfoAndAnimationLayer.h"

class GameScene : public cocos2d::Scene
{
public:
    virtual bool init();
    CREATE_FUNC(GameScene);
private:
    AnimalNode* _hero;
    cocos2d::Layer* _herolayer;
    cocos2d::Layer* _operlayer;
};

#endif /* defined(__pmgame__GameScene__) */
