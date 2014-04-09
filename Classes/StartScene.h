#ifndef __StartScene_SCENE_H__
#define __StartScene_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;
class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
private:
    ImageView * movieEffect;
    
    ImageView* movie2_0;
    
    ImageView * movie2_1;
    
    bool movie2_temp;
    
    bool movieTouchEvent(Ref * pSender, TouchEventType type);
    
    void movie2_0Effect();
};

#endif // __StartScene_SCENE_H__
