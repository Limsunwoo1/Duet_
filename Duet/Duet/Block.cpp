#include "Block.h"

CBlock::CBlock() : CObject(Vector2D{100, 100}, Vector2D{ 50, 50 })
{

}

CBlock::CBlock(Vector2D InPosition, Vector2D InScale) : CObject(Vector2D{InPosition.x, InPosition.y}, Vector2D{InScale.x, InScale.y})
{

}

CBlock::~CBlock()
{

}

void CBlock::Update(float InDeltaTime)
{
	Position.y += 1 * InDeltaTime * 200;
}