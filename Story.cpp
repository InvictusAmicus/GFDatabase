#include "Story.h"
#include "AudioEngine.h"
#include "Options.h"

int StoryTrack;
int StoryMenu;

USING_NS_CC;

Scene* Story::createScene()
{
	// 'scene' is an autorelease object
	auto StoryScene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Story::create();

	// add layer as a child to scene
	StoryScene->addChild(layer);

	// return the scene
	return StoryScene;
}

bool Story::init()
{

	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Options gameMusic;
	if (gameMusic.getMusicMute() != 1)
	{
		int V = gameMusic.getmusicVolume();
		StoryTrack = cocos2d::experimental::AudioEngine::play2d("GameWon.mp3", true, gameMusic.getMusicFloatVolume(V), nullptr);
	}

	//auto ReturnToTitle = MenuItemImage::create("Back.png", "BackClicked.png", CC_CALLBACK_1(MGameOverScreen::returnToTitleScreen, this));
	//ReturnToTitle->setPosition(Vec2(origin.x + visibleSize.width - ReturnToTitle->getContentSize().width, 70));
	//auto menu = Menu::create(ReturnToTitle, NULL);
	//menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 1);

	auto sprite = Sprite::create("Background.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	auto youLose = Label::createWithTTF("Player 1 has won", "fonts/Marker Felt.ttf", 70);
	youLose->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * (0.7)));
	youLose->setColor(cocos2d::Color3B::BLACK);
	this->addChild(youLose, 1);

	return true;
}

void Story::returnToTitleScreen(cocos2d::Ref* pSender)
{
	cocos2d::experimental::AudioEngine::stopAll();
	Options gameMusic;
	if (gameMusic.getMusicMute() != 1)
	{
		int V = gameMusic.getmusicVolume();
		StoryMenu = cocos2d::experimental::AudioEngine::play2d("MainMenu.mp3", true, gameMusic.getMusicFloatVolume(V), nullptr);
	}
	Director::getInstance()->popToRootScene();
}
