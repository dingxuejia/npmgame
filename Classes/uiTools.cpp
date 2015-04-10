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

Button* uiTools::createButton(const char* normalfile,
                              const char* selectedfile,
                              const char* disablefile,
                              const cocos2d::ui::Button::ccWidgetTouchCallback& callback)
{
    selectedfile=selectedfile==nullptr?normalfile:selectedfile;
    disablefile = disablefile==nullptr?normalfile:disablefile;
    Button* button = Button::create(normalfile,selectedfile,disablefile);
    button->addTouchEventListener(callback);
    return button;
}

TextAtlas* uiTools::createTextAtlas(std::string value,
                                    std::string &charMapFile,
                                    int itemWidth,
                                    int itemHeight,
                                    const std::string &startCharMap)
{
    TextAtlas* textatlas = TextAtlas::create(value,charMapFile,itemWidth,itemHeight,startCharMap);
    return textatlas;
};

Node* uiTools::createProgressbar()
{
    //Label* label = Label::createWithCharMap
    return nullptr;
}

