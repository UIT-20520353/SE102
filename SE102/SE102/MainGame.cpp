#include "Define.h"
#include "Game.h"
#include "Texture.h"
#include "Animation.h"
#include <string>

using namespace std;

#define ID_PLAYER "Player"

#define ID_SPRITE_PLAYER_1 "Sprite_1"
#define ID_SPRITE_PLAYER_2 "Sprite_2"
#define ID_SPRITE_PLAYER_3 "Sprite_3"
#define ID_SPRITE_PLAYER_4 "Sprite_4"
#define ID_SPRITE_PLAYER_5 "Sprite_5"
#define ID_SPRITE_PLAYER_6 "Sprite_6"
#define ID_SPRITE_PLAYER_7 "Sprite_7"
#define ID_SPRITE_PLAYER_8 "Sprite_8"

#define ID_ANIMATION_WALK_RIGHT "Walk_right"
#define ID_ANIMATION_WALK_LEFT	"Walk_left"

void LoadResources() {
	wstring path = ToWSTR("Resources\\spritesheet.png");
	TextureBase::GetInstance()->Add(ID_PLAYER, path.c_str(), D3DCOLOR_XRGB(255, 255, 255));

	Texture* texture = TextureBase::GetInstance()->Get(ID_PLAYER);
	// left top right bottom
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_1, 113, 5, 144, 47, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_2, 110, 56, 143, 97, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_3, 109, 106, 143, 142, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_4, 11, 157, 42, 198, texture);

	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_5, 7, 106, 38, 148, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_6, 58, 106, 91, 147, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_7, 59, 4, 93, 40, texture);
	SpriteBase::GetInstance()->Add(ID_SPRITE_PLAYER_8, 58, 55, 89, 96, texture);


	float frameTime = 100;
	Ref<Animation> animation1 = CreateRef<Animation>(frameTime);
	animation1->Add(ID_SPRITE_PLAYER_1);
	animation1->Add(ID_SPRITE_PLAYER_2);
	animation1->Add(ID_SPRITE_PLAYER_3);
	animation1->Add(ID_SPRITE_PLAYER_4);

	Ref<Animation> animation2 = CreateRef<Animation>(frameTime);
	animation2->Add(ID_SPRITE_PLAYER_5);
	animation2->Add(ID_SPRITE_PLAYER_6);
	animation2->Add(ID_SPRITE_PLAYER_7);
	animation2->Add(ID_SPRITE_PLAYER_8);

	AnimationBase::GetInstance()->Add(ID_ANIMATION_WALK_RIGHT, animation1);
	AnimationBase::GetInstance()->Add(ID_ANIMATION_WALK_LEFT, animation2);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Game::GetInstance()->Create(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, hInstance, nCmdShow);
	LoadResources();
	Game::GetInstance()->Run();

	return EXIT_SUCCESS;
}