#pragma once

#include "cocos2d.h"

class CarAction3 : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(CarAction3);

private:
    cocos2d::Sprite* sprite, * sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;

    void CarAction3::callOnce(float delta);
};
