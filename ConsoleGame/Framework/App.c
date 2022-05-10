#include "App.h"
#include "Common.h"
#include "Renderer.h"

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

void update()
{
    Renderer_DrawText("Hello Game", sizeof("Hello Game"));
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

    // Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
    while (true)
    {
        processInput();      // 입력 처리
        update();         // 게임 업데이트
        render();         // 게임 출력
    }

    return 0;
}