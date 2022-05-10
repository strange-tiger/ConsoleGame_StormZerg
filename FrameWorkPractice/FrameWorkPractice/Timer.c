#include "Timer.h"
#include <time.h>

clock_t s_prevTick;
float s_deltaTime;

bool Timer_Init()					// Timer �ʱ�ȭ : ���� ������ clock���� ����
{
	s_prevTick = clock();
}

void Timer_Update(void)				// ��Ÿ Ÿ���� ���Ͽ� ��ǻ�Ϳ� ���� ó���ӵ��� ���̸� �ذ��Ѵ�.
{
	clock_t currentTick = clock();	// ���� �ð��� currentTick���� ����

	float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;
	// currentTick�� s_prevTick�� ���̸� CLOCKS_PER_SEC�� ������ ��Ÿ Ÿ��(deltaTime)�� �� ������ ���Ѵ�.
	// float���� ĳ�����Ͽ� �и��� �������� ��Ÿ Ÿ���� ���Ѵ�.
	// CLOCKS_PER_SEC : clock�Լ��� ���ϴ� �ð��� �帧�� �� ������ �ٲٱ� ���� ������ ����ϴ� ���.

	s_deltaTime = deltaTime;		// s_deltaTime�� ����
	s_prevTick = currentTick;		// s_prevTick�� ����
}

float Timer_GetDeltaTime(void)		// ��Ÿ Ÿ��(s_deltaTime)�� ��ȯ�ϴ� �Լ�
{
	return s_deltaTime;
}