//
//  uiTools.h
//
//  ui工具类，封装快捷创建ui对象的方法
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__uiTools__
#define __pmgame__uiTools__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class uiTools
{
public:
    static cocos2d::ui::Button* createButton(const char* normalfile,
                                             const char* selectedfile,
                                             const char* disablefile,
                                             const cocos2d::ui::Button::ccWidgetTouchCallback& callback);
    static cocos2d::ui::TextAtlas* createTextAtlas(std::string value,
                                                   std::string &charMapFile,
                                                   int itemWidth,
                                                   int itemHeight,
                                                   const std::string &startCharMap);
    
    static cocos2d::Node* createProgressbar();
    static cocos2d::MenuItem* createMenuItem(const char* type,const char* filename,const char* word,const cocos2d::ccMenuCallback &callback);
};

#endif /* defined(__pmgame__uiTools__) */
