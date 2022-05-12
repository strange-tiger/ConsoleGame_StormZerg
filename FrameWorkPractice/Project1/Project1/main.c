#include <stdio.h>
#include <Windows.h>

int main(void)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// FOREGROUND_RGB
	// 
	// 1 2 4 8
	// BACKGROUND_RGB
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	puts("Hello World!");

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	char ch;
	WORD Attributes;

	return 0;
}