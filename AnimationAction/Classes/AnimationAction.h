#ifndef __ANIMATIONACTION_SCENE_H__
#define __ANIMATIONACTION_SCENE_H__


#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "Final/C3SButton.h"
#include "Final/CObstacle.h"
#include "Final/CRunner.h"

class AnimationAction : public cocos2d::Layer
{
private:
	cocos2d::Sequence *_mySequence;
	cocos2d::Action   *_myAction;

	// For Double Jump
	cocos2d::JumpBy   *_myJump;
	int _NoJumps;
	cocos2d::CallFunc *_mycallback;
	cocos2d::Point _runnerPt;

	cocos2d::Label *label1;
	int  _sceneno;
	char _cSceneNo[10];
	cocos2d::Sprite *returnbtn;
	cocos2d::Rect    rectReturn;
	cocos2d::Rect    rectCuber;

	C3SButton *replaybtn;
	CObstacle *obj1;
	CObstacle *obj2;
	CObstacle *obj3;
	CRunner *runner;

	bool jumpornot;

public:
	~AnimationAction();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void CuberBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void doStep(float dt);

	// Action 的 CallBack 函式
	void AnimationAction::actionFinished();


	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	// implement the "static create()" method manually
    CREATE_FUNC(AnimationAction);
};

#endif // __HELLOWORLD_SCENE_H__
