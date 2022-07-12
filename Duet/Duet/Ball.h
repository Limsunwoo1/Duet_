#pragma once
#include "Player.h"
#include "After_Image.h"
class CObject;

class CBall :
    public CPlayer
{
protected:
    int mAngle;
    std::vector<Vector2D> Circle;
    std::vector<CAfter_Image> ObjAfImg;
public:
    CBall();
    CBall(Vector2D InPosition, Vector2D InScale);
    ~CBall();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;
public:
    void AddAfterimage(String TextuerFilePath, float InDeltaTime);
    void Ball_InIt(CObject* InObject);
};

