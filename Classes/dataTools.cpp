//
//  dataTools.cpp
//  pmgame
//
//  Created by 丁学佳 on 15/3/13.
//
//

#include "dataTools.h"

using namespace tinyxml2;
USING_NS_CC;

void dataTools::getFileContent(const char* filename)
{
    
}

std::string dataTools::getValueFromXml(const char *filename, const char *key)
{
    auto node = getElementFromXml(filename, key);
    if(node)
        return node->GetText();
    return "";
}

void dataTools::setValueForXml(const char* filename, const char* key, const char* value)
{
    std::string path = FileUtils::getInstance()->fullPathForFilename(filename);
    auto doc = new XMLDocument();
    auto xmlError = doc->LoadFile(path.c_str());
    if (xmlError!=0)
    {
        delete doc;
        return;
    }
    auto node = getElementFromXml(doc, key);
    if (node) {
        node->SetValue(value);
    }
    
    doc->SaveFile(path.c_str());
    
    delete doc;
}

XMLElement* dataTools::getElementFromXml(const char* filename,const char* key)
{
    std::string path = FileUtils::getInstance()->fullPathForFilename(filename);
    auto doc = new XMLDocument();
    auto xmlError = doc->LoadFile(path.c_str());
    if (xmlError!=0)
    {
        delete doc;
        return nullptr;
    }
    
    //得到跟元素
    auto root = doc->RootElement();
    
    //遍历子元素
    for (auto node = root->FirstChildElement(); node; node->NextSiblingElement())
    {
        CCLOG("%s,%s",node->Name(),node->GetText());
        if (node->Name()==key)
        {
            return node;
        }
    }
    delete doc;
    return  nullptr;
}

XMLElement* dataTools::getElementFromXml(XMLDocument* doc,const char* key)
{
    //得到跟元素
    auto root = doc->RootElement();
    
    //遍历子元素
    for (auto node = root->FirstChildElement(); node; node->NextSiblingElement())
    {
        CCLOG("%s,%s",node->Name(),node->GetText());
        if (node->Name()==key)
        {
            return node;
        }
    }
    
    return  nullptr;
}

void dataTools::addGameDataXml()
{
    auto path = FileUtils::getInstance()->fullPathForFilename("gameData.xml");
//    if (FileUtils::getInstance()->isFileExist(path.c_str()))
//    {
//        return;
//    }
    
    
    XMLDocument* doc = new XMLDocument();
    XMLDeclaration* declare = doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    doc->LinkEndChild(declare);  // 添加到文档尾部
    
    //[3] 创建注释，并连接到XML文档中
    XMLComment* comment = doc->NewComment("this is the game base data");
    doc->LinkEndChild(comment);
    
    //[4] 创建根节点，并连接到XML文档
    XMLElement* root = doc->NewElement("baseData");
    doc->InsertEndChild(root);// 与LinkEndChild()功能相同
    
    XMLElement* nodeHp = doc->NewElement("Hp");
    XMLElement* nodeLevel = doc->NewElement("Level");
    XMLElement* nodePm = doc->NewElement("PmValue");
    
    XMLText* hpText = doc->NewText("5");
    XMLText* levelText = doc->NewText("1");
    XMLText* pmText = doc->NewText("100");
    
    root->LinkEndChild(nodeHp);
    root->LinkEndChild(nodeLevel);
    root->LinkEndChild(nodePm);
    
    nodeHp->LinkEndChild(hpText);
    nodeLevel->LinkEndChild(levelText);
    nodePm->LinkEndChild(pmText);
    
    doc->SaveFile(path.c_str());
    delete doc;
}

const char* dataTools::encode(std::string str)
{
    for(int i = 0; i < str.length(); i++) {
        auto ch = str[i];
        ch = 0xff & (((ch & (1 << 7)) >> 7) & (ch << 1));
        str[i] = ch;
    }
    
    return str.c_str();
}

const char* dataTools::decode(std::string str)
{
    for(int i = 0; i < str.length(); i++) {
        int ch = str[i];
        ch = 0xff & (((ch & (1)) << 7) & (ch >> 1));
        str[i] = ch;
    }
    return str.c_str();
}
