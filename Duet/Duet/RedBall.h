#pragma once
#include "Ball.h"
class CRedBall :
    public CBall
{
public:
    CRedBall();
    CRedBall(Vector2D InPosition, Vector2D InScale);
    ~CRedBall();

public:
    virtual void Update(float InDeltaTime) override;
};

