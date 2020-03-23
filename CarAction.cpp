#include "CarAction.h"

USING_NS_CC;

Scene* CarAction::createScene()
{
    auto scene = Scene::create();
    auto layer = CarAction::create();
    scene->addChild(layer);
    return scene;
}

bool CarAction::init()
{
    if (!Layer::init())
    {
        return false;
    }

    sprite = Sprite::create("Car.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);

    this->scheduleUpdate();
    return true;
}

//  delta - float value representing the amount of time, in seconds since the last time the update function was called
// if we multiply our move amount by the fraction of a second each frame takes, 
// it will perform roughly the same speed on all computers. When moving on a frame by frame basis, 
// express your units in seconds, then multiply them by the delta passed in to the update function
void CarAction::update(float delta) {
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    sprite->setPosition(position);
}

//In place of overriding update() you can also use schedule and scheduleOnce to schedule any function to be called.
//Either after a period of time or a number of times.The called function needs to have the same profile as update, 
//that is takes a single float parameterand a void return type.