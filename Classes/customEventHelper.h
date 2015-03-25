//
//  customEventHelper.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/20.
//
//

#ifndef __pmgame__customEventHelper__
#define __pmgame__customEventHelper__

#include "cocos2d.h"

class customEventHelper
{
public:
    static cocos2d::EventListenerCustom* createCustomEventListener(const std::string& eventName, const std::function<void(cocos2d::EventCustom*)> &callback);
    static bool dispatchCustomEvent(const std::string& eventName,void* userdata);
    static bool isEventListenerExist(cocos2d::EventListener::ListenerID& listenerId);
    static void removeCustomEventListener(cocos2d::EventListener::ListenerID& listenerId);
    //cocos2d::EventListenerCustom* getEventListener(cocos2d::EventListener::ListenerID& listenerId);
};

#endif /* defined(__pmgame__customEventHelper__) */
