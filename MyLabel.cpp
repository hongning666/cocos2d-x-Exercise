#include "MyLabel.h"


Scene* MyLabel::createScene()
{
	auto scene = Scene::create();
	auto layer = MyLabel::create();
	scene->addChild(layer);
	return scene;
}
bool MyLabel::init()
{
	Layer::init();
	/*LabelTTF* ttf = LabelTTF::create("HelloWorld", "Curier", 50);
	ttf->setPosition(240, 160);
	addChild(ttf);
	ttf->setTag(TTF);*/
	/*schedule(schedule_selector(MyLabel::mySchedule),1);
	LabelAtlas* atlas = LabelAtlas::create("0123456789", "Labelatlas.png", 24, 32, '0');
	atlas->setAnchorPoint(Vec2(0.5, 0.5));
	atlas->setPosition(240, 160);
	addChild(atlas);
	atlas->setTag(ATLAS);*/
	LabelBMFont *bm = LabelBMFont::create("GOOD NIGHT", "bitmapFontTest.fnt");
	bm->setPosition(240, 160);
	bm->setAnchorPoint(Vec2(0.5, 0.5));
	addChild(bm);
	Array *array = Array::create();
	array->addObject(bm);
	Object *obj;
	CCARRAY_FOREACH(array, obj)
	{
		Sprite *spr = (Sprite*)obj;
		spr->setPosition(CCRANDOM_0_1() * 480, CCRANDOM_0_1() * 320);
	}
	CCARRAY_FOREACH(array, obj)
	{
		static float x = 240;
		static float y = 160;
		Sprite *spr = (Sprite*)obj;
		MoveTo *to = MoveTo::create(2, Vec3(x, y, 23)); 
		spr->runAction(to);
	}
	return true;
}
void MyLabel::mySchedule(float dt)
{
	LabelAtlas* atlas = (LabelAtlas*)getChildByTag(ATLAS);
	static float t = 0;
	t += dt;
	String* str = String::createWithFormat("%d", (int)t);
	atlas->setString(str->getCString());
	/*CCString *str = CCString::createWithFormat("%d", (int)t);
	ttf->setString(str->getCString());*/
}