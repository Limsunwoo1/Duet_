#pragma once
#include "Object.h"
#include <string>
class CPlayer :
    public CObject
{
    MEMBER(int, mHeart);
protected:
    Vector2D mPrevPosition;
public:
    CPlayer();
    CPlayer(Vector2D InVector, Vector2D InScale);
    virtual ~CPlayer();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;
    virtual void Collision(const CObject* InOtherObject) override;
};