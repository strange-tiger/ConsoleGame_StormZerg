#include "Input.h"
#include <stdlib.h>

#define IS_KEY_PRESSED(vkey) (0x8000 & GetAsyncKeyState(vkey))

// 이전 프레임의 키 상태
bool s_isKeyPressedOnPrevFrame[256];

// 현재 프레임의 키 상태
bool s_isKeyPressedOnCurrentFrame[256];

//bool Input_Init(void)
//{
//	
//}

void Input_Update(void)
{
	// 이전 프레임의 키 내용 저장 및 현재 프레임의 키 상태를 가져와야 함.
	memcpy(s_isKeyPressedOnPrevFrame, s_isKeyPressedOnCurrentFrame, sizeof(s_isKeyPressedOnCurrentFrame));

	for (int32 vkey = 0; vkey < 256; ++vkey)
	{
		if (IS_KEY_PRESSED(vkey))
		{
			s_isKeyPressedOnCurrentFrame[vkey] = true;
		}
		else
		{
			s_isKeyPressedOnCurrentFrame[vkey] = false;
		}
	}
}

bool Input_GetKeyPress(uint8 vkey)
{
	if (false == s_isKeyPressedOnPrevFrame[vkey] && true == s_isKeyPressedOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKeyNonPress(uint8 vkey)
{
	if (true == s_isKeyPressedOnPrevFrame[vkey] && false == s_isKeyPressedOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKey(uint8 vkey)
{
	if (true == s_isKeyPressedOnPrevFrame[vkey] && true == s_isKeyPressedOnCurrentFrame[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}