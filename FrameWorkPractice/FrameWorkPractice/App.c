#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Renderer.h"
#include "Timer.h"

bool App_Init(void)
{
	if (false == Renderer_Init())
	{
		return false;
	}
	return true;
}

void processInput(void)
{

}

char str[128];
bool canShow;
float elapsedTime;

void update(void)
{
	Sleep(10);

	elapsedTime += Timer_GetDeltaTime();
	if (elapsedTime >= 0.5f)
	{
		elapsedTime = 0.0f;
		canShow = !canShow;
	}
}

void render(void)
{
	if (canShow)
	{
		Renderer_DrawText("메타플밍1기", sizeof("메타플밍1기"));
	}
	
	// Renderer_DrawText("로아망겜", sizeof("로아망겜"));

	// 더블 버퍼링
	// 1. 화면 전환하고
	Renderer_Flip();

	// 2. 백 버퍼의 내용(이전 화면)을 지워준다.
	Renderer_Clear();
}

int App_Run(void)
{
	Timer_Init(60);

	// 게임 루프 : 입력처리 -> 게임 업데이트 -> 게임 출력
	while (1)
	{
		Timer_Update();

		processInput();	// 입력처리
		update();		// 게임 업데이트	// 업데이트 : 변경 적용, 최신화, 갱신
		render();		// 게임 출력
	}
}