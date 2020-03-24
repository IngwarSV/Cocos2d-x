#include "CarAction3.h"

cocos2d::Scene* CarAction3::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = CarAction3::create();
    scene->addChild(layer);
    return scene;
}

bool CarAction3::init()
{
    if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
    {
        return false;
    }

    label = cocos2d::Label::createWithSystemFont("Press space to pause all, 1 to pause left", "Arial", 30);
    label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));

    sprite = cocos2d::Sprite::create("Car.png");
    sprite2 = cocos2d::Sprite::create("Car.png");
    sprite->setPosition(250, this->getBoundingBox().getMidY());
    sprite2->setPosition(700, this->getBoundingBox().getMidY());

    auto rotate = cocos2d::RotateBy::create(1, 45);
    auto rotate2 = cocos2d::RotateBy::create(1, -45);

    auto repeat1 = cocos2d::RepeatForever::create(rotate);
    auto repeat2 = cocos2d::RepeatForever::create(rotate2);

    this->addChild(label, 0);
    this->addChild(sprite, 0);
    this->addChild(sprite2, 0);

    sprite->runAction(repeat1);
    sprite2->runAction(repeat2);
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void {
        // On Spacebar, Pause/Unpause all actions and updates
        /*using ActionManager you are able to pause execution of Actions, either to a single Node or all Nodes at once
        In the event of pausing all running actions by calling getActionManager()->pauseAllRunningActions() this returns 
        a cocos2d::Vector off all the Nodes that were paused.When resuming, you simply pass this Vector back in a call to resumeTargets().*/
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
            if (pausedNodes.size()) {
                cocos2d::Director::getInstance()->getActionManager()->resumeTargets(pausedNodes);
                pausedNodes.clear();
                spritePaused = false; // In case user currently has 1 pressed too
            }
            else
                pausedNodes = cocos2d::Director::getInstance()->getActionManager()->pauseAllRunningActions();
            label->setString("Spacebar pressed");
        }
        // Pause/UnPause just sprite 1
        //In the event of a single Node it’s simply a matter of calling pauseSchedulerAndActions and resumeSchedulerAndActions
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_1) {
            if (spritePaused)
                sprite->resumeSchedulerAndActions();
            else
                sprite->pauseSchedulerAndActions();
            spritePaused = !spritePaused;
            label->setString("1 pressed");
        }

    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //This code will wait 10 seconds and then call our method callOnce().
    this->scheduleOnce(schedule_selector(CarAction3::callOnce), 10);

    return true;
}

void CarAction3::callOnce(float delta) {
    cocos2d::MessageBox("Called after 10 seconds elapsed", "Message");
}