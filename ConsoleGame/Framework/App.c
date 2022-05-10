#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	return true;
}

void processInput()
{

}

float elapsedTime;
bool canShow = false;
void update()
{
	// 0.5초마다 깜빡이는 텍스트를 만드시오.
	elapsedTime += DELTA_TIME;

	if (elapsedTime >= 0.5)
	{
		elapsedTime = 0.0f;
		canShow = !canShow;
	}

	if (canShow)
	{
		Renderer_DrawText("이 텍스트는 깜빡입니다.", sizeof("이 텍스트는 깜빡입니다."));
	}
}

void render()
{
	Renderer_Flip();
}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		// 시간이 업데이트 됐을 때에만 게임 루프 실행
		if (Timer_Update())
		{
			processInput();      // 입력 처리
			update();         // 게임 업데이트
			render();         // 게임 출력
		}
	}

	return 0;
}