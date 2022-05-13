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
		// �Է� // ó��
		// ȭ��ǥ Ű�� ������ SPACE_MOVING��ŭ �̵��ϵ���
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
		
		// ���
		system("cls");
		SetConsoleCursorPosition(consoleHandle, playerPos);
		printf("P");

		// ��Ÿ Ÿ��
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

/*
	���α׷� ����
	1. �÷��̾�� ȭ��ǥ�� �����δ�.
	2. �÷��̾�� P�� ǥ���Ѵ�.
	3. �÷��̾ �̵��� �� �ִ� ������ �������̴�.
	4. �����̽� Ű�� ������ �Ѿ��� �߻�ȴ�.�Ѿ��� �÷��̾� �ٷ� �տ� �����ȴ�.
	5. �Ѿ��� O�� ǥ���Ѵ�.
	6. �Ѿ��� 3�ʰ� ������ �� �����̴� 3�ʰ� ������ �������.
	7. ����� ���� �Լ��� �����ȴ�.
	8. ��ũ�δ� ��� �����ϴ�.
	9. ��ŸŸ�� ������ ����Ǿ� �־�� �Ѵ�.
	10. ��� �ĺ��ڴ� �������� ���ƾ� �Ѵ�.
	11. �����ִ� ��ü�� ��� ����ü�� ǥ���Ѵ�.
	12. ��� ��ü�� ����ϴ� ���� ������ ��ġ�ؾ� �Ѵ�.
	13. ���� ������ ������ ���� �Է� - ó�� - ��ºΰ� Ȯ���ϰ� ������ �־�� �Ѵ�.
*/