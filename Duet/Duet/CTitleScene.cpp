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
#include <string>

CTitleScene::CTitleScene() 
{
}

CTitleScene::~CTitleScene()
{

}

void CTitleScene::Init()
{
	//BACKGROUND
	CObject* BackGround = new CObject(Vector2D{340,490}, Vector2D{ 50,50 });
	BackGround->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	BackGround->SetTexture(CResourceManager::GetInstance()->FindTexture("BACKGROUND"));
	AddObject(OBJ_LAYER::BACKGROUND,BackGround);

	CObject* Ring = new CObject(Vector2D{340,600}, Vector2D{ 50,50 });
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
	CBlock* Block1 = new CBlock(Vector2D{ 120,0 }, Vector2D{ 50,50 });
	Block1->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block1->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block1);

	CBlock* Block2 = new CBlock(Vector2D{ 400,0 }, Vector2D{ 50,50 });
	Block2->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block2->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK3"));
	AddObject(OBJ_LAYER::BLOCK, Block2);

	CBlock* Block3 = new CBlock(Vector2D{ 145,-465 }, Vector2D{ 50,50 });
	Block3->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block3->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block3);

	CBlock* Block4 = new CBlock(Vector2D{ 435,-465 }, Vector2D{ 50,50 });
	Block4->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block4->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block4);
	/// ///////////////////////////////////////////////////////////////////
	CBlock* Block5 = new CBlock(Vector2D{ 545,-665 }, Vector2D{ 50,50 });
	Block5->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block5->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block5);

	CBlock* Block6 = new CBlock(Vector2D{ 455,-665 }, Vector2D{ 50,50 });
	Block6->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block6->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block6);

	CBlock* Block7 = new CBlock(Vector2D{ 115,-1000 }, Vector2D{ 50,50 });
	Block7->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block7->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block7);

	CBlock* Block8 = new CBlock(Vector2D{ 435,-1000 }, Vector2D{ 50,50 });
	Block8->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block8->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block8);
	//////////////////////////////////////////////////////////////////////////
	CBlock* Block9 = new CBlock(Vector2D{ 135,-1300 }, Vector2D{ 50,50 });
	Block9->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block9->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block9);

	CBlock* Block10 = new CBlock(Vector2D{ 228,-1300 }, Vector2D{ 50,50 });
	Block10->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block10->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block10);

	CBlock* Block11 = new CBlock(Vector2D{ 250,-1600 }, Vector2D{ 50,50 });
	Block11->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block11->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block11);

	CBlock* Block12 = new CBlock(Vector2D{ 550,-1600 }, Vector2D{ 50,50 });
	Block12->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block12->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block12);

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