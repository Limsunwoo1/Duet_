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
#include "RePlay_ReTurn.h"
#include <string>

CStage1::CStage1()
{

}

CStage1::~CStage1()
{
	CStage1::ClearObject();
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

	SetPlayerHeartCnt(RedBall->GetmHeart());

	//BLOCK
	CBlock* Block1 = new CBlock(Vector2D{ 465,0 }, Vector2D{ 50,50 });
	Block1->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block1->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block1);

	CBlock* Block2 = new CBlock(Vector2D{ 465, -250 }, Vector2D{ 50,50 });
	Block2->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block2->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block2);

	CBlock* Block3 = new CBlock(Vector2D{ 225, -450 }, Vector2D{ 50,50 });
	Block3->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block3->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block3);

	CBlock* Block4 = new CBlock(Vector2D{ 225, -650 }, Vector2D{ 50,50 });
	Block4->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block4->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block4);

	CBlock* Block5 = new CBlock(Vector2D{ 600,-950 }, Vector2D{ 50,50 });
	Block5->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block5->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block5);

	CBlock* Block6 = new CBlock(Vector2D{ 430,-950 }, Vector2D{ 50,50 });
	Block6->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block6->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block6);

	CBlock* Block7 = new CBlock(Vector2D{ 100,-1250 }, Vector2D{ 50,50 });
	Block7->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block7->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block7);

	CBlock* Block8 = new CBlock(Vector2D{ 230,-1250 }, Vector2D{ 50,50 });
	Block8->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block8->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block8);

	/////////////////////////////////////////////////////////////////////////
	CBlock* Block9 = new CBlock(Vector2D{ 120,-1550 }, Vector2D{ 50,50 });
	Block9->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block9->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block9);

	CBlock* Block10 = new CBlock(Vector2D{ 450,-1550 }, Vector2D{ 50,50 });
	Block10->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block10->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block10);

	CBlock* Block11 = new CBlock(Vector2D{ 145,-1850 }, Vector2D{ 50,50 });
	Block11->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block11->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block11);

	CBlock* Block12 = new CBlock(Vector2D{ 435,-1850 }, Vector2D{ 50,50 });
	Block12->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block12->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block12);

	CBlock* Block13 = new CBlock(Vector2D{ 545,-2150 }, Vector2D{ 50,50 });
	Block13->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block13->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block13);

	CBlock* Block14 = new CBlock(Vector2D{ 455,-2150 }, Vector2D{ 50,50 });
	Block14->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block14->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block14);

	CBlock* Block15 = new CBlock(Vector2D{ 115,-2450 }, Vector2D{ 50,50 });
	Block15->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block15->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block15);

	CBlock* Block16 = new CBlock(Vector2D{ 435,-2450 }, Vector2D{ 50,50 });
	Block16->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block16->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block16);

	CBlock* Block17 = new CBlock(Vector2D{ 135,-2750 }, Vector2D{ 50,50 });
	Block17->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block17->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block17);

	CBlock* Block18 = new CBlock(Vector2D{ 228,-2750 }, Vector2D{ 50,50 });
	Block18->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block18->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block18);

	CBlock* Block19 = new CBlock(Vector2D{ 250,-3050 }, Vector2D{ 50,50 });
	Block19->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block19->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block19);

	CBlock* Block20 = new CBlock(Vector2D{ 550,-3050 }, Vector2D{ 50,50 });
	Block20->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block20->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block20);

	///////////////////////////////////////////////////////////////////////////
	CBlock* Block21 = new CBlock(Vector2D{ 120,-3350 }, Vector2D{ 50,50 });
	Block21->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block21->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block21);

	CBlock* Block22 = new CBlock(Vector2D{ 250,-3350 }, Vector2D{ 50,50 });
	Block22->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block22->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block22);

	CBlock* Block23 = new CBlock(Vector2D{ 120,-3650 }, Vector2D{ 50,50 });
	Block23->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block23->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block23);

	CBlock* Block24 = new CBlock(Vector2D{ 250,-3650 }, Vector2D{ 50,50 });
	Block24->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block24->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block24);

	CBlock* Block25 = new CBlock(Vector2D{ 120,-3950 }, Vector2D{ 50,50 });
	Block25->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block25->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block25);

	CBlock* Block26 = new CBlock(Vector2D{ 250,-3950 }, Vector2D{ 50,50 });
	Block26->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block26->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block26);

	CBlock* Block27 = new CBlock(Vector2D{ 120,-4250 }, Vector2D{ 50,50 });
	Block27->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block27->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block27);

	CBlock* Block28 = new CBlock(Vector2D{ 250,-4250 }, Vector2D{ 50,50 });
	Block28->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block28->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block28);

	CBlock* Block29 = new CBlock(Vector2D{ 510,-4550 }, Vector2D{ 50,50 });
	Block29->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block29->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block29);

	CBlock* Block30 = new CBlock(Vector2D{ 430,-4550 }, Vector2D{ 50,50 });
	Block30->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block30->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block30);

	CBlock* Block31 = new CBlock(Vector2D{ 120,-4850 }, Vector2D{ 50,50 });
	Block31->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block31->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block31);

	CBlock* Block32 = new CBlock(Vector2D{ 250,-4850 }, Vector2D{ 50,50 });
	Block32->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block32->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block32);

	////////////////////////////////////////////////////////////////////////////////
	CBlock* Block33 = new CBlock(Vector2D{ 465,-5150 }, Vector2D{ 50,50 });
	Block33->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block33->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block33);

	CBlock* Block34 = new CBlock(Vector2D{ 465, -5350 }, Vector2D{ 50,50 });
	Block34->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block34->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block34);

	CBlock* Block35 = new CBlock(Vector2D{ 225, -5550 }, Vector2D{ 50,50 });
	Block35->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block35->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block35);

	CBlock* Block36 = new CBlock(Vector2D{ 225, -5750 }, Vector2D{ 50,50 });
	Block36->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block36->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block36);

	CBlock* Block37 = new CBlock(Vector2D{ 480,-5950 }, Vector2D{ 50,50 });
	Block37->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block37->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block37);

	CBlock* Block38 = new CBlock(Vector2D{ 430,-6150 }, Vector2D{ 50,50 });
	Block38->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block38->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block38);

	CBlock* Block39 = new CBlock(Vector2D{ 170,-6350 }, Vector2D{ 50,50 });
	Block39->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block39->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block39);

	CBlock* Block40 = new CBlock(Vector2D{ 230,-6550 }, Vector2D{ 50,50 });
	Block40->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block40->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block40);

	/////////////////////////////////////////////////////////////////////////
	CBlock* Block41_ = new CBlock(Vector2D{ 120,-6850 }, Vector2D{ 50,50 });
	Block41_->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block41_->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block41_);

	CBlock* Block41 = new CBlock(Vector2D{ 430,-6850 }, Vector2D{ 50,50 });
	Block41->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block41->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block41);

	/*CBlock* Block42 = new CBlock(Vector2D{ 145,-6850 }, Vector2D{ 50,50 });
	Block42->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block42->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block42);

	CBlock* Block43 = new CBlock(Vector2D{ 435,-6850 }, Vector2D{ 50,50 });
	Block43->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block43->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block43);*/

	CBlock* Block44 = new CBlock(Vector2D{ 545,-7150 }, Vector2D{ 50,50 });
	Block44->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block44->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block44);

	CBlock* Block45 = new CBlock(Vector2D{ 455,-7150 }, Vector2D{ 50,50 });
	Block45->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block45->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block45);

	CBlock* Block46 = new CBlock(Vector2D{ 115,-7450 }, Vector2D{ 50,50 });
	Block46->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block46->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block46);

	CBlock* Block47 = new CBlock(Vector2D{ 435,-7450 }, Vector2D{ 50,50 });
	Block47->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block47->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block47);

	CBlock* Block48 = new CBlock(Vector2D{ 135,-7750 }, Vector2D{ 50,50 });
	Block48->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block48->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block48);

	CBlock* Block49 = new CBlock(Vector2D{ 228,-7750 }, Vector2D{ 50,50 });
	Block49->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block49->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block49);

	CBlock* Block50 = new CBlock(Vector2D{ 250,-8050 }, Vector2D{ 50,50 });
	Block50->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block50->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block50);

	CBlock* Block51 = new CBlock(Vector2D{ 550,-8050 }, Vector2D{ 50,50 });
	Block51->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block51->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block51);

	///////////////////////////////////////////////////////////////////////////
	CBlock* Block52 = new CBlock(Vector2D{ 120,-8350 }, Vector2D{ 50,50 });
	Block52->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block52->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block52);

	CBlock* Block53 = new CBlock(Vector2D{ 250,-8350 }, Vector2D{ 50,50 });
	Block53->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block53->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block53);

	CBlock* Block54 = new CBlock(Vector2D{ 120,-8650 }, Vector2D{ 50,50 });
	Block54->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block54->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block54);

	CBlock* Block55 = new CBlock(Vector2D{ 250,-8650 }, Vector2D{ 50,50 });
	Block55->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block55->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block55);

	CBlock* Block56 = new CBlock(Vector2D{ 120,-8950 }, Vector2D{ 50,50 });
	Block56->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block56->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block56);

	CBlock* Block57 = new CBlock(Vector2D{ 250,-8950 }, Vector2D{ 50,50 });
	Block57->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block57->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block57);

	CBlock* Block58 = new CBlock(Vector2D{ 120,-9250 }, Vector2D{ 50,50 });
	Block58->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block58->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block58);

	CBlock* Block59 = new CBlock(Vector2D{ 250,-9250 }, Vector2D{ 50,50 });
	Block59->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block59->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block59);

	CBlock* Block60 = new CBlock(Vector2D{ 540,-9550 }, Vector2D{ 50,50 });
	Block60->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block60->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block60);

	CBlock* Block61 = new CBlock(Vector2D{ 430,-9550 }, Vector2D{ 50,50 });
	Block61->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block61->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block61);

	CBlock* Block62 = new CBlock(Vector2D{ 120,-9850 }, Vector2D{ 50,50 });
	Block62->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block62->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block62);

	CBlock* Block63 = new CBlock(Vector2D{ 250,-9850 }, Vector2D{ 50,50 });
	Block63->SetObjectLayer(OBJ_LAYER::BLOCK);
	Block63->SetTexture(CResourceManager::GetInstance()->FindTexture("BLOCK1"));
	AddObject(OBJ_LAYER::BLOCK, Block63);

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

void CStage1::Render(HDC Inhdc)
{
	for (int layer = (int)OBJ_LAYER::BACKGROUND; layer < (int)OBJ_LAYER::MAX; ++layer)
	{
		for (int i = 0; i < OBJvector[layer].size(); ++i)
		{
			OBJvector[layer][i]->Render(Inhdc);
		}
	}
}

void CStage1::Clear()
{
	CScene::Clear();
}

void CStage1::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}