#pragma once
#include "Object.h"
class Scrollmap 
{
private:

    texture* m_image;

public:



    float m_scroll;

    Scrollmap();
    ~Scrollmap();


    // Object��(��) ���� ��ӵ�
    void Init(texture* Backgrund);
    void Update(float speed);
    void Render();
    void Release();
 
 
};

