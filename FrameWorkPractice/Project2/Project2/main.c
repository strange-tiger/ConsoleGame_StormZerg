#include <stdio.h>
#include <Windows.h>

const char* block[] = {
	"▀  ",
	"▀  ",
	"▀▀▀"
};

int main(void)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	info.dwFontSize = (COORD){ 10, 14 };
	info.FontWeight = 400;
	lstrcpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(h, FALSE, &info);

	// 커서 위치를 옮기는 게 필요함.
	COORD coord = { 10, 10 };
	SetConsoleCursorPosition(h, coord);

	puts("Hello World");

	return 0;
}