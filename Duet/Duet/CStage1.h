#pragma once
#include "CScene.h"
#include "Define.h"

class CStage1 :
    public CScene
{
private:
    MEMBER(int, PlayerHeartCnt)
public:
    CStage1();
    virtual ~CStage1();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;
};

