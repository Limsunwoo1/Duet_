#pragma once
#include "Ball.h"
class CBlueBall :
    public CBall
{
public:
    CBlueBall();
    CBlueBall(Vector2D InPosition, Vector2D InScale);
    ~CBlueBall();
public:
    virtual void Update(float InDeltaTime) override;
};

