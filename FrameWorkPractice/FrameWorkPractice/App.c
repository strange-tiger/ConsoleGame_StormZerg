#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "App.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include <assert.h>

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

char str[2][128];
void update(void)							// 게임 업데이트 : 갱신
{
	int32 minVal = -45;
	int32 maxVal = 32;
	int32 randInt = Random_GetNumberFromRange(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d 사이의 정수 : %d\n", minVal, maxVal, randInt);

	float fminVal = -12.342f;
	float fmaxVal = 25.982f;
	float frand = Random_GetFNumberFromRange(fminVal, fmaxVal);
	assert(fminVal <= frand && frand <= fmaxVal);

	sprintf_s(str[1], sizeof(str[1]), "%f ~ %f 사이의 실수 : %f\n", fminVal, fmaxVal, frand);

	//sprintf_s(str, sizeof(str), "현재 입력 없음");
	//Sleep(100);

	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시 눌림");
	}
}

void render(void)							// 게임 출력
{
	Renderer_DrawText(str[0], strlen(str[0]));
	Renderer_DrawText(str[1], strlen(str[1]));
	
	// Renderer_DrawText("로아망겜", sizeof("로아망겜"));

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