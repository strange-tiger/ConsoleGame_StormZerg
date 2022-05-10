#include "App.h"
#include "Common.h"

bool App_Init()
{
    return true;
}

void processInput()
{

}

void update()
{

}

void render()
{
    system("cls");
    puts("Hello Game");
}

int32 App_Run()
{
    // Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
    while (true)
    {
        processInput();      // 입력 처리
        update();         // 게임 업데이트
        render();         // 게임 출력
    }

    return 0;
}