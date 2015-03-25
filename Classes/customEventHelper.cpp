//
//  customEventHelper.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/20.
//
//

#include "customEventHelper.h"

USING_NS_CC;

//创建事件监听
EventListenerCustom* customEventHelper::createCustomEventListener(const std::string& eventname, const std::function<void(EventCustom*)> &callback)
{
    auto _eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerCustom::create(eventname, callback);
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
    //_eventDispatcher->addCustomEventListener(eventname, callback);
    return listener;
}

//分发事件
bool customEventHelper::dispatchCustomEvent(const std::string& eventname,void* userdata)
{
    auto _eventDispatcher = Director::getInstance()->getEventDispatcher();
    _eventDispatcher->dispatchCustomEvent(eventname,userdata);
    return true;
}

bool customEventHelper::isEventListenerExist(EventListener::ListenerID &listenerId)
{
    return true;
}

void customEventHelper::removeCustomEventListener(EventListener::ListenerID &listenerId)
{
    auto _eventDispatcher = Director::getInstance()->getEventDispatcher();
    _eventDispatcher->removeCustomEventListeners(listenerId);
}