#include "SimpleAudioEngine.h"
#include "AudioEngine.h"
#include "Story.h"
#include "Options.h"
#include <fstream>
#include <string>
#include "NewSinglePlayGame.h"

USING_NS_CC;

int StartMusicVolume;
int MenuMusicMute;
int StartTrack;
int SoundEffectsVolume;
int MenuEffectsMute;

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

	SystemFile();
	PlayMusic();

	if (MenuMusicMute == 0)
	{
		CCLOG("MenuMusicMute if statement");
		CCLOG("%d", StartMusicVolume);
		Options playM;
		StartTrack = cocos2d::experimental::AudioEngine::play2d("MainMenu.mp3", true, playM.getMusicFloatVolume(StartMusicVolume), nullptr);
	}

	auto toGame = MenuItemImage::create("Play.png","PlayClicked.png", CC_CALLBACK_1(Story::toGame, this));
	toGame->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - toGame->getContentSize().height * 6));
	auto menuNewGame = Menu::create(toGame, NULL);
	menuNewGame->setPosition(Vec2::ZERO);
	this->addChild(menuNewGame, 1);

	return true;
}

void Story::toGame(Ref* pSender)
{
	cocos2d::experimental::AudioEngine::stopAll();
	auto NewGameScene = NewSinglePlayGame::createScene();
	Director::getInstance()->pushScene(NewGameScene);
}

void Story::SystemFile()
{
	CCLOG("START OF SYSTEM FILE");
	FileUtils::getInstance()->addSearchPath("SystemFile");
	std::string DataFileName = "System_File.txt";
	std::string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(DataFileName.c_str());
	std::ifstream ReadFile(fullpath);
	std::string text;
	if (!ReadFile)
	{
		CCLOG("FILE NOT FOUND");
	}
	else
	{
		for (int x = 0; x < 4; x++)
		{
			if (x == 0)
			{
				getline(ReadFile, text);
				int testFileInt = atoi(text.c_str());
				std::string::size_type sz;
				StartMusicVolume = std::stof(text, &sz);
				CCLOG("MVC %d", StartMusicVolume);
				Options GameMusic;
				GameMusic.setMV(StartMusicVolume);
			}
			if (x == 1)
			{
				getline(ReadFile, text);
				int testFileInt = atoi(text.c_str());
				std::string::size_type sz;
				SoundEffectsVolume = std::stof(text, &sz);
				Options GameMusic;
				GameMusic.setSEV(SoundEffectsVolume);
				CCLOG("SEVC %d", SoundEffectsVolume);
			}
			if (x == 2)
			{
				getline(ReadFile, text);
				MenuEffectsMute = atoi(text.c_str());
				Options GameMusic;
				GameMusic.setSEVMute(MenuEffectsMute);
				CCLOG("EFFECTS MUTE %d", MenuEffectsMute);
			}
			if (x == 3)
			{
				getline(ReadFile, text);
				MenuMusicMute = atoi(text.c_str());
				CCLOG("MUSIC MUTE %d", MenuMusicMute);
				Options GameMusic;
				GameMusic.setMute(MenuMusicMute);
			}

			CCLOG("X == %d", x);
		}
		ReadFile.close();
	}
	CCLOG("END OF System FILE");
}

void Story::PlayMusic()
{
	CCLOG("START OF PLAY MUSIC");

	if (StartMusicVolume == 0)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.0f);
	}
	else if (StartMusicVolume > 0 && StartMusicVolume < 10)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.1f);
	}
	else if (StartMusicVolume >= 10 && StartMusicVolume < 20)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.2f);
	}
	else if (StartMusicVolume >= 20 && StartMusicVolume < 30)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.3f);
	}
	else if (StartMusicVolume >= 30 && StartMusicVolume < 40)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.4f);
	}
	else if (StartMusicVolume >= 40 && StartMusicVolume < 50)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.5f);
	}
	else if (StartMusicVolume >= 50 && StartMusicVolume < 60)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.6f);
	}
	else if (StartMusicVolume >= 60 && StartMusicVolume < 70)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.7f);
	}
	else if (StartMusicVolume >= 70 && StartMusicVolume < 80)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.8f);
	}
	else if (StartMusicVolume >= 80 && StartMusicVolume < 90)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 0.9f);
	}
	else if (StartMusicVolume >= 90 && StartMusicVolume <= 100)
	{
		cocos2d::experimental::AudioEngine::setVolume(StartTrack, 1.0f);
	}
	CCLOG("END OF PLAY MUSIC");
}