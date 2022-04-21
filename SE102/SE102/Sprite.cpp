#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite(float left, float top, float right, float bottom, Texture* texture)
{
	m_Rect.left = static_cast<LONG>(left);
	m_Rect.top = static_cast<LONG>(top);
	m_Rect.right = static_cast<LONG>(right);
	m_Rect.bottom = static_cast<LONG>(bottom);
	m_Texture = texture;
}

RECT* Sprite::GetRect()
{
	return &m_Rect;
}

Texture* Sprite::GetTexture()
{
	return m_Texture;
}

void Sprite::Render(float X, float Y, TimeStep elapsed)
{
	Renderer::DrawSprite(X, Y, this);
}

Ref<SpriteBase> SpriteBase::s_Instance = CreateRef<SpriteBase>();
Ref<SpriteBase> SpriteBase::GetInstance() { return s_Instance; }

Ref<Sprite> SpriteBase::Add(const string& name, float left, float top, float right, float bottom, Texture* texture)
{
	m_Sprites[name] = CreateRef<Sprite>(left, top, right, bottom, texture);
	return m_Sprites[name];
}

Ref<Sprite> SpriteBase::Get(const string& name)
{
	return m_Sprites[name];
}