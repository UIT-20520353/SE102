#pragma once
#include <vector>
#include "Define.h"
#include "Sprite.h"

using namespace std;


class Frame
{
public:
	Frame(Ref<Sprite> sprite, TimeStep time);

	TimeStep GetTime();
	Ref<Sprite> GetSprite();

private:
	TimeStep    m_Time;
	Ref<Sprite> m_Sprite;
};

class Animation : public IRender2D
{
public:
	Animation(TimeStep defaultTime);

	void Add(const string& name, TimeStep time = 0);
	void Render(float X, float Y, TimeStep elapsed);

private:
	TimeStep m_DefaultTime;
	size_t   m_CurrentFrame;
	TimeStep m_TimeStep;

	TimeStep m_LastFrameTime;
	vector<Ref<Frame>> m_Frames;
};

class AnimationBase
{
public:
	static Ref<AnimationBase> GetInstance();

	Ref<Animation> Add(const string& name, Ref<Animation> animation);
	Ref<Animation> Get(const string& name);

private:
	static Ref<AnimationBase> s_Instance;
	HashTable<string, Ref<Animation>> m_Animations;
};


