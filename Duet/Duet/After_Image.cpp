#include "After_Image.h"
#include "CTexture.h"
#include "EventManager.h"

CAfter_Image::CAfter_Image() : CObject(Vector2D{100, 100}, Vector2D{ 50, 50 })
{
	mTarGetBall = nullptr;
}
CAfter_Image::CAfter_Image(Vector2D InPositon, Vector2D InScale) : CObject(Vector2D{InPositon.x, InPositon.y}, Vector2D{ InScale.x, InScale.y })
{
	mTarGetBall = nullptr;
}

CAfter_Image::~CAfter_Image()
{
	
}

void CAfter_Image::Update(float InDeltaTime)
{
	CObject::Update(InDeltaTime);
}

void CAfter_Image::Render(HDC Inhdc)
{
	// SourceConstantAlpha 0 에 근접할수록 투명해짐

	BLENDFUNCTION bf = {};
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 10;

	AlphaBlend(Inhdc,
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