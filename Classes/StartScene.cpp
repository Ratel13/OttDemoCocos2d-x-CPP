#include "StartScene.h"
#include "AppMacros.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"
#include "startMenuLayer1.h"
#include "startMenuLayer2.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto size = Director::getInstance()->getWinSize();
    auto realSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //this._super();
    
    //auto startLayer1 = new startMenuLayer1();
    //startLayer1->init(this);
    
    auto startLayer2 = new startMenuLayer2();
    startLayer2->init(this);
    startLayer2->setTag(200);
    //this->addChild(startLayer1,1);
    this->addChild(startLayer2,1);
    
    auto particleLayer = Layer::create();
    auto particle1 = ParticleSystemQuad::create("mystic.plist");
    particle1->setPositionType(ParticleSystem::PositionType::GROUPED);
    auto particle2 = ParticleSystemQuad::create("mystic.plist");
    particle2->setPositionType(ParticleSystem::PositionType::FREE);
    particle2->setScale(1.5);
    particleLayer->addChild(particle1, 2);
    particleLayer->addChild(particle2, 2);
    this->addChild(particleLayer,0.5);

    return true;
}


