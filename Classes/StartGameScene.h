//
//  StartGameScene.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__StartGameScene__
#define __pmgame__StartGameScene__

#include "cocos2d.h"

class StartGameScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void startBtnCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(StartGameScene);
};

#endif /* defined(__pmgame__StartGameScene__) */
