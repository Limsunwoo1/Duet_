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
	RedBall->SetObjectLayer(OBJ_LAYER::REDBALL);
	RedBall->SetTexture(CResourceManager::GetInstance()->FindTexture("REDBALL"));
	RIngPosition.x = Ring->GetPosition().x + (Ring->GetScale().x * 0.45f);
	RIngPosition.y = Ring->GetPosition().y;
	RedBall->SetPosition(RIngPosition);
	RedBall->Ball_InIt(Ring);
	AddObject(OBJ_LAYER::REDBALL, RedBall);

	CBlueBall* BlueBall = new CBlueBall();
	BlueBall->SetObjectLayer(OBJ_LAYER::BLUEBALL);
	BlueBall->SetTexture(CResourceManager::GetInstance()->FindTexture("BLUEBALL"));
	RIngPosition.x = Ring->GetPosition().x - (Ring->GetScale().x * 0.45f);
	RIngPosition.y = Ring->GetPosition().y;
	BlueBall->SetPosition(RIngPosition);
	BlueBall->Ball_InIt(Ring);
	AddObject(OBJ_LAYER::BLUEBALL, BlueBall);

	//BLOCK
	CObject* Block1 = new CObject(Vector2D{ 300,100 }, Vector2D{ 50,50 });
	Block1->SetObjectLayer(OBJ_LAYER::BLOCK1);
	Block1->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK1, Block1);

	CObject* Block2 = new CObject(Vector2D{ 300,200 }, Vector2D{ 50,50 });
	Block2->SetObjectLayer(OBJ_LAYER::BLOCK2);
	Block2->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK2"));
	AddObject(OBJ_LAYER::BLOCK2, Block2);

	CObject* Block3 = new CObject(Vector2D{ 300,300 }, Vector2D{ 50,50 });
	Block3->SetObjectLayer(OBJ_LAYER::BLOCK3);
	Block3->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK3"));
	AddObject(OBJ_LAYER::BLOCK3, Block3);

	//UI
	CUI* Heart = new CUI(Vector2D{ 30,30 }, Vector2D{ 50,50 });
	Heart->SetObjectLayer(OBJ_LAYER::HEART);
	Heart->SetTexture(CResourceManager::GetInstance()->FindTexture("HEART"));
	AddObject(OBJ_LAYER::HEART, Heart);

	Heart = new CUI(Vector2D{ 80,30 }, Vector2D{ 50,50 });
	Heart->SetObjectLayer(OBJ_LAYER::HEART);
	Heart->SetTexture(CResourceManager::GetInstance()->FindTexture("HEART"));
	AddObject(OBJ_LAYER::HEART, Heart);

	Heart = new CUI(Vector2D{ 130,30 }, Vector2D{ 50,50 });
	Heart->SetObjectLayer(OBJ_LAYER::HEART);
	Heart->SetTexture(CResourceManager::GetInstance()->FindTexture("HEART"));
	AddObject(OBJ_LAYER::HEART, Heart);

	// UI는 충돌체크하면 로직이 꼬일수도 있음 체크해도 UI 끼리만 하도록 주의
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::REDBALL);
	checkLayerList.push_back(OBJ_LAYER::BLUEBALL);
	CheckCollisionLayer[OBJ_LAYER::BLOCK1] = checkLayerList;
	CheckCollisionLayer[OBJ_LAYER::BLOCK2] = checkLayerList;
	CheckCollisionLayer[OBJ_LAYER::BLOCK3] = checkLayerList;

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