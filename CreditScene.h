#pragma once
#include "Scene.h"
class Scrollmap;
class CreditScene :
    public Scene
{
private:
    Scrollmap* m_map;
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

