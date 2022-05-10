#include "Renderer.h"
#include <Windows.h>

// s_ : static ���� // ���� �����ͷ� �Ҵ�Ǵ� ������� �ǹ� // ������ ������ ������
HANDLE s_screens[2];			// ���� ���۸��� �� �޸�	// typedef void* HANDLE : pointer to void(anything)�� HANDLE�� ������
int s_backBufferIndex;

bool Renderer_Init(void)									// �ʱ�ȭ �Լ�
{
	// s_screens[s_backBufferIndex];						// �� ���� : ����
															// �ܼ� ���α׷��� ���� ȭ�� ����� �Լ�
	s_screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	// CreateConsoleScreenBuffer() : ��ũ���� ����� Window �ý��� �Լ�. �Ű� ������ �ý��� ���α׷����� �غ��� ���ص� ���̱⿡, ������ ����
	if (s_screens[0] == INVALID_HANDLE_VALUE)				// ���� ó��
	{
		return false;
	}

	s_screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[1] == INVALID_HANDLE_VALUE)				// ���� ó��
	{
		CloseHandle(s_screens[0]);
		// s_screens[0]�� ���������� ����������Ƿ� ������ ����� �Ѵ�.

		return false;
	}

	return true;
}

void Renderer_Cleanup(void)									// �ڿ� ����
{
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void Renderer_Flip(void)									// ���� ���۸��� ���� ��ũ�� ��ȯ �Լ�
{
	// 1. ���� �ܼ��� ��ũ�� ���۸� �� ���۷� ����
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);
	// SetConsoleActiveScreenBuffer() : � ��ũ���� ����� �� �����ϴ� �Լ�

// 2. �� ���� ��ȯ
	s_backBufferIndex = !s_backBufferIndex;
}

void Renderer_Clear(void)									// ��ũ�� ���� �Լ� : clsó�� �� ������ ������ ����� �Լ�  
{
	HANDLE consoleHandle = s_screens[s_backBufferIndex];

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer_DrawText(const char* text, int numberOfText)	// �� ������ ��ũ������ printf ���� �ܼ� ��� �Լ��� �� �̻� �� �� ���⿡, ������ �Լ��� �����Ͽ� ���
{
	HANDLE backBuffer = s_screens[s_backBufferIndex];

	WriteConsoleA(backBuffer, text, numberOfText, NULL, NULL);
		// WriteConsole() : ���� Ŀ�� ������ ���ڿ��� ����ϴ� �Լ�
}