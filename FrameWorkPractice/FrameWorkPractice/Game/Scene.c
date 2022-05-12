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

	TextCopyWithWhite(data->TitleText, L"�������");

	// �����̽� Ű�� ������ "�޷�"�� ��µǰ�.
	
	if (true == Input_GetKeyPress(VK_SPACE))
	{
		TextCopy(data, L"�޷�", TEXT_COLOR_RED | TEXT_COLOR_STRONG | BACK_COLOR_RED);
	}
}

void titleSceneRender(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawText(data->TitleText, sizeof(data->TitleText), 16, 8);
}

void titleSceneRelease(void)
{
	free(g_Scene.Data);			// ���� �Ҵ�� �޸� ����
	g_Scene.Data = NULL;		// ��۸� ������ ����
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

// ���� �� �����ϱ�
void Scene_SetNextScene(int32 scene)
{
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_TITLE <= scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene == SCENE_NULL);
	// ���� ���� ���� -> Release()
	g_Scene.Release();
	// ������ �ε��� ���� ���缭 g_Scene�� ����
	g_Scene = { Init, Update, Render, Release };
	// ���� ���� �ʱ�ȭ -> Init()
	g_Scene.Init();
	
	s_nextScene = 0;
}