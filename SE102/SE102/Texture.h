#pragma once
#include "Define.h"
#include <d3dx9.h>

using namespace std;

typedef IDirect3DTexture9 Texture;

class TextureBase
{
public:
	TextureBase() = default;
	~TextureBase();
	static Ref<TextureBase> GetInstance();

	Texture* Add(const string& name, LPCWSTR path, D3DCOLOR trans);
	Texture* Get(const string& name);

private:
	static Ref<TextureBase> s_Instance;
	HashTable<string, Texture*> m_Textures;
};

