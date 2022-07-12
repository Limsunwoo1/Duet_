#include "Player.h"
#include "After_Image.h"
#include "KeyManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CTexture.h"

CPlayer::CPlayer() : CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{
	SetmHeart(3);
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y })
{
	SetmHeart(3);
}

CPlayer::~CPlayer()
{

}

void CPlayer::Update(float InDeltaTime)
{
	CObject::Update(InDeltaTime);
}

void CPlayer::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);

	mHeart -= 1;
	/*EventInfo eventInfo;
	eventInfo.Type = EVENT_TYPE::DELETE_OBJECT;
	eventInfo.Parameter = new OBJ_LAYER(ObjLayer);
	eventInfo.Parameter2 = this;
	CEventManager::GetInstance()->AddEvent(eventInfo);*/
}

void CPlayer::Render(HDC InHdc)
{
	// 알파값 == 투명값
	// 투명하게 띄우는거, 반투명하게 띄우는거를 알파블렌딩 이라고 한다
	// 색상을 섞는다는 블렌딩의 의미

	// bmp 파일은 보통 색상이 24비트짜리
	// R : 8비트
	// G : 8비트
	// B : 8비트 0 ~ 255 값
	// 32 비트는 여기에 A : 8 비트가 추가된 값 ( 알파값 )

	if (Texture)
	{
		// 32비트 bmp 는 bf.AlphaFormat = AC_SRC_ALPHA
		// 24비트 bmp 는 bf.AlphaFormat = 0

		BLENDFUNCTION bf = {};
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = 0;
		bf.SourceConstantAlpha = 255;

		AlphaBlend(InHdc,
			(int)(Position.x - (Texture->GetWidth() * 0.5f)),
			(int)(Position.y - (Texture->GetHeight() * 0.5f)),
			Texture->GetWidth(),
			Texture->GetHeight(),
			Texture->GetHdc(),
			0,
			0,
			Texture->GetWidth(),
			Texture->GetHeight(),
			bf);
	}
	else
	{
		Rectangle(InHdc,
			(int)(Position.x - (Scale.x * 0.5f)),
			(int)(Position.y - (Scale.y * 0.5f)),
			(int)(Position.x + (Scale.x * 0.5f)),
			(int)(Position.y + (Scale.y * 0.5f)));
	}
}

void CPlayer::AddAfterimage(String TextuerFilePath, float InDeltaTime)
{
	static float  delta = 0.0f;
	delta += InDeltaTime;
	if(delta > 0.1f)
	if ((mPrevPosition.x != Position.x) || (mPrevPosition.y != Position.y))
	{
		CAfter_Image* InObject = new CAfter_Image(Vector2D{ Position.x, Position.y }, Vector2D{ Position.x, Position.y });
		InObject->SetTexture(CResourceManager::GetInstance()->FindTexture(TextuerFilePath));

		EventInfo Addimage;
		Addimage.Type = EVENT_TYPE::ADD_OBJECT;
		Addimage.Parameter = new OBJ_LAYER(OBJ_LAYER::AFTER_IMAGE);
		Addimage.Parameter2 = InObject;

		CEventManager::GetInstance()->AddEvent(Addimage);
		delta -= 0.01f;
	}

	mPrevPosition = Position;
}