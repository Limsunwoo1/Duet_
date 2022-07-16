#include "PlayerLife.h"
#include "Player.h"
#include "ResourceManager.h"
static unsigned int id = 0;
static int EntryPosition = 0;

CPlayerLife::CPlayerLife() : CUI(Vector2D{30 + EntryPosition, 30}, Vector2D{50, 50})
{
	mTarGetObj = nullptr;
	PlayerLife_Id = id;
	id++;
	EntryPosition += 50;
}

CPlayerLife::~CPlayerLife()
{
	id--;
	EntryPosition -= 50;
}

void CPlayerLife::Update(float InDeltaTime)
{
	if (mTarGetObj->GetmHeart() == PlayerLife_Id)
	{
		this->SetTexture(CResourceManager::GetInstance()->FindTexture("BROKENHEART"));
	}
}

void CPlayerLife::SetTarGetObj(CObject* InOBJ)
{
	mTarGetObj = dynamic_cast<CPlayer*> (InOBJ);
}