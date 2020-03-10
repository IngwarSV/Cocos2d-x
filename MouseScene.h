#pragma once

#include <iostream>
#include "cocos2d.h"

class MouseScene : public cocos2d::Layer
{

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(MouseScene);
//private:
//    const static int MAX_TOUCHES = 5;
//
//protected:
//    cocos2d::Label* labelTouchLocations[MAX_TOUCHES];

};