#pragma once

#include "Texture.h"
#include "IRender2D.h"

using namespace std;

class Sprite : public IRender2D
{
public:
	Sprite(float left, float top, float right, float bottom, Texture* texture);

	RECT* GetRect();
	Texture* GetTexture();

	void Render(float X, float Y, TimeStep elapsed = 0);

private:
	RECT     m_Rect;
	Texture* m_Texture;
};

class SpriteBase
{
public:
	SpriteBase() = default;
	static Ref<SpriteBase> GetInstance();

	Ref<Sprite> Add(const string& name, float left, float top, float right, float bottom, Texture* texture);
	Ref<Sprite> Get(const string& name);

private:
	static Ref<SpriteBase> s_Instance;
	HashTable<string, Ref<Sprite>> m_Sprites;
};

