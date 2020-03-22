#pragma once

#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
};


//Basically the enterBackground / enterForeground methods are called when your application gains and loses focus, 
//while applicationDidFinishLaunching is called when your application is loaded(at the end of the loading process).