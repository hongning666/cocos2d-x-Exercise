#ifndef MYLABEL_H_
#define MYLABEL_H_
#include"cocos2d.h"
USING_NS_CC;
class MyLabel:public Layer
{
public:
	static Scene* createScene();
	bool init();
	CREATE_FUNC(MyLabel);
	enum Label//Ã¶¾Ù
	{
		TTF,ATLAS
	};
	void mySchedule(float dt);//¶¨Ê±Æ÷
};

#endif