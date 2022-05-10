#include "Timer.h"
#include <time.h>

clock_t s_prevTick;
float s_deltaTime;

bool Timer_Init()					// Timer 초기화 : 시작 시점을 clock으로 지정
{
	s_prevTick = clock();
}

void Timer_Update(void)				// 델타 타임을 구하여 컴퓨터에 따른 처리속도의 차이를 해결한다.
{
	clock_t currentTick = clock();	// 현재 시각을 currentTick으로 저장

	float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;
	// currentTick과 s_prevTick의 차이를 CLOCKS_PER_SEC로 나누어 델타 타임(deltaTime)을 초 단위로 구한다.
	// float으로 캐스팅하여 밀리초 단위까지 델타 타임을 구한다.
	// CLOCKS_PER_SEC : clock함수로 구하는 시간의 흐름을 초 단위로 바꾸기 위해 나누어 줘야하는 상수.

	s_deltaTime = deltaTime;		// s_deltaTime을 갱신
	s_prevTick = currentTick;		// s_prevTick을 갱신
}

float Timer_GetDeltaTime(void)		// 델타 타임(s_deltaTime)을 반환하는 함수
{
	return s_deltaTime;
}