#pragma once

/// <summary>
/// Ÿ�̸Ӹ� �ʱ�ȭ�Ѵ�.
/// </summary>
/// <param name="fps">������ FPS</param>
void   Timer_Init(int32 fps);

/// <summary>
/// Ÿ�̸Ӹ� ������Ʈ�Ѵ�.
/// </summary>
/// <return>������Ʈ�� �����ߴٸ� true, �ƴϸ� false</return>
bool   Timer_Update(void);

/// <summary>
/// ��ŸŸ���� ���Ѵ�.
/// </summary>
/// <return>DeltaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð�</return>
float   Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime()