#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Renderer.h"
#include "Framework/Input.h"

Scene g_Scene;

static ESceneType s_nextScene;

typedef struct tagTitleSceneData
{
	Text TitleText[128];
} TitleSceneData;

void titleSceneInit(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));
}

void titleSceneUpdate(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	TextCopyWithWhite(data->TitleText, L"테일즈런너");

	// 스페이스 키를 누르면 "메롱"이 출력되게.
	
	if (true == Input_GetKeyPress(VK_SPACE))
	{
		TextCopy(data, L"메롱", TEXT_COLOR_RED | TEXT_COLOR_STRONG | BACK_COLOR_RED);
	}
}

void titleSceneRender(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawText(data->TitleText, sizeof(data->TitleText), 16, 8);
}

void titleSceneRelease(void)
{
	free(g_Scene.Data);			// 동적 할당된 메모리 해제
	g_Scene.Data = NULL;		// 댕글링 포인터 방지
}

bool Scene_IsSetNextScene(void)
{
	if (0 == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// 다음 씬 지정하기
void Scene_SetNextScene(int32 scene)
{
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_TITLE <= scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene == SCENE_NULL);
	// 이전 씬을 정리 -> Release()
	g_Scene.Release();
	// 다음에 로드할 씬에 맞춰서 g_Scene을 구성
	g_Scene = { Init, Update, Render, Release };
	// 다음 씬을 초기화 -> Init()
	g_Scene.Init();
	
	s_nextScene = 0;
}