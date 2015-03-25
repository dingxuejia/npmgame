#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0,-50));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //创建一个物理世界, 大小和屏幕的尺寸相同, 使用默认材质, debug框的宽度为3个像素
    auto body = PhysicsBody::createEdgeBox( visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    //创建一个碰撞图形
    auto edgeShape = Node::create();
    //将图形和刚刚创建的世界绑定
    edgeShape->setPhysicsBody( body);
    //设置图形的位置在屏幕正中间
    edgeShape->setPosition( visibleSize.width / 2, visibleSize.height / 2);
    //添加进图层
    this->addChild( edgeShape);
    
    
    auto sbody = Sprite::create( "CloseNormal.png");
    p1 = PhysicsBody::createCircle( sbody->getContentSize().width/2);
    //设置一个正方形绑定在精灵上面
    sbody->setPhysicsBody(p1);
    sbody->setPosition(Vec2(100,visibleSize.height));
    this->addChild(sbody);
    
    
    auto sbody2 = Sprite::create("HelloWorld.png");
    //设置一个正方形绑定在精灵上面
    auto pbody = PhysicsBody::createBox( sbody2->getContentSize());
    pbody->setDynamic(false);
    sbody2->setPhysicsBody(pbody);
    sbody2->setPosition(Vec2(100,visibleSize.height-300));
    this->addChild(sbody2);
    
    //    auto nodea = Sprite::create("HelloWorld.png");
    //    nodea->setPosition(visibleSize.width*0.5,visibleSize.height*0.5);
    //    this->addChild(nodea);
    //    nodea->addChild(sbody);
    //    nodea->runAction(MoveBy::create(5, Vec2(1000,1000)));
    this->scheduleOnce(schedule_selector(HelloWorld::forceupdate), 5);
    
    return true;
}

void HelloWorld::forceupdate(float dt)
{
    p1->applyImpulse(Vec2(100,40000));//给冲力
    //this->scheduleOnce(schedule_selector(HelloWorld::endupdate), 2);
}

void HelloWorld::endupdate(float dt)
{
    p1->applyForce(Vec2(-100,-10000));//给恒力
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
