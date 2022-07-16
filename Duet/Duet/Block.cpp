#include "Block.h"
#include "CTexture.h"
#include "After_Image.h"
#include "ResourceManager.h"
CBlock::CBlock() : CObject(Vector2D{100, 100}, Vector2D{ 50, 50 })
{
	alph = 255;
}

CBlock::CBlock(Vector2D InPosition, Vector2D InScale) : CObject(Vector2D{InPosition.x, InPosition.y}, Vector2D{InScale.x, InScale.y})
{
	alph = 255;
}

CBlock::~CBlock()
{

}

void CBlock::Update(float InDeltaTime)
{
	if (Position.y >= 10000)
	{
		Position.y = 0;
		alph = 255;
	}

	Position.y += 1 * InDeltaTime * 200;

	if (Position.y >= 730)
		alph -= 1;	
}

void CBlock::Render(HDC InHdc)
{
	if (Texture)
	{
		// 32비트 bmp 는 bf.AlphaFormat = AC_SRC_ALPHA
		// 24비트 bmp 는 bf.AlphaFormat = 0
		if (alph <= 0)
			alph = 0;

		BLENDFUNCTION bf = {};
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = 0;
		bf.SourceConstantAlpha = alph;

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
}