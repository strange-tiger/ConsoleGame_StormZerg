#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

#define SPACE_MOVING 1
#define BOUNDARY_X 32
#define BOUNDARY_Y 16
#define BULLET_DURATION 3.0f

struct Bullet
{
	COORD pos;
	float life;
	bool shot;
} bullet;

int main(void)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	clock_t prevTick = clock();
	COORD playerPos = { 16, 8 };
	bullet.pos.X = 0;
	bullet.pos.Y = 0;
	bullet.life = 0.0f;
	bullet.shot = 0;

	SetConsoleCursorPosition(consoleHandle, playerPos);
	printf("P");
	while (1)
	{
		// 입력
		// 화살표 키가 눌리면 SPACE_MOVING만큼 이동하도록
		if (0x8000 & GetAsyncKeyState(VK_LEFT) && playerPos.X > 0)
		{
			playerPos.X -= SPACE_MOVING;
		}
		if (0x8000 & GetAsyncKeyState(VK_RIGHT) && playerPos.X < BOUNDARY_X)
		{
			playerPos.X += SPACE_MOVING;
		}
		if (0x8000 & GetAsyncKeyState(VK_UP) && playerPos.Y > 0)
		{
			playerPos.Y -= SPACE_MOVING;
		}
		if (0x8000 & GetAsyncKeyState(VK_DOWN) && playerPos.Y < BOUNDARY_Y)
		{
			playerPos.Y += SPACE_MOVING;
		}

		if (0x8000 & GetAsyncKeyState(VK_SPACE))
		{
			bullet.pos.X = playerPos.X + 1;
			bullet.pos.Y = playerPos.Y;
			bullet.life = BULLET_DURATION;

			bullet.shot = true;
		}
		
		// 출력
		system("cls");
		SetConsoleCursorPosition(consoleHandle, playerPos);
		printf("P");

		// 델타 타임
		clock_t currentTick = clock();
		float deltaTime = (float)(currentTick - prevTick) / CLOCKS_PER_SEC;
		prevTick = currentTick;

		if (bullet.shot && bullet.life > 0.0f)
		{
			bullet.life -= deltaTime;

			bullet.pos.X += SPACE_MOVING;

			SetConsoleCursorPosition(consoleHandle, bullet.pos);
			printf("O");
		}
		else if (bullet.life < 0.0f)
		{
			bullet.shot = false;
			bullet.life = 0.0f;

			system("cls");
		}

		Sleep(10);
	}
	return 0;
}