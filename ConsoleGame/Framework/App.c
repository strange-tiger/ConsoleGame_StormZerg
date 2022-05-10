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

    // Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
    while (true)
    {
        processInput();      // �Է� ó��
        update();         // ���� ������Ʈ
        render();         // ���� ���
    }

    return 0;
}