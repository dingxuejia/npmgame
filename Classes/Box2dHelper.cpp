//
//  Box2dHelper.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/17.
//
//

#include "Box2dHelper.h"
#include "GLES-Render.h"
USING_NS_CC;

static Box2dHelper* _box2dHelper = nullptr;

Box2dHelper* Box2dHelper::getInstence()
{
    if(!_box2dHelper)
    {
        _box2dHelper = new (std::nothrow) Box2dHelper();
        CCASSERT(_box2dHelper, "FATAL: Not enough memory");
        _box2dHelper->init();
    }
    return _box2dHelper;
}

bool Box2dHelper::init()
{
    _world=nullptr;
    return true;
}

b2World* Box2dHelper::createWorld(float gravityi, float gravityj)
{
    if (!_world) {
        CC_SAFE_DELETE(_world);
    }
    
    b2Vec2 gravity;
    gravity.Set(gravityi, gravityj);
    _world = new b2World(gravity);
    _world->SetAllowSleeping(true);
    _world->SetContinuousPhysics(true);
    GLESDebugDraw* debugDraw=new GLESDebugDraw(PTM_RATIO);
    //auto draw = b2Draw.e_aabbBit;
//    b2Draw *debugDraw;
    //debugDraw->SetFlags(0x0004);
    uint32 flag = 0;
    flag+= b2Draw::e_shapeBit;
    debugDraw->SetFlags(flag);
    _world->SetDebugDraw(debugDraw);
    //_world->SetContactListener(this);
    return _world;
}

b2World* Box2dHelper::getWorld()
{
    return _world;
}

b2Body* Box2dHelper::addNodeToWorld(Node *node,b2BodyType type)
{
    b2BodyDef spriteBodyDef;
    spriteBodyDef.type=type;
    spriteBodyDef.position.Set(node->getPositionX()/PTM_RATIO, node->getPositionY()/PTM_RATIO);
    spriteBodyDef.userData = node;
    
    b2Body* spritebody = _world->CreateBody(&spriteBodyDef);
    //sprite->setB2Body(spritebody);
    
    b2PolygonShape spriteShape;
    Size spriteSize = node->getContentSize();
    spriteShape.SetAsBox(spriteSize.width/PTM_RATIO, spriteSize.height/PTM_RATIO);
    
    b2FixtureDef spriteFix;
    spriteFix.density=Box2dDensity; //密度
    spriteFix.shape=&spriteShape;
    spriteFix.friction = Box2dFriction; //摩擦力
    spritebody->CreateFixture(&spriteFix);
    return spritebody;
}

void Box2dHelper::update(float dt)
{
    for (b2Body* b =_world->GetBodyList(); b; b=b->GetNext())
    {
        if (b->GetUserData()!=nullptr) {
            Node* sp = static_cast<Node*>(b->GetUserData());
            b2Vec2 pos = b->GetPosition();
            sp->setPosition(Vec2(pos.x*PTM_RATIO,pos.y*PTM_RATIO));
//            CCLOG("1%f",pos.y);
//            CCLOG("2%f",sp->getPositionY());
        }
    }
    _world->Step(dt, 8, 8);
}
