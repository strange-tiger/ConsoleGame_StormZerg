#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "App.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include <assert.h>
#include "Text.h"

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
	Input_Update();
}

char str[2][128];
Text text[128];
void update(void)							// ���� ������Ʈ : ����
{
	TextCopyWithWhite(text, L"�츮���� ������ ���ǹ��̴�.");

	//TextCopy(text, L"�츮���� ������ �������̴�.");
	//for (int32 i = 9; text[i].Char.UnicodeChar != L'\0'; i++)
	//{
	//	text[i].Attributes = BACK_COLOR_RED | TEXT_COLOR_WHITE | TEXT_COLOR_STRONG;
	//}

	int32 minVal = -45;
	int32 maxVal = 32;
	int32 randInt = Random_GetNumberFromRange(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d ������ ���� : %d\n", minVal, maxVal, randInt);

	float fminVal = -12.342f;
	float fmaxVal = 25.982f;
	float frand = Random_GetFNumberFromRange(fminVal, fmaxVal);
	assert(fminVal <= frand && frand <= fmaxVal);

	sprintf_s(str[1], sizeof(str[1]), "%f ~ %f ������ �Ǽ� : %f\n", fminVal, fmaxVal, frand);

	//sprintf_s(str, sizeof(str), "���� �Է� ����");
	//Sleep(100);
	/*
	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���� ����");
	}
	*/
}

void render(void)							// ���� ���
{
	Renderer_DrawText(text, TextLen(text), 10 , 10);
	// Renderer_DrawText(str[1], strlen(str[1]));
	
	// Renderer_DrawText("�ξƸ���", sizeof("�ξƸ���"));

	// ���� ���۸�
	// 1. ȭ�� ��ȯ�ϰ�
	Renderer_Flip();

	// 2. �� ������ ����(���� ȭ��)�� �����ش�.
	Renderer_Clear();

	// ��� : tearing �ذ�, �� �̻� �ؽ�Ʈ�� ��¦���� �ʴ´�.
}

int32 App_Run(void)							// ���� ����
{
	Timer_Init();							// Timer �ʱ�ȭ
	Random_Init();

	// ���� ���� : �Է�ó�� -> ���� ������Ʈ -> ���� ���
	while (1)
	{
		Timer_Update();						// Timer ������Ʈ : ��Ÿ Ÿ�� ���

		processInput();						// �Է�ó��
		update();							// ���� ������Ʈ	// ������Ʈ : ���� ����, �ֽ�ȭ, ����
		render();							// ���� ���
	}
}