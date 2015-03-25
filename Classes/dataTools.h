//
//  dataTools.h
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#ifndef __pmgame__dataTools__
#define __pmgame__dataTools__

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

class dataTools
{
public:
    void getFileContent(const char* filename);
    //只能用于只有1级子元素的情况
    static std::string getValueFromXml(const char* filename,const char* key);
    static void setValueForXml(const char* filename,const char* key,const char* value);
    static tinyxml2::XMLElement* getElementFromXml(const char* filename,const char* key);
    static tinyxml2::XMLElement* getElementFromXml(tinyxml2::XMLDocument* doc,const char* key);
    
    //添加游戏基本属性文件
    static void addGameDataXml();
private:
    static const char* encode(std::string str);
    static const char* decode(std::string str);
};

#endif /* defined(__pmgame__dataTools__) */
