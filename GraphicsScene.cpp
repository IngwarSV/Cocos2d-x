#include <iostream>
#include "GraphicsScene.h"


USING_NS_CC;

//The createScene() method is pretty straight forward.
//We create a Scene object, then an instance of our HelloWorld class (which inherits from Layer) and 
//add our layer to the scene then return the scene(which our AppDelegate then passed to Director->runScene()).

Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);

    return scene;
}


bool GraphicsScene::init()
{
    /*Layer::init() provides default initiation for a Layer or its subclass. 
    If your subclass depends on these default initiation to work, then it is necessary. 
    Alternatively is that you supply your own init() method to initialize your Layer.
    Initializes the instance of Node.
        Returns     Whether the initialization was successful.
        First we call our base classes init function ( which is very important to do )*/
    if (!Layer::init())
    {
        return false;
    }

    auto sprite = Sprite::create("decepticon.png");
    auto sprite2 = Sprite::create("autobot.png");
    sprite->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
    sprite2->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));

    //you can actually parent any Node to any other Node object
    sprite->addChild(sprite2);

   /* the child’s position is relative to it’s parent.
    Therefore sprite2’s(0, 0) position is relative to the origin of sprite1
    When the parent moves, the child moves with it*/
    sprite->setPosition(100, 100);
    sprite2->setPosition(0, 0);

    this->addChild(sprite, 0);
        
    /*So what do you do when you want to get a node’s position in the world, not relative to it’s parent ? 
    Fortunately Node has that functionality built in :*/
    Vec2 worldPosition = sprite2->convertToWorldSpace(sprite2->getPosition());
    return true;
}


