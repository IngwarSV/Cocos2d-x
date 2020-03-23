#include "KeyboardScene.h"

USING_NS_CC;

Scene* KeyboardScene::createScene()
{
    auto scene = Scene::create();

    auto layer = KeyboardScene::create();
    scene->addChild(layer);
    return scene;
}

bool KeyboardScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto sprite = Sprite::create("HelloWorld.png");
    // returns the untransformed size of the node - layer KeyboardScene in this case
    sprite->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);

    this->addChild(sprite, 0);

    auto eventListener = EventListenerKeyboard::create();
       
    /*The first paramater passed in is the EventKeyboard::KeyCode enum, 
    which is a value representing the key that was pressed.
    The second value was the Event target, in this case our sprite.
    We use the Event pointer to get the target Nodeand update 
    it’s position in a direction depending on which key is pressed*/
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->setPosition(--loc.x, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->setPosition(++loc.x, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            event->getCurrentTarget()->setPosition(loc.x, --loc.y);
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);

    return true;
}