#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>

#define GetKey(vkey) 0x8000 & GetAsyncKeyState(vkey)
#define PLAYER_MOVE_SPEED 1
#define BULLET_MOVE_SPEED 1
#define BOUNDARY_X 32
#define BOUNDARY_Y 16
#define PLAYER_INIT_POS_X 16
#define PLAYER_INIT_POS_Y 8

#define BULLET_DURATION 3.0f

int main(void)
{
	struct Bullet
	{
		COORD pos;
		float life;
		bool isFired; // isShot, isShotten, isShooting, exist, shootOut, fired, isFired, flying
	} bullet;
	bullet.pos.X = 0;
	bullet.pos.Y = 0;
	bullet.life = 0.0f;
	bullet.isFired = 0;

	struct Player
	{
		COORD pos;
	} player;
	player.pos.X = PLAYER_INIT_POS_X;
	player.pos.Y = PLAYER_INIT_POS_Y;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	clock_t prevTick = clock();
	
	while (1)
	{
		// ��Ÿ Ÿ��
		clock_t currentTick = clock();
		float deltaTime = (float)(currentTick - prevTick) / CLOCKS_PER_SEC;
		prevTick = currentTick;

		// �Է� // ó��
		// ȭ��ǥ Ű�� ������ MOVE_SPEED��ŭ �̵��ϵ���
		if (GetKey(VK_LEFT))
		{
			if (player.pos.X > 0)
			{
				player.pos.X -= PLAYER_MOVE_SPEED;
			}
		}
		if (GetKey(VK_RIGHT))
		{
			if (player.pos.X < BOUNDARY_X)
			{
				player.pos.X += PLAYER_MOVE_SPEED;
			}
		}
		if (GetKey(VK_UP))
		{
			if (player.pos.Y > 0)
			{
				player.pos.Y -= PLAYER_MOVE_SPEED;
			}
		}
		if (GetKey(VK_DOWN))
		{
			if (player.pos.Y < BOUNDARY_Y)
			{
				player.pos.Y += PLAYER_MOVE_SPEED;
			}
		}

		if (GetKey(VK_SPACE))
		{
			bullet.pos.X = player.pos.X + 1;
			bullet.pos.Y = player.pos.Y;
			bullet.life = BULLET_DURATION;

			bullet.isFired = true;
		}

		// ó��
		if (bullet.life > 0.0f)
		{
			bullet.life -= deltaTime;
			bullet.pos.X += BULLET_MOVE_SPEED;
		}
		else
		{
			bullet.isFired = false;
			bullet.life = 0.0f;
		}

		// ���
		system("cls");
		SetConsoleCursorPosition(consoleHandle, player.pos);
		printf("P");
		if (bullet.isFired)
		{
			SetConsoleCursorPosition(consoleHandle, bullet.pos);
			printf("O");
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