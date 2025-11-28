#include "PlayScene.h"
#include "../Library/Time.h"
#include "Player.h"
#include "StackAndQueue.h"

namespace
{
	const float SEARCH_INTERVAL{ 0.01f };
	const float TO_RELOAD_SCENE_TIME{ 3.0f };
}

int PlayScene::playCount_{ 0 };

PlayScene::PlayScene() :
	diggingDungeon_{ 43, 13 },
	timeLeft_{ SEARCH_INTERVAL },
	viewer_{ diggingDungeon_ },
	pPlayer_{ nullptr }
{
	diggingDungeon_.Generate();
	if (playCount_ % 2 == 0)
	{
		pCellData_ = static_cast<IDataList<Cell*>*>(new DataQueue<Cell*>{});
	}
	else
	{
		pCellData_ = static_cast<IDataList<Cell*>*>(new DataStack<Cell*>{});
	}

	playCount_++;
	pPlayer_ = new Player{ viewer_, pCellData_ };
}

PlayScene::~PlayScene()
{
	if (pCellData_)
	{
		delete pCellData_;
	}
}

void PlayScene::Update()
{
	if (pPlayer_->IsComplete())
	{
		timeLeft_ -= Time::DeltaTime();
		if (timeLeft_ <= 0.0f)
		{
			SceneManager::ReloadScene();
		}

		return;
	}

	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
		return;
	}

	timeLeft_ -= Time::DeltaTime();
	{
		pPlayer_->Step();
		if (pPlayer_->IsComplete())
		{
			timeLeft_ += TO_RELOAD_SCENE_TIME;
		}
		else
		{
			timeLeft_ += SEARCH_INTERVAL;
		}
	}
}

void PlayScene::Draw()
{
	viewer_.View();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
