//
//  AnimalNode.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/16.
//
//

#include "AnimalNode.h"

USING_NS_CC;

//AnimalNode::AnimalNode()
//{
//    
//}

//AnimalNode::AnimalNode(const char* file)
//{
//    _animalSprite = Sprite::create(file);
//    _animalSprite->setAnchorPoint(Vec2(0,0));
//    this->setAnchorPoint(Vec2(0,0));
//    this->addChild(_animalSprite);
//}

//bool AnimalNode::init()
//{
//    _animalSprite = Sprite::create("file");
//    _animalSprite->setAnchorPoint(Vec2(0,0));
//    this->setAnchorPoint(Vec2(0,0));
//    this->addChild(_animalSprite);
//}

void AnimalNode::InitNode(const char *file)
{
    _animalSprite = Sprite::create(file);
    _animalSprite->setAnchorPoint(Vec2(0,0));
    this->setContentSize(_animalSprite->getContentSize());
    this->setAnchorPoint(Vec2(0,0));
    this->addChild(_animalSprite);
}

void AnimalNode::Move(int direction, int distance)
{
    if(direction==DirectionEnum::dRight)
    {
        this->setPositionX(this->getPositionX()+distance);
    }
    else
    {
        this->setPositionX(this->getPositionX()-distance);
    }
}

void AnimalNode::Attack(AnimalNode* enemy)
{
    
}

void AnimalNode::BeAttack()
{
    
}

void AnimalNode::Jump(int time,cocos2d::Vec2 vec,int height)
{
    //auto action =JumpBy::create(time, vec,height,1);
}

void AnimalNode::DestoryNode()
{
    
}

void AnimalNode::PlayAnimation(Animation &animation)
{
    
}