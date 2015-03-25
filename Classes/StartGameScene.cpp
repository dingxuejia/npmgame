//
//  StartGameScene.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "StartGameScene.h"
#include "uiTools.h"

USING_NS_CC;

Scene* StartGameScene::createScene()
{
    auto scene = Scene::create();
    auto layer =StartGameScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartGameScene::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto btnMenuItm = MenuItemFont::create("开始");
    btnMenuItm->setPosition(Vec2(50,50));
    btnMenuItm->setCallback(CC_CALLBACK_1(StartGameScene::startBtnCallback,this));
    
    auto menuItemEnd = MenuItemFont::create("结束");
    menuItemEnd->setPosition(Vec2(visibleSize.width-50,50));
    menuItemEnd->setCallback([](Ref* pSender){Director::getInstance()->end();});
    auto btnMenu = Menu::create(btnMenuItm, menuItemEnd,NULL);
    btnMenu->setPosition(0,0);

    this->addChild(btnMenu);
    return true;
}

void StartGameScene::startBtnCallback(Ref* pSender)
{
    Director::getInstance()->end();
}