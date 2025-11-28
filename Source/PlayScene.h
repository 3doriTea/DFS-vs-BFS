#pragma once
#include "../Library/SceneBase.h"
#include "Dig/DiggingDungeon.h"
#include "Dig/DungeonViewer.h"
#include "IDataList.h"
#include "CellInfo.h"


class Player;

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	DiggingDungeon diggingDungeon_;
	DungeonViewer viewer_;
	float timeLeft_;
	Player* pPlayer_;
	IDataList<Cell*>* pCellData_;

	static int playCount_;
};
