#include "TouchScene.h"

USING_NS_CC;

Scene* TouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);

    return scene;
}

bool TouchScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto sprite = Sprite::create("decepticon.png");
    //getVisibleSize() - returns visible size of the OpenGL view in points. 
    //the value is equal to getWinSize (returns Size struct - float width, float height)
    sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    // Add a "touch" event listener to our sprite
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {

        auto bounds = event->getCurrentTarget()->getBoundingBox();

        //containsPoint - check if the point is contained inclusively in rect
        //touch->getLocation() - returns current touch location in OpenGLCoords
        if (bounds.containsPoint(touch->getLocation())) {
            std::stringstream touchDetails;
            touchDetails << "Touched at OpenGL coordinates: " <<
                
                //the other is relative to the bottom left corner of the screen
                touch->getLocation().x << "," << touch->getLocation().y << std::endl <<
                //one relative to the top left corner of the screen, 
                "Touched at UI coordinate: " <<
                touch->getLocationInView().x << "," << touch->getLocationInView().y << std::endl <<
                //the local coordinate is the position the click occurred relative to the node’s origin
                "Touched at local coordinate:" <<
                event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << "," <<
                event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
                "Touch moved by:" << touch->getDelta().x << "," << touch->getDelta().y;
            // str() - returns a string object with a copy of the current contents of the stream
            //c_str() - Формирует массив строк в стиле си. И возвращает указатель на него.
            // second string is a Title
            MessageBox(touchDetails.str().c_str(), "Touched");
        }
        return true;
    };

    //The second parameter, sprite, is what determines the target of the Event.  
    //The target is passed as a Node but can be cast if required.
   /* This was the old way of doing things and I did it this way for a couple reasons. First, to show that you can.
   Second, because _eventListener is a protected member, I would only have access to it if I derived my own Sprite object.*/
   // Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sprite);
    this->addChild(sprite, 0);

    return true;
}