//
//  MapNode.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/16.
//
//

#ifndef __pmgame__MapNode__
#define __pmgame__MapNode__

#include "cocos2d.h"
#include "stdio.h"

class MapNode: public cocos2d::Node
{
public:
    //MapNode();
    //~MapNode();
    void InitMap(const char* file); //根据图片定义地图
    void MoveMap(cocos2d::Node* hero,cocos2d::Size visbleSize,int distance,int direction); //移动地图
    int getJudleMap(); //判断是否达到地图边界
    cocos2d::Vec2 getMapPosition();
    CREATE_FUNC(MapNode);
private:
    cocos2d::Sprite* mapSprite;
    int _isJudle; //纪录地图是否达到边界
};

#endif /* defined(__pmgame__MapNode__) */
