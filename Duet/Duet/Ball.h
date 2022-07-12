#pragma once
#include "Player.h"

class CObject;

class CBall :
    public CPlayer
{
protected:
    int mAngle;
    std::vector<Vector2D> Circle;
public:
    CBall();
    CBall(Vector2D InPosition, Vector2D InScale);
    ~CBall();

    virtual void Update(float InDeltaTime) override;
public:
    void Ball_InIt(CObject* InObject);
};

