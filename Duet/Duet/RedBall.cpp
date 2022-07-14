#include "RedBall.h"
CRedBall::CRedBall() : CBall(Vector2D{ 100,100 }, Vector2D{ 50,50 })
{
	SetmHeart(3);
	mAngle = 0;
	mPrevPosition = Position;
}

CRedBall::CRedBall(Vector2D InPosition, Vector2D InScale) : CBall(Vector2D{ InPosition.x, InPosition.y }, Vector2D{ InScale.x, InScale.y })
{
	SetmHeart(3);
	mAngle = 0;
	mPrevPosition = Position;
}

CRedBall::~CRedBall()
{

}

void CRedBall::Update(float InDeltaTime)
{
	String rdefile = "REDBALL";
	CRedBall::AddAfterimage(rdefile, InDeltaTime);
	CBall::Update(InDeltaTime);
	/*static int cnt = 0;
	if (cnt >= 5)
	{
		CBall::Update(InDeltaTime);
		cnt = 0;
	}
	cnt++;*/
}