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
	// ���İ� == ����
	// �����ϰ� ���°�, �������ϰ� ���°Ÿ� ���ĺ��� �̶�� �Ѵ�
	// ������ ���´ٴ� ������ �ǹ�

	// bmp ������ ���� ������ 24��Ʈ¥��
	// R : 8��Ʈ
	// G : 8��Ʈ
	// B : 8��Ʈ 0 ~ 255 ��
	// 32 ��Ʈ�� ���⿡ A : 8 ��Ʈ�� �߰��� �� ( ���İ� )

	if (Texture)
	{
		// 32��Ʈ bmp �� bf.AlphaFormat = AC_SRC_ALPHA
		// 24��Ʈ bmp �� bf.AlphaFormat = 0

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