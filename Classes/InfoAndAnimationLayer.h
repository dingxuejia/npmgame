//
//  InfoAndAnimationLayer.h
//  npmgame
//
//  Created by 丁学佳 on 15/3/25.
//
//

#ifndef __npmgame__InfoAndAnimationLayer__
#define __npmgame__InfoAndAnimationLayer__

//用于存放显示玩家信息ui和播放动画

#include "BaseLayer.h"
#include "stdio.h"

class InfoAndAnimLayer:public BaseLayer
{
public:
    void addHpShow(int num);
    void addPmShow(int num);
    void addLevelShow(int num);
    
    void changeHp(int nowNum);
    void changePm(int nowNum);
    
    bool virtual init();
    CREATE_FUNC(InfoAndAnimLayer);
private:
    void addCustomEventListener();
    void playAnimation(cocos2d::Vec2 pos,cocos2d::Animation* anima);
    
    cocos2d::LabelTTF* _hpLabel;
    cocos2d::Label* _pmLabel;
};

#endif /* defined(__npmgame__InfoAndAnimationLayer__) */
