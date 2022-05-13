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
		// 델타 타임
		clock_t currentTick = clock();
		float deltaTime = (float)(currentTick - prevTick) / CLOCKS_PER_SEC;
		prevTick = currentTick;

		// 입력 // 처리
		// 화살표 키가 눌리면 MOVE_SPEED만큼 이동하도록
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

		// 처리
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

		// 출력
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
	프로그램 조건
	1. 플레이어는 화살표로 움직인다.
	2. 플레이어는 P로 표현한다.
	3. 플레이어가 이동할 수 있는 범위는 제한적이다.
	4. 스페이스 키를 누르면 총알이 발사된다.총알은 플레이어 바로 앞에 생성된다.
	5. 총알은 O로 표현한다.
	6. 총알은 3초간 앞으로 쭉 움직이다 3초가 지나면 사라진다.
	7. 사용자 정의 함수는 금지된다.
	8. 매크로는 사용 가능하다.
	9. 델타타임 개념이 적용되어 있어야 한다.
	10. 모든 식별자는 가독성이 좋아야 한다.
	11. 관련있는 객체는 묶어서 구조체로 표현한다.
	12. 모든 객체는 사용하는 곳과 가까이 위치해야 한다.
	13. 게임 루프의 순서에 맞춰 입력 - 처리 - 출력부가 확실하게 나눠져 있어야 한다.
*/