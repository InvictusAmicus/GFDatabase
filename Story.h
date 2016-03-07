#ifndef _STORY_H_
#define _STORY_H_

#include "NewSinglePlayGame.h"
#include "cocos2d.h"

class Story : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void toGame(cocos2d::Ref*);
	// a selector callback

	/*!
	*Retrieves the values from the system file and sets the values in Options
	*/
	void SystemFile();

	/*!
	*Sets the volume of the background music
	*/
	void PlayMusic();

	CREATE_FUNC(Story);
}

#endif