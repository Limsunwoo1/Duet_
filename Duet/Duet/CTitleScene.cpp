#include "CTitleScene.h"
#include "Func.h"
#include "Button.h"
#include "Player.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "UtilLog.h"
#include "Loger.h"
#include "UtilMath.h"
#include "RedBall.h"
#include "BlueBall.h"
#include "Block.h"
#include "PlayerLife.h"
#include "CStage1.h"
#include <string>

CTitleScene::CTitleScene() 
{
}

CTitleScene::~CTitleScene()
{
	CScene::Clear();
}

void CTitleScene::Init()
{
	//BACKGROUND
	CObject* BackGround = new CObject(Vector2D{340,490}, Vector2D{ 50,50 });
	BackGround->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	BackGround->SetTexture(CResourceManager::GetInstance()->FindTexture("DUET"));
	AddObject(OBJ_LAYER::BACKGROUND,BackGround);

	//UI
	CButton* GameRun = new CButton(Vector2D{ 340, 850 }, Vector2D{ 50, 50 });
	GameRun->SetTexture(CResourceManager::GetInstance()->FindTexture("GAMESTART"));
	GameRun->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, GameStart);
	AddObject(OBJ_LAYER::UI, GameRun);
	// UI는 충돌체크하면 로직이 꼬일수도 있음 체크해도 UI 끼리만 하도록 주의
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::BALL);
	checkLayerList.push_back(OBJ_LAYER::BALL);
	CheckCollisionLayer[OBJ_LAYER::BLOCK] = checkLayerList;


	LOG("일반 로그 테스트");
	WARN_LOG("경고 로그 테스트");
	ERROR_LOG("에러 로그 테스트");
	ETC1_LOG("커스텀 로그 테스트");
}

void CTitleScene::Clear()
{	
	CScene::Clear();
}

void CTitleScene::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CTitleScene::GameStart()
{
	CStage1* StageStart = new CStage1();
	CSceneManager::GetInstance()->SetCurScene(StageStart);
}