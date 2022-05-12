#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// 씬을 초기화 하는 함수
	void (*Update)(void);	// 업데이트
	void (*Render)(void);	// 렌더
	void (*Release)(void);	// 씬에서 사용한 자원을 정리
	void* Data;
} Scene;

typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE = 1,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene;

// 다음 씬으로 전환될 예정인가?
// 다음 씬으로 전환될 예정이면 true, 아니면 false
bool Scene_IsSetNextScene(void);

// 다음 씬을 지정한다.
// 매개변수 scene : 씬
void Scene_SetNextScene(int32 scene);

// 씬 전환
void Scene_Change(void);