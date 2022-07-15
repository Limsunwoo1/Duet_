#pragma once
#include "CScene.h"
class CRePlay_ReTurn :
    public CScene
{
public:
    CRePlay_ReTurn();
    virtual ~CRePlay_ReTurn();

public:
    virtual void Init() override;
    virtual void Update(float InDeltaTime) override;
    virtual void Clear() override;

    static void RePlay();
    static void ReTurn();
};

