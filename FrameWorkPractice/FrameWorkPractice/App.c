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
		Renderer_DrawText("��Ÿ�ù�1��", sizeof("��Ÿ�ù�1��"));
	}
	
	// Renderer_DrawText("�ξƸ���", sizeof("�ξƸ���"));

	// ���� ���۸�
	// 1. ȭ�� ��ȯ�ϰ�
	Renderer_Flip();

	// 2. �� ������ ����(���� ȭ��)�� �����ش�.
	Renderer_Clear();
}

int App_Run(void)
{
	Timer_Init(60);

	// ���� ���� : �Է�ó�� -> ���� ������Ʈ -> ���� ���
	while (1)
	{
		Timer_Update();

		processInput();	// �Է�ó��
		update();		// ���� ������Ʈ	// ������Ʈ : ���� ����, �ֽ�ȭ, ����
		render();		// ���� ���
	}
}