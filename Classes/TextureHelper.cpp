//
//  TextureHelper.cpp
//  npmgame
//
//  Created by 丁学佳 on 15/4/1.
//
//

#include "TextureHelper.h"
USING_NS_CC;

void TextureHelper::addSpriteFrameCache(const std::string &listname,const std::string &filename)
{
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile(listname, filename);
}

void TextureHelper::addTextureCache(const std::string &filename)
{
    auto textureCache = Director::getInstance()->getTextureCache();
    textureCache->addImage(filename);
    //textureCache->addImageAsync(const std::string &filepath, const std::function<void (Texture2D *)> &callback)
}