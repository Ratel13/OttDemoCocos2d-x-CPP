#include "startMenuLayer1.h"
#include "AppMacros.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

#include "StartScene.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;

startMenuLayer1::startMenuLayer1()
{
    
}

startMenuLayer1::~startMenuLayer1()
{
    
}
bool startMenuLayer1::init(Layer * aLayer)
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Layout * widget = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HiSiliconDemo_2.json"));
    this->addChild(widget);
	//Get the buttons of continue button, main menu button, select button, setting button
	auto menu1_0 = dynamic_cast<Label*>(widget->getChildByName("Menu1-0"));
	auto menu1_1 = dynamic_cast<Label*>(widget->getChildByName("Menu1-1"));
	auto menu1_2 = dynamic_cast<Label*>(widget->getChildByName("Menu1-2"));
	auto menu1_3 = dynamic_cast<Label*>(widget->getChildByName("Menu1-3"));
    auto menu1_4 = dynamic_cast<Label*>(widget->getChildByName("Menu1-4"));
    menuEffect = dynamic_cast<ImageView*>(widget->getChildByName("menuEffect"));
    /*
    menu1_0->addTouchEventListener(this, toucheventselector(startMenuLayer1::onMenuChange));
	menu1_1->addTouchEventListener(this, toucheventselector(startMenuLayer1::onMenuChange));
	menu1_2->addTouchEventListener(this, toucheventselector(startMenuLayer1::onMenuChange));
    menu1_3->addTouchEventListener(this, toucheventselector(startMenuLayer1::onMenuChange));
    menu1_4->addTouchEventListener(this, toucheventselector(startMenuLayer1::onMenuChange));
    */
    
   // this->setTouchEnabled(true);
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(startMenuLayer1::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(startMenuLayer1::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    /*
    menu1_0->setTouchEnabled(true);
    menu1_1->setTouchEnabled(true);
    menu1_3->setTouchEnabled(true);
    menu1_4->setTouchEnabled(true);
     */
     return true;
}
void startMenuLayer1::onMenuChange(Ref * pSender, TouchEventType type)
{
    if(TOUCH_EVENT_BEGAN==type)
    {
        auto startLayer1 = thisScene->getChildByTag(200);
        //            var startLayer2 = thisScene.getChildByTag(300);
        Point positionNow = startLayer1->getPosition();
        auto actionBy1 = EaseBackIn::create(MoveBy::create(1, Point(2000,0)));
        //            var sequence1 = cc.Sequence.create(actionBy1,cc.CallFunc.create(this.layer2SetPosition,startLayer1))
        //            var actionBy2 = cc.MoveBy.create(10, cc.p(2000,0));
        startLayer1->runAction(actionBy1);
        startLayer1->setPosition(positionNow);
        //            startLayer2.runAction(actionBy2);
    }
}

void startMenuLayer1::layer2SetPosition(Layer * layer2,Point position)
{
    this->setPosition(Point(0,0));
}


