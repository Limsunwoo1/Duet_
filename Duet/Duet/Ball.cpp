#include "Ball.h"
#include "KeyManager.h"
CBall::CBall() : CPlayer(Vector2D{100,100}, Vector2D{ 50,50 })
{
	mPrevPosition = Position;
}

CBall::CBall(Vector2D InPosition, Vector2D InScale) : CPlayer(Vector2D{ InPosition.x, InPosition.y }, Vector2D{ InScale.x, InScale.y })
{
	mPrevPosition = Position;
}

CBall::~CBall()
{
	
}

void CBall::Update(float InDeltaTime)
{
	if (KEY_STATE(KEY::A) == KEY_STATE::HOLD)
	{
		if (mAngle <= 0)
			mAngle = 360;

		mAngle--;
	}

	if (KEY_STATE(KEY::D) == KEY_STATE::HOLD)
	{
		if (mAngle >= 359)
			mAngle = -1;
		
		mAngle++;
	}

	Position = Circle[mAngle];
}

void CBall::Ball_InIt(CObject* InObject)
{
	Vector2D push_vector;
	float length = UtilMath::Length(Vector2D(Position - InObject->GetPosition()));
	for (int i = 0; i < 360; ++i)
	{
		push_vector.x = (UtilMath::Cos((float)i) * length) + InObject->GetPosition().x;
		push_vector.y = (UtilMath::Sin((float)i) * length) + InObject->GetPosition().y;

		Circle.push_back(push_vector);
	}
}