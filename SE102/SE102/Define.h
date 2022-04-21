#pragma once
#include <memory>
#include "Debug.h"
#include <unordered_map>

using namespace std;

template<typename T> using Scope = unique_ptr<T>;
template<typename T> using Ref = shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
	return make_shared<T>(forward<Args>(args)...);
}

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
	return make_unique<T>(forward<Args>(args)...);
}

template<typename K, typename V> using HashTable = unordered_map<K, V>;

typedef float TimeStep;


constexpr int WIDTH_TILES = 16;
constexpr int HEIGHT_TILES = 14;

constexpr int     SCREEN_WIDTH = WIDTH_TILES * 16;
constexpr int     SCREEN_HEIGHT = HEIGHT_TILES * 16;
constexpr wchar_t SCREEN_TITLE[] = L"Metal Slug 3";

constexpr float TIME_EPSILON = 0.001F;

