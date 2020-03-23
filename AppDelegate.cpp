#include "AppDelegate.h"
//#include "KeyboardScene2.h"
//#include "KeyboardScene.h"
//#include "MouseScene.h"
//#include "GraphicsScene.h"
//#include "MultiTouchScene.h"
//#include "TouchScene.h"
//#include "TouchScene2.h"
//#include "CarAction.h"
#include "CarAction2.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    //we get an instance of the Director singleton
    auto director = Director::getInstance();
    //then use it to either get the GLView, or create a GLViewImpl, which is a default implementation of GLView.
    //GLView - это бесплатная кроссплатформенная утилита для просмотра OpenGL расширений.
    //Open Graphics Library(OpenGL)is a cross - language, cross - platform application programming interface(API) for rendering 2D and 3D vector graphics.
     //The API is typically used to interact with a graphics processing unit(GPU), to achieve hardware - accelerated rendering.
    auto glview = director->getOpenGLView();
    if (!glview) {
        //Basically GLView is the OpenGL representation of your window or screen, 
        //depending on what kind of device you are running.
        glview = GLViewImpl::create("Hello World");
        //set the resolution of the window 
        //( this is not required, I just wanted a smaller resolution for screen shots ) by calling setFrameSize()
        //glview->setFrameSize(640, 480);
        //set the view as active
        director->setOpenGLView(glview);
    }
    //auto scene = KeyboardScene2::createScene();
    //auto scene = KeyboardScene::createScene();
    //auto scene = MouseScene::createScene();
    //auto scene = TouchScene::createScene();
    //auto scene = TouchScene2::createScene();
    //auto scene = GraphicsScene::createScene();
    //auto scene = MultiTouch::createScene();
    //auto scene = CarAction::createScene();
    auto scene = CarAction2::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}



