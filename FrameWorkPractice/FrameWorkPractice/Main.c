#include "App.h"
#include <stdio.h>
// #include "Random.h"

int main(void)
{
	// 1. ���α׷� �ʱ�ȭ
	if (false == App_Init())	// ���� ó��
	{
		puts("�� �ʱ�ȭ�� �����߽��ϴ�.");

		return 1;
	}
	
	// 2. ���α׷� ����
	return App_Run();

	/*srand(time(NULL));
	int32 randomNum = Random_GetNumberFromRange(-327, 327);
	printf("%d", randomNum);*/
	/*srand(time(NULL));
	float randomNum = Random_GetFNumberFromRange(-350.000f, 350.000f);
	printf("%f", randomNum);*/
}