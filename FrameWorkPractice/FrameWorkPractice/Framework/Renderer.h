#pragma once

#include <stdbool.h>
#include "Common.h"
#include "Text.h"

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);
void Renderer_Clear(void);
void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);
	// printf를 더 이상 못 쓰기에, 콘솔에 출력할 함수를 만듦
	// 문자색 등의 속성이 들어간 문자열을 출력, 출력 위치 지정 가능