#include "AppDelegate.h"
#include "KeyboardScene.h"
//#include "MouseScene.h"
//#include "GraphicsScene.h"
//#include "MultiTouchScene.h"
//#include "TouchScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::create("Hello World");
        //glview->setFrameSize(640, 480);
        director->setOpenGLView(glview);
    }
    auto scene = KeyboardScene::createScene();
    //auto scene = MouseScene::createScene();
    //auto scene = TouchScene::createScene();
    //auto scene = GraphicsScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}