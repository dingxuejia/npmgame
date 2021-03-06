//
//  InfoAndAnimationLayer.cpp
//  npmgame
//
//  Created by 丁学佳 on 15/3/25.
//
//

#include "InfoAndAnimationLayer.h"

USING_NS_CC;

bool InfoAndAnimLayer::init()
{
    addCustomEventListener();
    return true;
}

void InfoAndAnimLayer::addHpShow(int num)
{
    std::string str="HP:"+BaseFunction::inttostring(num);
    _hpLabel = LabelTTF::create(str, "Arial", 20);
    _hpLabel->setPosition(getVisbleSize().width*0.1,getVisbleSize().height*0.9);
    _hpLabel->setColor(Color3B(255,0,0));
    this->addChild(_hpLabel);
}

void InfoAndAnimLayer::addPmShow(int num)
{
    std::string str = "PM:"+BaseFunction::inttostring(num);
    _pmLabel = Label::createWithSystemFont(str, "Arial", 20);
    _pmLabel->setPosition(getVisbleSize().width*0.2,getVisbleSize().height*0.9);
    _pmLabel->setColor(Color3B(255,0,0));
    this->addChild(_pmLabel);
}

void InfoAndAnimLayer::addLevelShow(int num)
{
    
}

void InfoAndAnimLayer::addCustomEventListener()
{
    
}

void InfoAndAnimLayer::changeHp(int nownum)
{
    _hpLabel->setString("HP:"+BaseFunction::inttostring(nownum));
}

void InfoAndAnimLayer::changePm(int nowNum)
{
    _pmLabel->setString("PM:"+BaseFunction::inttostring(nowNum));
}

void InfoAndAnimLayer::playAnimation(Vec2 pos, Animation* anima)
{
    
}