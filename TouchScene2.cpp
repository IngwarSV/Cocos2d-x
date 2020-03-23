#include "TouchScene2.h"

USING_NS_CC;

Scene* TouchScene2::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene2::create();
    scene->addChild(layer);

    return scene;
}

bool TouchScene2::init()
{
    if (!Layer::init())
    {
        return false;
    }
    //Label used to draw the text on the screen
    labelTouchInfo = Label::createWithSystemFont("Touch or clicksomewhere to begin", "Arial", 30);

    labelTouchInfo->setPosition(Vec2(
        Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    //EventListener of type EventListenerTouchOneByOne, which predictably handles touches, one by one
    auto touchListener = EventListenerTouchOneByOne::create();

    // TouchScene2::onTouchBegan - 
    // TouchScene2::onTouchBegan - вызов метода класса TouchScene2, this - передача объкта этого класса, 
    // CC_CALLBACK_2 - two placeholders, waiting for two arguments
    // можно было реализовать через аноним-функцию
    touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene2::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene2::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene2::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene2::onTouchCancelled, this);

    //register our EventListener to receive events.
    /*This is done with a call to NodeТs protected member _eventListener.
    We call addEventListenerWithSceneGraphPriority(), 
    which basically means we want this event to be updated as much as possible.*/
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    this->addChild(labelTouchInfo);
    return true;
}

bool TouchScene2::onTouchBegan(Touch* touch, Event* event)
{
    labelTouchInfo->setPosition(touch->getLocation());
    labelTouchInfo->setString("You Touched Here");
    return true;
}

void TouchScene2::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended");
}

void TouchScene2::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");
}

void TouchScene2::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}