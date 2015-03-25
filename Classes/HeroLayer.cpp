//
//  gameLayer.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "HeroLayer.h"
#include <math.h>

USING_NS_CC;

bool HeroLayer::init()
{
    _animalnode = AnimalNode::create();
    _animalnode->InitNode("CloseNormal.png");
    _animalnode->setAnchorPoint(Vec2(0,0));
    _animalnode->setPosition(Vec2(getVisbleSize().width*0.5,0));
    //_animalnode->setContentSize(Size(Vec2(100,100)));
    this->addChild(_animalnode,1);
    
    _mapnode = MapNode::create();
    _mapnode->InitMap("back.jpg");
    _mapnode->setPosition(Vec2(-9,0));
    this->addChild(_mapnode,0);
    
    auto floor = Sprite::create("floor.png");
    floor->setContentSize(Size(Vec2(1000,1)));
    floor->setPosition(0,0);
    this->addChild(floor,1);
    
    auto floor2 = Sprite::create("floor2.png");
    floor2->setPosition(getVisbleSize().width,0);
    this->addChild(floor2,1);
    
//    auto test = Sprite::create("CloseNormal.png");
//    test->setPosition(100,200);
//    this->addChild(test,2);
    
    auto b2d = Box2dHelper::getInstence();
    b2d->createWorld(0, -10);
    _heroBodyDef = b2d->addNodeToWorld(_animalnode,b2_dynamicBody);
    b2d->addNodeToWorld(floor, b2_staticBody);
    b2d->addNodeToWorld(floor2, b2_staticBody);
    
    
    addCustomEventListener();
    this->scheduleUpdate();
    
    return true;
}

void HeroLayer::addCustomEventListener()
{
    
    //添加自定义事件监听
    customEventHelper::createCustomEventListener("LeftGo", [=](EventCustom* event)
                                                 {
                                                     //_heroBodyDef->ApplyForceToCenter(b2Vec2(-100,0), true);
                                                     HeroMove(DirectionEnum::dLeft);
                                                 });
    
    customEventHelper::createCustomEventListener("RightGo", [=](EventCustom* event)
                                                 {
                                                     //_heroBodyDef->ApplyForceToCenter(b2Vec2(100,0), true);
                                                     HeroMove(DirectionEnum::dRight);
                                                 });
    customEventHelper::createCustomEventListener("Jump", [=](EventCustom* event)
                                                 {
                                                     _heroBodyDef->ApplyForceToCenter(b2Vec2(0,200), true);
                                                     //_heroBodyDef->SetAwake(false);
                                                 });
    customEventHelper::createCustomEventListener("EndMove", [=](EventCustom* event)
                                                 {
                                                     this->unschedule(schedule_selector(HeroLayer::mapScheduleRight));
                                                     this->unschedule(schedule_selector(HeroLayer::mapScheduleLeft));
                                                 });
}

void HeroLayer::update(float dt)
{
    //CCLOG("3%f",_animalnode->getPositionY());
    Box2dHelper::getInstence()->update(dt);
}


void HeroLayer::HeroMove(int direction)
{
    if(direction == DirectionEnum::dRight)
        this->schedule(schedule_selector(HeroLayer::mapScheduleRight),0.016);
    else
        this->schedule(schedule_selector(HeroLayer::mapScheduleLeft),0.016);
}



//下面是 人物可以走到地图边缘  需要检测边缘判断是人移动还是地图移动  超级蛋痛    暂时不做  未完成版
//void HeroLayer::HeroMove(int direction)
//{
//    //地图达到右边届
//    if (_mapnode->getJudleMap()==JudleEnum::Right)
//    {
//        if (fabsf(_animalnode->getPositionX()-getVisbleSize().width*0.5)>5)
//        {
//            _heroBodyDef->ApplyForceToCenter(b2Vec2(100*direction,0),true);
//        }
//        else if (fabsf(_animalnode->getPositionX()-getVisbleSize().width*0.5)<=5)
//        {
//            if (direction == DirectionEnum::dRight)
//            {
//                _heroBodyDef->ApplyForceToCenter(b2Vec2(100,0), true);
//            }
//            else
//            {
//                this->schedule(schedule_selector(HeroLayer::mapMoveSch),0.16);
//                //_mapnode->MoveMap(_animalnode, getVisbleSize(), 10, -direction);
//            }
//        }
//    }
//    else if (_mapnode->getJudleMap()==JudleEnum::Left)
//    {
//        CCLOG("%f",_animalnode->getPositionX());
//        CCLOG("%f",getVisbleSize().width*0.5);
//        if(fabsf(_animalnode->getPositionX()-getVisbleSize().width*0.5)>5)
//        {
//            _heroBodyDef->ApplyForceToCenter(b2Vec2(100*direction,0), true);
//        }
//        else if(fabsf(_animalnode->getPositionX()-getVisbleSize().width*0.5)<=5)
//        {
//            if (direction == DirectionEnum::dLeft)
//            {
//                _heroBodyDef->ApplyForceToCenter(b2Vec2(-100,0), true);
//            }
//            else
//            {
//                this->schedule(schedule_selector(HeroLayer::mapMoveSch),0.16);
//                //_mapnode->MoveMap(_animalnode, getVisbleSize(), 10, -direction);
//            }
//        }
//    }
//    else
//    {
//         this->schedule(schedule_selector(HeroLayer::mapMoveSch),0.16);
//    }
//}
//

void HeroLayer::mapScheduleRight(float dt)
{
    _mapnode->MoveMap(_animalnode, getVisbleSize(), 2,DirectionEnum::dRight);
    //Box2dHelper::getInstence()->getWorld()->set
}

void HeroLayer::mapScheduleLeft(float dt)
{
    _mapnode->MoveMap(_animalnode, getVisbleSize(), 2,DirectionEnum::dLeft);
}



