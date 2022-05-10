#pragma once

#include "Type.h"

/// <summary>
/// 렌더러를 초기화한다.
/// </summary>
/// <returns>초기화에 성공했으면 true, 아니면 false</returns>
bool   Renderer_Init(void);

/// <summary>
/// 렌더러를 정리한다.
/// </summary>
void   Renderer_Cleanup(void);


/// <summary>
/// 화면을 바꾼다.
/// </summary>
void   Renderer_Flip(void);

void   Renderer_DrawText(const char* text, int32 numberOfChar);