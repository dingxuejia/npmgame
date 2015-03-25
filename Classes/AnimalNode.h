//
//  AnimalNode.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/16.
//
//

#ifndef __pmgame__AnimalNode__
#define __pmgame__AnimalNode__

#include "cocos2d.h"
#include "stdio.h"

class AnimalNode:public cocos2d::Node
{
public:
    //AnimalNode();
    //AnimalNode(const char* file);
    //~AnimalNode();
    //bool virtual init();
    void InitNode(const char* file); //初始化
    void Move(int direction,int distance); //移动
    void Jump(int time,cocos2d::Vec2 vec,int height); //跳跃
    void Attack(AnimalNode* enemy); //攻击
    void BeAttack(); //被攻击
    void DestoryNode(); //销毁对象
    void PlayAnimation(cocos2d::Animation &animation);
    CREATE_FUNC(AnimalNode);
private:
    cocos2d::Sprite* _animalSprite;
    int _hpValue;
};

#endif /* defined(__pmgame__AnimalNode__) */
