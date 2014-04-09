#ifndef __WelcomeScene_SCENE_H__
#define __WelcomeScene_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class WelcomeScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    void dataLoaded(float percent);
    
    // a selector callback
    void ReplaceScene(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(WelcomeScene);
    
    LabelTTF* label;
};

#endif // __WelcomeScene_SCENE_H__
