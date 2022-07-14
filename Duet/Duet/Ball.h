#pragma once
#include "Player.h"
#include "After_Image.h"
class CObject;

class CBall :
    public CPlayer
{
protected:
    int                       mAngle;
    std::vector<Vector2D>     Circle;
    std::vector<CAfter_Image> ObjAfImg;
    CBall*                    mOtherBall;
    int                       alph;
    PROTECT_MEMBER(float, mCollsionDelTa)
    PROTECT_MEMBER(bool, mRenderTime)
public:
    CBall();
    CBall(Vector2D InPosition, Vector2D InScale);
    ~CBall();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;
    virtual void Collision(const CObject* InOtherObject) override;
public:
    void AddAfterimage(String TextuerFilePath, float InDeltaTime);
    int BlinkRender();
    void Ball_InIt(CObject* InObject);
    void SetOtherBall(CBall* InOtherBall) { mOtherBall = InOtherBall; };
};

