#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// ���� �ʱ�ȭ �ϴ� �Լ�
	void (*Update)(void);	// ������Ʈ
	void (*Render)(void);	// ����
	void (*Release)(void);	// ������ ����� �ڿ��� ����
	void* Data;
} Scene;

typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE = 1,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene;

// ���� ������ ��ȯ�� �����ΰ�?
// ���� ������ ��ȯ�� �����̸� true, �ƴϸ� false
bool Scene_IsSetNextScene(void);

// ���� ���� �����Ѵ�.
// �Ű����� scene : ��
void Scene_SetNextScene(int32 scene);

// �� ��ȯ
void Scene_Change(void);