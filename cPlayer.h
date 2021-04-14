#pragma once
#include "Object.h"
class Bullet;
class ObjectManager;
class cPlayer :
    public Object
{
private:


    cFrame* m_Frame_5;
    VECtexture* m_Image;


    bool b_move;
    void Movement();


public:
    bool top;
    bool stop;
    bool b_Attack;
    Timer* anytime;
    Timer* dld;
    int anime = 0;
    bool dead;
    float p_hp = 1;
   void shootBullet();

    cPlayer();
    ~cPlayer();

        // Object을(를) 통해 상속됨
     void Init() override;
     void Update() override;
     void Render() override;
     void Release() override;
     void onCollisionStay(Object* obj) override;
     void onCollisionExit(Object* obj) override;
};

