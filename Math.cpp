#include "DXUT.h"
#include "Math.h"


Vector2 Math::RotateVec(Vector2 Vec, float Rot)
{
    
        float _Rot = D3DXToRadian(Rot);
        return Vector2(cos(_Rot) * Vec.x + -sin(_Rot) * Vec.y, sin(_Rot) * Vec.x + cos(_Rot) * Vec.y);
    
	
}

Math::Math()
{
}


Math::~Math()
{
}
