//
//  Box2dHelper.h
//  pmgame
//  创建一个单例物理世界，可随时调用和销毁。所有物理相关的对象均保存在此类中
//  Created by 丁学佳 on 15/3/17.
//
//

#ifndef __pmgame__Box2dHelper__
#define __pmgame__Box2dHelper__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "stdio.h"

const float PTM_RATIO = 96;

class Box2dHelper
{
public:
    static Box2dHelper* getInstence();  //返回单例对象
    b2World* createWorld(float gravityi ,float gravityj);
    b2World* getWorld();
    b2Body* addNodeToWorld(cocos2d::Node* node,b2BodyType type); //添加物体
    void update(float dt);
    void ReleseWorld();
    //void addBodyForSprite(cocos2d::Sprite* sprite);
    //void addFixtureForSprite(cocos2d::Sprite* sprite);
private:
    b2World* _world;
    bool init();  //初始化
};
#endif /* defined(__pmgame__Box2dHelper__) */
