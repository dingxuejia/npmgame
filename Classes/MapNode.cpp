//
//  MapNode.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/16.
//
//

#include "MapNode.h"
#include "BaseConfig.h"

USING_NS_CC;

void MapNode::InitMap(const char* file)
{
    mapSprite = Sprite::create(file);
    mapSprite->setAnchorPoint(Vec2(0,0));
    this->setAnchorPoint(Vec2(0,0));
    this->addChild(mapSprite);
    _isJudle=JudleEnum::Left;
}

//当地图到达某个边界时，均为英雄自己的移动
//当地图没达到边界时，均为地图的移动
//固整个移动的流程为，判断地图是否达到边界，到达边界，根据玩家的位置和左右边界进行相应玩家移动
//没有达到边界，地图移动
void MapNode::MoveMap(Node* hero, Size visbleSize,int distance,int direction)
{
    if(this->getPositionX()<=-(mapSprite->getContentSize().width-visbleSize.width)) //到达地图最右边
    {
        if(direction==DirectionEnum::dRight)
            _isJudle=JudleEnum::Right;
        else
        {
            this->setPositionX(this->getPositionX()-distance*direction);
            _isJudle = JudleEnum::NotJudle;
        }
    }
    else if(this->getPositionX()>=0) //达到地图最左边
    {
        if (direction==DirectionEnum::dLeft)
            _isJudle = JudleEnum::Left;
        else
        {
            this->setPositionX(this->getPositionX()-distance*direction);
            _isJudle = JudleEnum::NotJudle;
        }
    }
    else
    {
        this->setPositionX(this->getPositionX()-distance*direction);
        _isJudle = JudleEnum::NotJudle;
    }
}

int MapNode::getJudleMap()
{
    return _isJudle;
}

Vec2 MapNode::getMapPosition()
{
    return this->getPosition();
}