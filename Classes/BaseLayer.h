//
//  BaseLayer.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/19.
//
//

#ifndef __pmgame__BaseLayer__
#define __pmgame__BaseLayer__

#include "cocos2d.h"

class BaseLayer : public cocos2d::Layer
{
public:
    cocos2d::Size getWinSize();
    cocos2d::Size getVisbleSize();
    cocos2d::Size getFrameSize();
    cocos2d::Vec2 getVisibleOrigin();
};

#endif /* defined(__pmgame__BaseLayer__) */
