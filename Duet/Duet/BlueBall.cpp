#include "BlueBall.h"

CBlueBall::CBlueBall() : CBall(Vector2D{ 100,100 }, Vector2D{ 50,50 })
{
	SetmHeart(3);
	mAngle = 180;
	mPrevPosition = Position;
}

CBlueBall::CBlueBall(Vector2D InPosition, Vector2D InScale) : CBall(Vector2D{ InPosition.x, InPosition.y }, Vector2D{ InScale.x, InScale.y })
{
	SetmHeart(3);
	mAngle = 180;
	mPrevPosition = Position;
}

CBlueBall::~CBlueBall()
{

}

void CBlueBall::Update(float InDeltaTime)
{
	String rdefile = "BLUEBALL";
	CBlueBall::AddAfterimage(rdefile, InDeltaTime);
	
	static int cnt = 0;
	if (cnt >= 5)
	{
		CBall::Update(InDeltaTime);
		cnt = 0;
	}
	cnt++;
}