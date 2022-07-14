#pragma once
#include "Object.h"
class CBlock :
    public CObject
{
public:
    CBlock();
    CBlock(Vector2D InPosition, Vector2D InScale);
    ~CBlock();
public:
    virtual void Update(float InDeltaTime) override;
};

