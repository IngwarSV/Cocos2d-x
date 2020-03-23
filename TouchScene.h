#pragma once

#include "cocos2d.h"

class TouchScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(TouchScene);

private:
    cocos2d::Label* labelTouchInfo;
};
