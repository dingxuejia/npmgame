//
//  OperLayer.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/17.
//
//

#include "OperLayer.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

bool OperLayer::init()
{
    addDirecButton();
    
//    auto dispatcher = Director::getInstance()->getEventDispatcher();
//    auto listner = EventListenerTouchOneByOne::create();
//    listner->onTouchBegan=CC_CALLBACK_2(OperLayer::onTouchBegan, this);
//    listner->onTouchMoved=CC_CALLBACK_2(OperLayer::onTouchMoved, this);
//    listner->onTouchEnded=CC_CALLBACK_2(OperLayer::onTouchEnded, this);
//    listner->onTouchCancelled = CC_CALLBACK_2(OperLayer::onTouchCancelled,this);
//    dispatcher->addEventListenerWithSceneGraphPriority(listner, this);
    return true;
}

void OperLayer::addDirecButton()
{
    auto leftButton = uiTools::createButton("CloseNormal.png", "", "", CC_CALLBACK_2(OperLayer::leftButtonTouch,this));
    leftButton->setPosition(Vec2(getVisibleOrigin().x+20,getVisbleSize().height*0.75));
    this->addChild(leftButton);
    
    auto rightButton = uiTools::createButton("CloseNormal.png", "", "", CC_CALLBACK_2(OperLayer::rightButtonTouch,this));
    rightButton->setPosition(Vec2(getVisibleOrigin().x+100,getVisbleSize().height*0.75));
    this->addChild(rightButton);
    
    auto jumpButton = uiTools::createButton("CloseNormal.png", "", "", CC_CALLBACK_2(OperLayer::jumpButtonTouch,this));
    jumpButton->setPosition(Vec2(getVisbleSize().width*0.75,getVisbleSize().height*0.25));
    this->addChild(jumpButton);
        
}

//判断点是否在节点的范围内
bool OperLayer::isNodeContainPoint(Node *node,Vec2 pos)
{
    auto size = node->getContentSize();
    auto rect = Rect(node->getPositionX(), node->getPositionY(), size.width, size.height);
    if (rect.containsPoint(pos)) {
        return true;
    }
    return false;
}

void OperLayer::rightButtonTouch(Ref *psender, Widget::TouchEventType type)
{
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            customEventHelper::dispatchCustomEvent("RightGo",nullptr);
            break;
        case Widget::TouchEventType::MOVED:
            break;
        case Widget::TouchEventType::ENDED:
            customEventHelper::dispatchCustomEvent("EndMove",nullptr);
            break;
        case Widget::TouchEventType::CANCELED:
            customEventHelper::dispatchCustomEvent("EndMove",nullptr);
            break;
        default:
            break;
    }
}

void OperLayer::leftButtonTouch(Ref *psender, Widget::TouchEventType type)
{
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            customEventHelper::dispatchCustomEvent("LeftGo",nullptr);
            break;
        case Widget::TouchEventType::MOVED:
            break;
        case Widget::TouchEventType::ENDED:
            customEventHelper::dispatchCustomEvent("EndMove",nullptr);
            break;
        case Widget::TouchEventType::CANCELED:
            customEventHelper::dispatchCustomEvent("EndMove",nullptr);
            break;
        default:
            break;
    }
}

void OperLayer::jumpButtonTouch(Ref* psender, Widget::TouchEventType type)
{
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            customEventHelper::dispatchCustomEvent("Jump",nullptr);
            break;
        case Widget::TouchEventType::MOVED:
            break;
        case Widget::TouchEventType::ENDED:
            break;
        case Widget::TouchEventType::CANCELED:
            break;
        default:
            break;
    }
}



