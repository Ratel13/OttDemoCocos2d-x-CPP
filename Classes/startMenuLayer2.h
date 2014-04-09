#ifndef __startMenuLayer2_SCENE_H__
#define __startMenuLayer2_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocostudio;
class startMenuLayer2 : public cocos2d::Layer
{
public:
    startMenuLayer2();
    virtual ~startMenuLayer2();
    bool init(Layer * aLayer);
    
private:
    ImageView * movieEffect;
    
    ImageView* movie2_0;
    
    ImageView * movie2_1;
    
    bool movie2_temp;
    
    bool movieTouchEvent(Ref * pSender, TouchEventType type);
    
    void movie2_0Effect();
    
    Sprite * menuEffect;
    
    void onMenuChange(Ref * pSender);
    
    Vector<ImageView* > imageViewVec;
    
    std::vector<float > imageViewPositionXVec;
    
    std::vector<float > imageViewPositionYVec;
    
    void goHead();
    
    void goBack(float dt);
    
    bool lock = false;
    
    Ref * lastImageView;
};

#endif // __startMenuLayer2_SCENE_H__
