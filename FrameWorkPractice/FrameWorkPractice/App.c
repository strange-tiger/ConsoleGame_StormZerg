#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Renderer.h"
#include "Timer.h"

bool App_Init(void)							// �ʱ�ȭ
{
	if (false == Renderer_Init())			// ���� ó��
	{
		return false;
	}
	return true;
}

void processInput(void)						// �Է� ó��
{

}

bool canShow;								// ��¦�̴� ȿ���� ���� �Ҹ��� ����
float elapsedTime;							// ��ȭ�� �ֱ�

void update(void)							// ���� ������Ʈ : ����
{
	// Sleep(10);

	elapsedTime += Timer_GetDeltaTime();	// ��Ÿ Ÿ�Ӹ�ŭ ��ȭ
	if (elapsedTime >= 0.5f)				// 0.5�� ����
	{
		elapsedTime = 0.0f;					// �ֱ� �ʱ�ȭ
		canShow = !canShow;					// �Ҹ��� ������ �ݴ�� ����
	}
}

void render(void)							// ���� ���
{
	if (canShow)							// ��¦�̴� ȿ��
	{
		Renderer_DrawText("��Ÿ�ù�1��", sizeof("��Ÿ�ù�1��"));
	}
	
	// Renderer_DrawText("�ξƸ���", sizeof("�ξƸ���"));

	// ���� ���۸�
	// 1. ȭ�� ��ȯ�ϰ�
	Renderer_Flip();

	// 2. �� ������ ����(���� ȭ��)�� �����ش�.
	Renderer_Clear();

	// ��� : tearing �ذ�, �� �̻� �ؽ�Ʈ�� ��¦���� �ʴ´�.
}

int App_Run(void)							// ���� ����
{
	Timer_Init(60);							// Timer �ʱ�ȭ : fps 60

	// ���� ���� : �Է�ó�� -> ���� ������Ʈ -> ���� ���
	while (1)
	{
		Timer_Update();						// Timer ������Ʈ : ��Ÿ Ÿ�� ���

		processInput();						// �Է�ó��
		update();							// ���� ������Ʈ	// ������Ʈ : ���� ����, �ֽ�ȭ, ����
		render();							// ���� ���
	}
}