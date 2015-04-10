//
//  animationTools.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__animationTools__
#define __pmgame__animationTools__

#include "cocos2d.h"

class animationTools
{
public:
    //用于一组组装好的图片封装成动画
    static cocos2d::Animation* CreateAniWithSpriteFrame(std::string frameName,
                                                        std::string suffixname,//后缀名
                                                        int begin,
                                                        int end,
                                                        float delay,
                                                        int loops);
};

#endif /* defined(__pmgame__animationTools__) */
