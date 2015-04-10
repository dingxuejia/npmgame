//
//  animationTools.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "animationTools.h"

USING_NS_CC;

Animation* animationTools::CreateAniWithSpriteFrame(std::string frameName,
                                                    std::string suffixname,
                                                    int begin,
                                                    int end,
                                                    float delay,
                                                    int loops)
{
    auto frameCache = SpriteFrameCache::getInstance();
    
    Vector<SpriteFrame*> frameVector;
    for (int i =begin; i<=end; i++) {
        std::string str = StringUtils::format("%d",i);
        str=frameName+str+suffixname;
        auto spriteFrame = frameCache->getSpriteFrameByName(str);
        frameVector.pushBack(spriteFrame);
    }
    auto animation = Animation::createWithSpriteFrames(frameVector);
    animation->setDelayPerUnit(delay);
    animation->setLoops(loops);
    return animation;
}