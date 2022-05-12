#include "Text.h"

void TextCopy(Text* dest, const WCHAR* src, WORD attributes)
{
	while (*src)
	{
		dest->Char.UnicodeChar = *src;		// src 내용을 dest에 복사
		dest->Attributes = attributes;

		++dest;
		++src;
	}
}

int32 TextLen(const Text* text)
{
	int32 count = 0;

	while (text -> Char.UnicodeChar)
	{
		count++;
		text++;
	}

	return count;
}