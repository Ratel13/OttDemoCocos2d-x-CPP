#include "startMenuLayer2.h"
#include "AppMacros.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;

startMenuLayer2::startMenuLayer2()
{
    
}

startMenuLayer2::~startMenuLayer2()
{
    
}
bool startMenuLayer2::init(Layer * aLayer)
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto bg2 = Sprite::create("Background.png");
    bg2->setAnchorPoint(Point(0.0f,0.0f));
    this->addChild(bg2,0);
    
    //Read the resources of CocoStudio json file
    Layout * pauseWidget = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HiSiliconDemo_1.json"));
    this->addChild(pauseWidget,1);
	movie2_0 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie2-0"));
    movie2_0->setOpacity(0);
    
    ImageView* movie3_0 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie3-0"));
	ImageView* movie1_1 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie1-1"));
	ImageView* movie4_1 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie4-1"));
    ImageView* movie5_1 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie5-1"));
	ImageView* movie6_1 = dynamic_cast<ImageView*>(pauseWidget->getChildByName("Movie6-1"));
    ImageView* seriesBackground = dynamic_cast<ImageView*>(pauseWidget->getChildByName("seriesBackground"));
    
    imageViewVec.pushBack(movie3_0);
    imageViewVec.pushBack(movie1_1);
    imageViewVec.pushBack(movie4_1);
    imageViewVec.pushBack(movie5_1);
    imageViewVec.pushBack(movie6_1);
    imageViewVec.pushBack(seriesBackground);
    
    imageViewPositionXVec.push_back(movie3_0->getPositionX());
    imageViewPositionXVec.push_back(movie1_1->getPositionX());
    imageViewPositionXVec.push_back(movie4_1->getPositionX());
    imageViewPositionXVec.push_back(movie5_1->getPositionX());
    imageViewPositionXVec.push_back(movie6_1->getPositionX());
    imageViewPositionXVec.push_back(seriesBackground->getPositionX());
    
    imageViewPositionYVec.push_back(movie3_0->getPositionY());
    imageViewPositionYVec.push_back(movie1_1->getPositionY());
    imageViewPositionYVec.push_back(movie4_1->getPositionY());
    imageViewPositionYVec.push_back(movie5_1->getPositionY());
    imageViewPositionYVec.push_back(movie6_1->getPositionY());
    imageViewPositionYVec.push_back(seriesBackground->getPositionY());
    
    
    movie3_0->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
	movie1_1->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
	movie4_1->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
    movie5_1->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
	movie6_1->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
    seriesBackground->addTouchEventListener(this, toucheventselector(startMenuLayer2::movieTouchEvent));
    
    movie2_0->setOpacity(0);
    
    movieEffect = ImageView::create();
    movieEffect->loadTexture("movie-effect.png");
    
    movie2_1  = ImageView::create();
    movie2_1->loadTexture("Movie2-1.png");
    movieEffect->setVisible(false);
    movieEffect->setTag(100);
    this->addChild(movieEffect,0);

   
    
    movie2_1->setScale(movie2_0->getContentSize().width/movie2_1->getContentSize().width, movie2_0->getContentSize().height/movie2_1->getContentSize().height);
    
    movie2_1->setAnchorPoint(movie2_0->getAnchorPoint());
    
    movie2_1->setPosition(movie2_0->getPosition());
    
    this->addChild(movie2_1,3);
    
    imageViewVec.pushBack(movie2_1);
    imageViewPositionXVec.push_back(movie2_1->getPositionX());
    imageViewPositionYVec.push_back(movie2_1->getPositionY());
    
    auto orbit1 = OrbitCamera::create(3, 1, 0, 0, 360, 0, 0);
    auto delay = DelayTime::create(4);
    movie2_temp = true;
    movie2_1->runAction(RepeatForever::create(Sequence::create(orbit1,delay,CallFunc::create(CC_CALLBACK_0(startMenuLayer2::movie2_0Effect,this)),delay->clone(),NULL)));
    auto mirror = ImageView::create();
    mirror->loadTexture("mirror.png");
    mirror->setAnchorPoint(Point(0,0));
    mirror->setPosition(Point(150,-15));
    this->addChild(mirror,5);

    
    

    Layout * widget = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HiSiliconDemo_2.json"));
  
    auto aEffect = dynamic_cast<ImageView*>(widget->getChildByName("menuEffect"));
    menuEffect = Sprite::create("menuEffect.png");
    menuEffect->setPosition(aEffect->getPosition());
    this->addChild(menuEffect,0);
    
    
	auto menu1_0 = dynamic_cast<ImageView*>(widget->getChildByName("ImageView_1-0"));
	auto menu1_1 = dynamic_cast<ImageView*>(widget->getChildByName("ImageView_1-1"));
	auto menu1_2 = dynamic_cast<ImageView*>(widget->getChildByName("ImageView_1-2"));
	auto menu1_3 = dynamic_cast<ImageView*>(widget->getChildByName("ImageView_1-3"));
    auto menu1_4 = dynamic_cast<ImageView*>(widget->getChildByName("ImageView_1-4"));
    
    float aScale = 2.0f;
    
    auto item0= MenuItemFont::create("热门推荐", CC_CALLBACK_1(startMenuLayer2::onMenuChange, this));
    item0->setTag(1000);
    item0->setScale( aScale );
    item0->setPosition(menu1_0->getPosition());
    
    auto item1= MenuItemFont::create("影视分类", CC_CALLBACK_1(startMenuLayer2::onMenuChange, this));
    item0->setTag(1001);
    item1->setScale(aScale );
    item1->setPosition(menu1_1->getPosition());
    
    auto item2= MenuItemFont::create("专区", CC_CALLBACK_1(startMenuLayer2::onMenuChange, this));
    item0->setTag(1002);
    item2->setScale(aScale );
    item2->setPosition(menu1_2->getPosition());
    
    auto item3= MenuItemFont::create("应用", CC_CALLBACK_1(startMenuLayer2::onMenuChange, this));
    item0->setTag(1003);
    item3->setScale(aScale);
    item3->setPosition(menu1_3->getPosition());
    
    auto item4= MenuItemFont::create("设置", CC_CALLBACK_1(startMenuLayer2::onMenuChange, this));
    item0->setTag(1004);
    item4->setScale(aScale);
    item4->setPosition(menu1_4->getPosition());
    
    auto menu = Menu::create(item0,item1,item2,item3,item4,NULL);
    menu->setPosition(Point(0,0));
    this->addChild(menu,1000);

    return true;
}

void startMenuLayer2::onMenuChange(Ref * pSender)
{
    if(lock || lastImageView==pSender)
    {
        return;
    }
    lastImageView = pSender;
    lock = true;
    movieEffect->setPosition(Point(2000,2000));
    MenuItemFont * aItem = (MenuItemFont * )pSender;
    
    auto toPoint = Point(aItem->getPositionX(),aItem->getPositionY()-aItem->getContentSize().height/2);
    auto actionEaseBackIn = EaseBackIn::create(MoveTo::create(0.5, toPoint));
    menuEffect->runAction(actionEaseBackIn);
    
    for (int i = 0; i<imageViewVec.size(); i++)
    {
        ImageView * aItem = (ImageView * )imageViewVec.at(i);
        auto actionTo = EaseBackIn::create(MoveBy::create(1.0, Point(2000,0)));
        if(imageViewVec.size()-1==i)
        {
            aItem->runAction(Sequence::create(actionTo,CallFunc::create(CC_CALLBACK_0(startMenuLayer2::goHead,this)),NULL));
        }
        else
        {
            aItem->runAction(actionTo);
        }
    }
}

void startMenuLayer2::goHead()
{
    for (int i = 0; i<imageViewVec.size(); i++)
    {
        ImageView * aItem = (ImageView * )imageViewVec.at(i);
        Point mypoint = Point(imageViewPositionXVec.at(i)-3000,imageViewPositionYVec.at(i));
        aItem->setPosition(mypoint);
    }
    this->scheduleOnce(schedule_selector(startMenuLayer2::goBack), 0.5);
}

void startMenuLayer2::goBack(float dt)
{
    for (int i = 0; i<imageViewVec.size(); i++)
    {
        ImageView * aItem = (ImageView * )imageViewVec.at(i);
        Point mypoint = Point(imageViewPositionXVec.at(i),imageViewPositionYVec.at(i));
        auto actionTo = EaseBackIn::create(MoveTo::create(0.5, mypoint));
        aItem->runAction(actionTo);
    }
    lock = false;
}



void startMenuLayer2::movie2_0Effect()
{
    
    if(movie2_temp == true){
        
        movie2_1->loadTexture("Movie2-2.png");
        movie2_temp = false;
        movie2_1->setScale(movie2_0->getContentSize().width/movie2_1->getContentSize().width, movie2_0->getContentSize().height/movie2_1->getContentSize().height);
    }
    else
    {
        movie2_1->loadTexture("Movie2-1.png");
        movie2_temp = true;
        movie2_1->setScale(movie2_0->getContentSize().width/movie2_1->getContentSize().width, movie2_0->getContentSize().height/movie2_1->getContentSize().height);
    }
}
bool startMenuLayer2::movieTouchEvent(Ref * pSender, TouchEventType type)
{
    if(lock)
    {
       movieEffect->setPosition(Point(2000,2000));
    }
    
    ImageView* aImage = (ImageView *)pSender;
    
    auto scaleX = aImage->getScaleX();
    auto scaleY = aImage->getScaleY();
    if(TOUCH_EVENT_BEGAN==type)
    {
        movieEffect->setVisible(true);
        movieEffect->setScale(aImage->getContentSize().width/movieEffect->getContentSize().width*1.70, aImage->getContentSize().height/movieEffect->getContentSize().height*1.70);
        aImage->setScaleX(scaleX*1.02);
        aImage->setScaleY(scaleY*1.02);
        movieEffect->setAnchorPoint(aImage->getAnchorPoint());
        movieEffect->setPosition(aImage->getPosition());
        movieEffect->setZOrder(aImage->getZOrder()-0.5);
        return false;
    }
    
    if(TOUCH_EVENT_ENDED==type){
        movieEffect->setScale(aImage->getContentSize().width/movieEffect->getContentSize().width*1.60, aImage->getContentSize().height/movieEffect->getContentSize().height*1.60);
        aImage->setScaleX(1);
        aImage->setScaleY(1);
    }
    
    return true;
}

