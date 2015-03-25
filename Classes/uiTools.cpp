//
//  uiTools.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "uiTools.h"

USING_NS_CC;
using namespace ui;

Button* uiTools::createButton(const char* normalfile,const char* selectedfile,const char* disablefile,const cocos2d::ui::Button::ccWidgetTouchCallback& callback)
{
    auto button = Button::create(normalfile,selectedfile,disablefile);
    button->addTouchEventListener(callback);
    return button;
}

Node* uiTools::createProgressbar()
{
    return nullptr;
}

