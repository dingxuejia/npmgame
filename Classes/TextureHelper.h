//
//  TextureHelper.h
//  npmgame
//
//  Created by 丁学佳 on 15/4/1.
//
//

#ifndef __npmgame__TextureHelper__
#define __npmgame__TextureHelper__

#include "cocos2d.h"

class TextureHelper
{
public:
    static void addSpriteFrameCache(const std::string &listname,const std::string &filename);
    static void addTextureCache(const std::string &filename);
};

#endif /* defined(__npmgame__TextureHelper__) */
