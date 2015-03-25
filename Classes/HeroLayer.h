//
//  gameLayer.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__gameLayer__
#define __pmgame__gameLayer__

#include "stdio.h"
#include "BaseLayer.h"

class HeroLayer:public BaseLayer
{
public:
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(HeroLayer);
    
private:
    AnimalNode* _animalnode;
    MapNode* _mapnode;
    b2Body* _heroBodyDef;
    
    //void HeroLeftGo(cocos2d::EventCustom* event);
    void HeroMove(int direction);
    //void HeroStopMove();
    void mapScheduleRight(float dt);
    void mapScheduleLeft(float dt);
    void addCustomEventListener();
    
};

#endif /* defined(__pmgame__gameLayer__) */
