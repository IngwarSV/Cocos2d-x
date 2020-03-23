#pragma once

#include "cocos2d.h"

class TouchScene2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    //quartet of handler functions for handling the various possible touch events - 
    //здесь они переопределены для класса TouchScene2
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    CREATE_FUNC(TouchScene2);

private:
    //Label used to draw the text on the screen
    cocos2d::Label* labelTouchInfo;
};