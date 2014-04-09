#include "WelcomeScene.h"
#include "AppMacros.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

#include "StartScene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;

Scene* WelcomeScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = WelcomeScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool WelcomeScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto size = Director::getInstance()->getWinSize();
    
    label = LabelTTF::create("Loading...", "Arial", 60);
    label->setPosition(Point(size.width-label->getContentSize().width, label->getContentSize().height/2));
    this->addChild(label, 2, 1);
    ArmatureDataManager::getInstance()->addArmatureFileInfoAsync("ChenXiaoGeWelcome.ExportJson", this, schedule_selector(WelcomeScene::dataLoaded));

    return true;
}
void WelcomeScene::dataLoaded(float percent)
{
    auto size = Director::getInstance()->getWinSize();

    auto armature = Armature::create("ChenXiaoGeWelcome");
    armature->getAnimation()->play("Animation1");
    armature->getAnimation()->setSpeedScale(2.0);
    armature->setAnchorPoint(Point(0,0));
//    armature->setPosition(Point(SCREEN_SIZE.width/3, SCREEN_SIZE.height/2));
    armature->setPosition(Point(size.width-label->getContentSize().width-armature->getContentSize().width-100,label->getContentSize().height/2));

    this->addChild(armature);
    
    this->scheduleOnce(schedule_selector(WelcomeScene::ReplaceScene), 1.0);
}

void WelcomeScene::ReplaceScene(float dt)
{
    auto scene = StartScene::createScene();
    Director::getInstance()->replaceScene( TransitionProgressHorizontal::create(1.0, scene) );
}
