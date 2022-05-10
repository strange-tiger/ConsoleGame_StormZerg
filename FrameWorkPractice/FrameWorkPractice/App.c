#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Renderer.h"
#include "Timer.h"

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

}

bool canShow;								// 반짝이는 효과를 위한 불리언 변수
float elapsedTime;							// 변화의 주기

void update(void)							// 게임 업데이트 : 갱신
{
	// Sleep(10);

	elapsedTime += Timer_GetDeltaTime();	// 델타 타임만큼 변화
	if (elapsedTime >= 0.5f)				// 0.5초 마다
	{
		elapsedTime = 0.0f;					// 주기 초기화
		canShow = !canShow;					// 불리언 변수를 반대로 대입
	}
}

void render(void)							// 게임 출력
{
	if (canShow)							// 반짝이는 효과
	{
		Renderer_DrawText("메타플밍1기", sizeof("메타플밍1기"));
	}
	
	// Renderer_DrawText("로아망겜", sizeof("로아망겜"));

	// 더블 버퍼링
	// 1. 화면 전환하고
	Renderer_Flip();

	// 2. 백 버퍼의 내용(이전 화면)을 지워준다.
	Renderer_Clear();

	// 결과 : tearing 해결, 더 이상 텍스트가 반짝이지 않는다.
}

int App_Run(void)							// 게임 실행
{
	Timer_Init(60);							// Timer 초기화 : fps 60

	// 게임 루프 : 입력처리 -> 게임 업데이트 -> 게임 출력
	while (1)
	{
		Timer_Update();						// Timer 업데이트 : 델타 타임 계산

		processInput();						// 입력처리
		update();							// 게임 업데이트	// 업데이트 : 변경 적용, 최신화, 갱신
		render();							// 게임 출력
	}
}