#pragma once
#include "UI.h"

class CPlayer;

class CPlayerLife :
    public CUI
{
private:
    unsigned int        PlayerLife_Id;
    CPlayer*            mTarGetObj;
public:
    CPlayerLife();
    ~CPlayerLife();

    virtual void Update(float InDeltaTime) override;
    void SetTarGetObj(CObject* InOBJ);
};

