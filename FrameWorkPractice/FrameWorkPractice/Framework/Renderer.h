#pragma once

#include <stdbool.h>
#include "Common.h"
#include "Text.h"

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);
void Renderer_Clear(void);
void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);
	// printf�� �� �̻� �� ���⿡, �ֿܼ� ����� �Լ��� ����
	// ���ڻ� ���� �Ӽ��� �� ���ڿ��� ���, ��� ��ġ ���� ����