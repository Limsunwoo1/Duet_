#include "CStage1.h"
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
#include <string>

CStage1::CStage1()
{
}

CStage1::~CStage1()
{

}

void CStage1::Init()
{
	//BACKGROUND
	CObject* BackGround = new CObject(Vector2D{ 340,490 }, Vector2D{ 50,50 });
	BackGround->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	BackGround->SetTexture(CResourceManager::GetInstance()->FindTexture("BACKGROUND"));
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	CObject* Ring = new CObject(Vector2D{ 340,600 }, Vector2D{ 50,50 });
	Ring->SetObjectLayer(OBJ_LAYER::RING);
	Ring->SetTexture(CResourceManager::GetInstance()->FindTexture("RING"));
	AddObject(OBJ_LAYER::RING, Ring);

	//PLAYER
	Vector2D RIngPosition;
	CRedBall* RedBall = new CRedBall();
	RedBall->SetObjectLayer(OBJ_LAYER::BALL);
	RedBall->SetTexture(CResourceManager::GetInstance()->FindTexture("REDBALL"));
	RIngPosition.x = Ring->GetPosition().x + (Ring->GetScale().x * 0.45f);
	RIngPosition.y = Ring->GetPosition().y;
	RedBall->SetPosition(RIngPosition);
	RedBall->Ball_InIt(Ring);

	CBlueBall* BlueBall = new CBlueBall();
	BlueBall->SetObjectLayer(OBJ_LAYER::BALL);
	BlueBall->SetTexture(CResourceManager::GetInstance()->FindTexture("BLUEBALL"));
	RIngPosition.x = Ring->GetPosition().x - (Ring->GetScale().x * 0.45f);
	RIngPosition.y = Ring->GetPosition().y;
	BlueBall->SetPosition(RIngPosition);
	BlueBall->Ball_InIt(Ring);

	RedBall->SetOtherBall(BlueBall);
	BlueBall->SetOtherBall(RedBall);

	AddObject(OBJ_LAYER::BALL, RedBall);
	AddObject(OBJ_LAYER::BALL, BlueBall);

	//BLOCK
	CBlock* Block1 = new CBlock(Vector2D{ 100,100 }, Vector2D{ 50,50 });
	Block1->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block1->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block1);

	CBlock* Block2 = new CBlock(Vector2D{ 500,100 }, Vector2D{ 50,50 });
	Block2->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block2->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK2"));
	AddObject(OBJ_LAYER::BLOCK, Block2);

	//UI
	CPlayerLife* Heart;
	for (int i = 0; i < 3; ++i)
	{
		Heart = new CPlayerLife();
		Heart->SetObjectLayer(OBJ_LAYER::HEART);
		Heart->SetTexture(CResourceManager::GetInstance()->FindTexture("HEART"));
		Heart->SetTarGetObj(RedBall);
		AddObject(OBJ_LAYER::HEART, Heart);
	}
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

void CStage1::Render(HDC Inhdc)
{

}

void CStage1::Clear()
{
	CScene::Clear();
}

void CStage1::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}