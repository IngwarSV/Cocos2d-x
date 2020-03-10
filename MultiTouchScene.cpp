#include "MultiTouchScene.h"

USING_NS_CC;

Scene* MultiTouch::createScene()
{
    auto scene = Scene::create();
    auto layer = MultiTouch::create();
    scene->addChild(layer);

    return scene;
}

bool MultiTouch::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // Create an array of Labels to display touch locations and add them to this node, defaulted to invisible
    for (int i = 0; i < MAX_TOUCHES; ++i) {
        labelTouchLocations[i] = Label::createWithSystemFont("", "Arial", 42);
        labelTouchLocations[i]->setVisible(false);
        this->addChild(labelTouchLocations[i]);
    }

    auto eventListener = EventListenerTouchAllAtOnce::create();

    //  Create an eventListener to handle multiple touches, using a lambda, cause baby, it's C++11
    eventListener->onTouchesBegan = [=](const std::vector<Touch*>& touches, Event* event) {

        // Clear all visible touches just in case there are less fingers touching than last time
        std::for_each(labelTouchLocations, labelTouchLocations + MAX_TOUCHES, [](Label* touchLabel) {
            touchLabel->setVisible(false);
            });

        // For each touch in the touches vector, set a Label to display at it's location and make it visible
        for (int i = 0; i < touches.size(); ++i) {
            labelTouchLocations[i]->setPosition(touches[i]->getLocation());
            labelTouchLocations[i]->setVisible(true);
            labelTouchLocations[i]->setString("Touched");
        }
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}