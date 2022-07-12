#pragma once
#include "Object.h"
#include <queue>

class CAfter_Image :
    public CObject
{
private:
    CObject*    mTarGetBall;
    float       Alpha;
public:
    CAfter_Image();
    CAfter_Image(Vector2D InPositon, Vector2D InScale);
    ~CAfter_Image();
public:
    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;

    void SetTarGetBall(CObject* InBall){mTarGetBall = InBall;};
};

