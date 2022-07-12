#include "Ball.h"
#include "KeyManager.h"
#include "ResourceManager.h"
#include "CTexture.h"
CBall::CBall() : CPlayer(Vector2D{100,100}, Vector2D{ 50,50 })
{
	mPrevPosition = Position;
}

CBall::CBall(Vector2D InPosition, Vector2D InScale) : CPlayer(Vector2D{ InPosition.x, InPosition.y }, Vector2D{ InScale.x, InScale.y })
{
	mPrevPosition = Position;
}

CBall::~CBall()
{
	
}

void CBall::Update(float InDeltaTime)
{
	for (CAfter_Image InImage : ObjAfImg)
	{
		InImage.Update(InDeltaTime);
	}

	if (KEY_STATE(KEY::A) == KEY_STATE::HOLD)
	{
		if (mAngle <= 0)
			mAngle = 360;

		mAngle--;
	}

	if (KEY_STATE(KEY::D) == KEY_STATE::HOLD)
	{
		if (mAngle >= 359)
			mAngle = -1;
		
		mAngle++;
	}

	Position = Circle[mAngle];
}

void CBall::Render(HDC InHdc)
{
	for (CAfter_Image InImage : ObjAfImg)
	{
		InImage.Render(InHdc);
	}

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

void CBall::Ball_InIt(CObject* InObject)
{
	Vector2D push_vector;
	float length = UtilMath::Length(Vector2D(Position - InObject->GetPosition()));
	for (int i = 0; i < 360; ++i)
	{
		push_vector.x = (UtilMath::Cos((float)i) * length) + InObject->GetPosition().x;
		push_vector.y = (UtilMath::Sin((float)i) * length) + InObject->GetPosition().y;

		Circle.push_back(push_vector);
	}
}

void CBall::AddAfterimage(String TextuerFilePath, float InDeltaTime)
{
	if (ObjAfImg.size() >= 10)
	{
		ObjAfImg.erase(ObjAfImg.begin());
	}

	static float  delta = 0.0f;
	delta += InDeltaTime;
	if (delta > 0.01f)
	{
		if ((mPrevPosition.x != Position.x) || (mPrevPosition.y != Position.y))
		{
			CAfter_Image InObject = CAfter_Image(Vector2D{ Position.x, Position.y }, Vector2D{ Position.x, Position.y });
			InObject.SetTexture(CResourceManager::GetInstance()->FindTexture(TextuerFilePath));

			ObjAfImg.push_back(InObject);
		}
		delta -= 0.01f;
	}

	mPrevPosition = Position;
}