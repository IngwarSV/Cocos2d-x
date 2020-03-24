#include "CarAction2.h"

USING_NS_CC;

Scene* CarAction2::createScene()
{
    auto scene = Scene::create();
    auto layer = CarAction2::create();
    scene->addChild(layer);
    return scene;
}

bool CarAction2::init()
{
    //install of calling Layer::init() in our own init, we call LayerColor::initWithColor()
    if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
    {
        return false;
    }

    sprite = Sprite::create("Car.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);

    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void {

    //Actions inherited from ActionInterval, which are actions that happen over time:

        // This is where our different actions are going to be implemented

        //////////////1///////////////

        //MoveTo action to move the target node to the position(0, 0) over a duration of 2 seconds
        //auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0, 0));
        //auto action = cocos2d::MoveBy::create(2, cocos2d::Vec2(300, 300));
        //sprite->runAction(action);

        //////////////2///////////////
        
        /*A GLubyte is an 8bit value that ranges from 0 to 255 in value.In all cases 255 is the fully on value,
        and 0 is the fully off value.Therefore the value(255, 0, 0) is 100 % red, 0 % green, 0 % blue,
        while the value 30 in TintTo is 30 / 255 or 11.7 % opaque.*/

        /*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::ScaleBy::create(1.5, 1.5));
        actions.pushBack(cocos2d::DelayTime::create(1));
        
        actions.pushBack(cocos2d::TintTo::create(1.5, 255, 0, 0));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::FadeTo::create(1.5, 30));

        auto sequence = cocos2d::Sequence::create(actions);
        sprite->runAction(sequence);*/

        ///////////////3//////////////

        /*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::ScaleBy::create(1.5, 1.5));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::TintTo::create(1.5, 255, 0, 0));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::FadeTo::create(1.5, 30));

        auto parallel = cocos2d::Spawn::create(actions);

        sprite->runAction(parallel);*/

        ////////////////4//////////////
               
        /*auto action = cocos2d::MoveBy::create(0.2, cocos2d::Vec2(10, 0));
        auto action2 = cocos2d::ScaleBy::create(2, 1.3);
        auto repeat = cocos2d::Repeat::create(action, 10);
        auto repeatForever = cocos2d::RepeatForever::create(action2);

        sprite->runAction(repeat);
        sprite->runAction(repeatForever);*/

    // There are also actions that happen instantly. These actions inherit from ActionInstant.

        /////////////////5/////////////

        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::MoveTo::create(1, cocos2d::Vec2(0, 0)));
        actions.pushBack(cocos2d::DelayTime::create(1));
        //The Place action can by thought of as a 0 duration MoveTo call, putting the Node at the specified position
        actions.pushBack(cocos2d::Place::create(cocos2d::Vec2(
            this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY()))); 
        actions.pushBack(cocos2d::DelayTime::create(1));
        //FlipX mirrors the Node along the X axis
        actions.pushBack(cocos2d::FlipX::create(true));
        actions.pushBack(cocos2d::DelayTime::create(1));
        //FlipY does the same across the Y axis
        actions.pushBack(cocos2d::FlipY::create(true));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::Hide::create());
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::Show::create());
        actions.pushBack(cocos2d::DelayTime::create(1));

        /*CallFunc enables you to call code using an action, in this case I use a lambda 
        that simply changes the background color of the Layer.
        CallFunc is an incredibly important actionand allows you to do 
        just about anything using Actions, such as updating state, playing a sound, etc.*/
        actions.pushBack(cocos2d::CallFunc::create([=]()->void {
            this->setColor(cocos2d::Color3B::GREEN);
        }));

        actions.pushBack(cocos2d::DelayTime::create(1));

        /*RemoveSelf it’s basically a kill switch. When a removeSelf action is encountered, that 
        Node is removed from it’s parent.Passing true causing cleanup to be done.
        This is incredibly handy for something like handling the lifespan of a bullet in the scene for example.*/
        actions.pushBack(cocos2d::RemoveSelf::create(false));

        auto sequence = cocos2d::Sequence::create(actions);
        sprite->runAction(sequence);


    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

//  delta - float value representing the amount of time, in seconds since the last time the update function was called
// if we multiply our move amount by the fraction of a second each frame takes, 
// it will perform roughly the same speed on all computers. When moving on a frame by frame basis, 
// express your units in seconds, then multiply them by the delta passed in to the update function

// this->scheduleUpdate() - without this Update won't be working
void CarAction2::update(float delta) {
   auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    sprite->setPosition(position);
}

//In place of overriding update() you can also use schedule and scheduleOnce to schedule any function to be called.
//Either after a period of time or a number of times.The called function needs to have the same profile as update, 
//that is takes a single float parameterand a void return type.


//Instead of our scene inheriting from Layer we instead inherit from LayerColor, which adds, you guessed it, color information.
//Additionally, install of calling Layer::init() in our own init, we call LayerColor::initWithColor().