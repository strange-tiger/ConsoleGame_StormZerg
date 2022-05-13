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
		// 입력 // 처리
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