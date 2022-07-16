#pragma once
#include "Object.h"
#include <vector>

class CAfter_Image;

class CBlock :
    public CObject
{
private:
    int alph;
public:
    CBlock();
    CBlock(Vector2D InPosition, Vector2D InScale);
    ~CBlock();
public:
    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;
};

