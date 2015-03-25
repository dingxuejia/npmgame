//
//  BaseLayer.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/19.
//
//

#include "BaseLayer.h"

USING_NS_CC;

Size BaseLayer::getWinSize()
{
    return Director::getInstance()->getWinSize();
}

Size BaseLayer::getVisbleSize()
{
    return Director::getInstance()->getVisibleSize();
}

Vec2 BaseLayer::getVisibleOrigin()
{
    return Director::getInstance()->getVisibleOrigin();
}

Size BaseLayer::getFrameSize()
{
    return Director::getInstance()->getOpenGLView()->getFrameSize();
}