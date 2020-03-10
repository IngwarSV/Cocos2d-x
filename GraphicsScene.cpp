#include <iostream>
#include "GraphicsScene.h"


USING_NS_CC;

Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);

    return scene;
}

bool GraphicsScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto sprite = Sprite::create("decepticon.png");
    auto sprite2 = Sprite::create("autobot.png");
    sprite->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
    sprite2->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));

    sprite->addChild(sprite2);

    sprite->setPosition(100, 100);
    sprite2->setPosition(0, 0);

    this->addChild(sprite, 0);
        
    Vec2 worldPosition = sprite2->convertToWorldSpace(sprite2->getPosition());
    return true;
}