#include "RePlay_ReTurn.h"
#include "Button.h"
#include "ResourceManager.h"
#include "CTitleScene.h"
#include "CStage1.h"
#include "CSceneManager.h"
#include "EventManager.h"

CRePlay_ReTurn::CRePlay_ReTurn()
{

}

CRePlay_ReTurn::~CRePlay_ReTurn()
{
	CRePlay_ReTurn::Clear();
}

void CRePlay_ReTurn::Init()
{
	//BACKGROUND
	//CObject* BackGround = new CObject(Vector2D{ 340,490 }, Vector2D{ 50,50 });
	//BackGround->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	//BackGround->SetTexture(CResourceManager::GetInstance()->FindTexture("BACKGROUND"));
	//AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	//UI
	CButton* RePlay = new CButton(Vector2D{ 340, 350 }, Vector2D{ 50, 50 });
	RePlay->SetObjectLayer(OBJ_LAYER::UI);
	RePlay->SetTexture(CResourceManager::GetInstance()->FindTexture("REPLAY"));
	RePlay->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, CRePlay_ReTurn::RePlay);
	AddObject(OBJ_LAYER::UI, RePlay);

	CButton* Return = new CButton(Vector2D{ 340, 550 }, Vector2D{ 50, 50 });
	Return->SetObjectLayer(OBJ_LAYER::UI);
	Return->SetTexture(CResourceManager::GetInstance()->FindTexture("RETURN"));
	Return->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, CRePlay_ReTurn::ReTurn);
	AddObject(OBJ_LAYER::UI, Return);
}

void CRePlay_ReTurn::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CRePlay_ReTurn::Clear()
{
	CRePlay_ReTurn::ClearObject();
}

void CRePlay_ReTurn::RePlay()
{
	CStage1* Stage1 = new CStage1();

	EventInfo SetScene;
	SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
	SetScene.Parameter = Stage1;

	CEventManager::GetInstance()->AddEvent(SetScene);
	CSceneManager::GetInstance()->ClearReGame();
}

void CRePlay_ReTurn::ReTurn()
{
	CTitleScene* Title = new CTitleScene();
	
	EventInfo SetScene;
	SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
	SetScene.Parameter = Title;

	CEventManager::GetInstance()->AddEvent(SetScene);
	CSceneManager::GetInstance()->ClearReGame();
}