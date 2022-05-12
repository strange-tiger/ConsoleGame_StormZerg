#include "App.h"
#include "Common.h"
#include <assert.h>
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"
#include "Scene.h"

bool App_Init(void)							// 초기화
{
	if (false == Renderer_Init())			// 예외 처리
	{
		return false;
	}
	return true;
}

void processInput(void)						// 입력 처리
{
	Input_Update();
}

void update(void)							// 게임 업데이트 : 갱신
{
	g_Scene.Update();

	// TextCopyWithWhite(text, L"우리반의 존잘은 성권문이다.");
}

void render(void)							// 게임 출력
{
	g_Scene.Render();
	
	// 더블 버퍼링
	// 1. 화면 전환하고
	Renderer_Flip();

	// 2. 백 버퍼의 내용(이전 화면)을 지워준다.
	Renderer_Clear();

	// 결과 : tearing 해결, 더 이상 텍스트가 반짝이지 않는다.
}

int32 App_Run(void)							// 게임 실행
{
	Timer_Init();							// Timer 초기화
	Random_Init();

	// 게임 루프 : 입력처리 -> 게임 업데이트 -> 게임 출력
	while (1)
	{
		Timer_Update();						// Timer 업데이트 : 델타 타임 계산

		processInput();						// 입력처리
		update();							// 게임 업데이트	// 업데이트 : 변경 적용, 최신화, 갱신
		render();							// 게임 출력
	}
}