#pragma once

#include "cocos2d.h"

class GraphicsScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GraphicsScene);
};

//the macro is creating a create() function that allocates an instance of our class, 
//calls the init method that we providedand then, most importantly, calls autorelease() we inherited from Ref.

//CREATE_FUNC(HelloWorld);

//static HelloWorld* create() {
//    HelloWorld* pRet = new HelloWorld();
//    if (pRet && pRet->init())
//    {
//        pRet->autorelease();
//        return pRet;
//    }
//    else
//    {
//        delete pRet;
//        pRet = NULL;
//        return NULL;
//    }
//}


