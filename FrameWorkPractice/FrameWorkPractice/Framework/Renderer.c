#include "Renderer.h"

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

void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y)
// �� ������ ��ũ������ printf ���� �ܼ� ��� �Լ��� �� �̻� �� �� ���⿡, ������ �Լ��� �����Ͽ� ���
// ���ڻ� ���� �Ӽ��� �� ���ڿ��� ���, ��� ��ġ ���� ����
{
	// 1. �� ���ۿ� ���� �ڵ��� �����´�.
	HANDLE backBuffer = s_screens[s_backBufferIndex];

	// 2. Ŀ�� ��ġ�� �Ű��ش�.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. �� ���ۿ� �ؽ�Ʈ�� ����Ѵ�.
	for (int32 i = 0; i < numberOfChar; ++i)	// �� ���ڸ��� ���� �� ������ �ٸ��⿡, �ϳ��� ���
	{
		SetConsoleTextAttribute(backBuffer, text[i].Attributes);
		WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
	}
	SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
	// WriteConsole() : ���� Ŀ�� ������ ���ڿ��� ����ϴ� �Լ�
	// WriteConsole() -> w����, �����ڵ� WriteConsoleA() -> A����, �ƽ�Ű�ڵ� 
	// SetConsoleTextAttribute() : �ؽ�Ʈ�� ���� �����ϴ� �Լ�
}