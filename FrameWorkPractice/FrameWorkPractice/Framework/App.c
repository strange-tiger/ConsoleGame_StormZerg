#include "App.h"
#include "Common.h"
#include <assert.h>
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"
#include "Scene.h"

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

void update(void)							// ���� ������Ʈ : ����
{
	g_Scene.Update();

	// TextCopyWithWhite(text, L"�츮���� ������ ���ǹ��̴�.");
}

void render(void)							// ���� ���
{
	g_Scene.Render();
	
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