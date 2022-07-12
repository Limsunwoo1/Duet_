#include "ResourceManager.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
{
	Hdc = nullptr;
	HInstance = nullptr;
}

CResourceManager::~CResourceManager()
{
	for (std::pair<string, CTexture*> textureInfo : TextureList)
		delete textureInfo.second;

	TextureList.clear();
}

void CResourceManager::Init(HINSTANCE InHInst, HDC InHdc)
{
	HInstance = InHInst;
	Hdc = InHdc;


	LoadTexture("BACKGROUND",L"Texture/BackGround.bmp");
	LoadTexture("RING", L"Texture/Circle.bmp");
	LoadTexture("BLOCK1", L"Texture/huddle1.bmp");
	LoadTexture("BLOCK2", L"Texture/huddle2.bmp");
	LoadTexture("BLOCK3", L"Texture/huddle3.bmp");
	LoadTexture("REDBALL", L"Texture/RedBall.bmp");
	LoadTexture("BLUEBALL", L"Texture/BlueBall.bmp");
	LoadTexture("HEART", L"Texture/Heart.bmp");
	LoadTexture("BROKENHEART", L"Texture/BrokenHeart.bmp");
}

CTexture* CResourceManager::LoadTexture(const string& InName, const wstring& InFilePath)
{
	CTexture* texture = FindTexture(InName);
	if (texture)
		return texture;

	texture = new CTexture;
	if (!texture)
		return nullptr;

	if (texture->LoadTexture(InName, HInstance, Hdc, InFilePath))
	{
		TextureList.emplace(make_pair(InName, texture));
	}
	else
	{
		delete texture;
		texture = nullptr;
	}

	return texture;
}

CTexture* CResourceManager::FindTexture(const string& InName)
{
	//find 에 실패하면 iter에는 end() 값이 담긴다
	auto iter = TextureList.find(InName);
	if (iter == TextureList.end())
		return nullptr;

	return iter->second;
}
