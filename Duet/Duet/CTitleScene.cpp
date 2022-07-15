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
	// UI�� �浹üũ�ϸ� ������ ���ϼ��� ���� üũ�ص� UI ������ �ϵ��� ����
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::BALL);
	checkLayerList.push_back(OBJ_LAYER::BALL);
	CheckCollisionLayer[OBJ_LAYER::BLOCK] = checkLayerList;


	LOG("�Ϲ� �α� �׽�Ʈ");
	WARN_LOG("��� �α� �׽�Ʈ");
	ERROR_LOG("���� �α� �׽�Ʈ");
	ETC1_LOG("Ŀ���� �α� �׽�Ʈ");
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