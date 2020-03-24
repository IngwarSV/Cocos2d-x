#pragma once

#include "cocos2d.h"

//Instead of our scene inheriting from Layer we instead inherit from LayerColor, 
//which adds, you guessed it, color information
class CarAction2 : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(CarAction2);

    void update(float) override;

private:
    cocos2d::Sprite* sprite;
};