#pragma once

#include <stdbool.h>

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);
void Renderer_Clear(void);
void Renderer_DrawText(const char* text, int numberOfText);
	// printf를 더 이상 못 쓰기에, 콘솔에 출력할 함수를 만듦