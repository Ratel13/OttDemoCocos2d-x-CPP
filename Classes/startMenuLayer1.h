#ifndef __startMenuLayer1_SCENE_H__
#define __startMenuLayer1_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;
class StartScene;
class startMenuLayer1 : public cocos2d::Layer
{
public:
    startMenuLayer1();
    virtual ~startMenuLayer1();
    
    StartScene * thisScene;
    bool init(Layer * aLayer);
    
private:
    ImageView * menuEffect;
    
    void onMenuChange(Ref * pSender, TouchEventType type);
    void layer2SetPosition(Layer * layer2,Point position);
};

#endif // __startMenuLayer1_SCENE_H__
