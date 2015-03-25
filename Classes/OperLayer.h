//
//  OperLayer.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/17.
//
//

#ifndef __pmgame__OperLayer__
#define __pmgame__OperLayer__

#include "cocos2d.h"
#include "BaseLayer.h"
#include "stdio.h"

class OperLayer:public BaseLayer
{
public:
    bool virtual init();
    void addDirecButton();
    CREATE_FUNC(OperLayer);
private:
    bool isNodeContainPoint(cocos2d::Node* node,cocos2d::Vec2 pos);
    
    void leftButtonTouch(Ref* psender, cocos2d::ui::Widget::TouchEventType type);
    void rightButtonTouch(Ref* psender, cocos2d::ui::Widget::TouchEventType type);
    void jumpButtonTouch(Ref* psender,cocos2d::ui::Widget::TouchEventType type);
    
//    cocos2d::Menu* _menu;
//    cocos2d::Vector<Node*> _dirNode;
};

#endif /* defined(__pmgame__OperLayer__) */
