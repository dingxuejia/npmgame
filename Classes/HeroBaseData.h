//
//  HeroBaseData.h
//  npmgame
//
//  Created by 丁学佳 on 15/3/24.
//
//

#ifndef __npmgame__HeroBaseData__
#define __npmgame__HeroBaseData__

//#include <stdio.h>
#include <vector>

//存储英雄所有数据的类
//单例类全局存储，以免过多访问配置文件
class HeroBaseData
{
public:
    static HeroBaseData* getInstence();
    inline int getHp(){return _heroHp;};
    inline void setHp(int hp){_heroHp=hp;};
    inline int getPm(){return _nowPm;};
    inline void setPm(int pm){_nowPm=pm;};
    inline int getLevel(){return _nowLevel;};
    inline void setLevel(int lev){_nowLevel=lev;};
    inline bool getJump(){return  _isJump;};
    inline void setJump(bool jump){_isJump=jump;};
    inline bool getAlive(){return _isAlive;};
    inline void setAlive(bool alive){_isAlive=alive;};
private:
    void init();
    
    int _heroHp;
    int _nowLevel;
    int _nowPm;
    bool _isJump;
    bool _isAlive;
    std::vector<int> _goods;
};

#endif /* defined(__npmgame__HeroBaseData__) */
