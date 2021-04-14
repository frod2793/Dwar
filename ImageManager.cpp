#include "DXUT.h"
#include "ImageManager.h"

void texture::CenterRender(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}

void texture::Render(Vector2 pos, float rot, Vector2 size)
{
	IMAGE->Render(this, pos, rot, size);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}


ImageManager::ImageManager()
	:m_sprite(nullptr)
{
	Init();
}


ImageManager::~ImageManager()
{
	Release();
}

//불러올 이미지를 부를 이름과 경로
texture* ImageManager::AddImage(const string& key, const string& path, const int& number)
{
	auto find = m_images.find(key);//이미 있는 이름을 다시 쓰려고 하는게 아닌지 확인해본다
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			LoadCount++;
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
#pragma region 로딩실패
		//DEBUG_LOG("ERROR! 이미지 로딩에 실패했습니다. 파일경로를 다시 확인해주세요");
		//DEBUG_LOG("\tkey : %s\t path : %s", key.c_str(), path.c_str());
#pragma endregion
		//이미지 로딩이 실패했을경우(없는 파일, cpu메모리 부족등등) 이곳으로 오게 된다
		return nullptr;
	}
	//이미 불러온 이미지를 다시 불러오려 했거나
	//다른 이미지를 같은 이름으로 쓰고 있을경우 이곳으로 오게 된다
	return find->second;
}

texture* ImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//이름으로 이미지를 찾아본다
	if (find == m_images.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

VECtexture* ImageManager::ADDVECIMAGE(const string & key, const string & path, int max)
{
	auto find = vecImages.find(key);
	if (find != vecImages.end())
		return find->second;

	VECtexture* vec = new VECtexture();

	for (int i = 1; i <= max; i++)
	{
		LPDIRECT3DTEXTURE9 lpTexture;
		D3DXIMAGE_INFO info;

		char ch[256];
		sprintf(ch, "%s/(%d).png", path.c_str(), i);

		if (D3DXCreateTextureFromFileExA(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lpTexture) == S_OK)
		{
			LoadCount++;
			texture * text = new texture(lpTexture, info);
			vec->ADDIMAGE(text);
		}
		
	}

	vecImages.insert(make_pair(key, vec));
	return vec;
}

VECtexture* ImageManager::FINDVECIMAGE(const string & key, int max)
{
	return vecImages[key];
}

void ImageManager::Init()
{
#pragma region Load
	AddImage("BackGround", "./Resource/Back.png");
	AddImage("title", "./Resource/title.png");
	AddImage("PL", "./Resource/BUT.png");
	AddImage("CL", "./Resource/CREDIT.png");
	AddImage("OP", "./Resource/OP.png");
	AddImage("TL", "./Resource/TLT.png");
	AddImage("QT", "./Resource/QT.png");
	AddImage("Mouse", "./Resource/Mouse.png");
	AddImage("Player", "./Resource/(1).png");
	AddImage("bullet", "./Resource/bullet.png");
	AddImage("bbt", "./Resource/bbt.png");
	AddImage("enemy", "./Resource/Enemy.png");
	AddImage("TE", "./Resource/TE.png");
	AddImage("end", "./Resource/end.png");
	AddImage("hp", "./Resource/hp.png");
	AddImage("stop", "./Resource/T.png");
	AddImage("OPP", "./Resource/P.png");
	AddImage("clear", "./ Resource / clear.png");

	ADDVECIMAGE("effect", "./Resource/effect", 6);
	ADDVECIMAGE("player", "./Resource/player", 5);
	ADDVECIMAGE("boss", "./Resource/Boss", 2);
	ADDVECIMAGE("End", "./Resource/End", 7);
#pragma endregion

	D3DXCreateSprite(g_device, &m_sprite);
	D3DXCreateSprite(g_device, &m_sprite2);
}

void ImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	for (auto iter : vecImages)
	{
		SAFE_DELETE(iter.second);
	}
	vecImages.clear();

	m_sprite->Release();
	m_sprite2->Release();
}

void ImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	m_sprite2->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void ImageManager::End()
{
	m_sprite->End();
	m_sprite2->End();
}

void ImageManager::CenterRender(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(texturePtr->info.Width / 2, texturePtr->info.Height / 2);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void ImageManager::Render(texture* texturePtr, Vector2 pos, float rot, Vector2 size)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(0, 0);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}


void ImageManager::drawText(const string& str, Vector2 pos, float size, D3DCOLOR color, bool Center)
{
	D3DXMATRIXA16 mat;
	if (!Center)
	{
		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else
	{
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, 0);
	}
	m_sprite->SetTransform(&mat);
	lpFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(lpFont);
}

void ImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
	m_sprite2->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
	m_sprite2->OnResetDevice();
	
}


VECtexture::VECtexture()
{
}

VECtexture::~VECtexture()
{
	for (auto iter : m_VecTex) {
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_VecTex.clear();
}

void VECtexture::ADDIMAGE(texture* tempImage)
{
	m_VecTex.push_back(tempImage);
}

texture* VECtexture::FINDIMAGE(int count)
{
	if (count == -1)
		return m_VecTex[0];
	else
		return m_VecTex[count];
}



void cFrame::SetFrame(int start, int end, unsigned long delay)
{
	NowFrame = StartFrame = start;
	EndFrame = end;
	FrameDelay = delay;
	FrameSkip = FrameDelay + timeGetTime();
}
