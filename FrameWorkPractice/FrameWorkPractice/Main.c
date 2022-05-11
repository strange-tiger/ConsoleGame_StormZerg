#include "App.h"
#include <stdio.h>
// #include "Random.h"

int main(void)
{
	// 1. 프로그램 초기화
	if (false == App_Init())	// 예외 처리
	{
		puts("앱 초기화에 실패했습니다.");

		return 1;
	}
	
	// 2. 프로그램 실행
	return App_Run();

	/*srand(time(NULL));
	int32 randomNum = Random_GetNumberFromRange(-327, 327);
	printf("%d", randomNum);*/
	/*srand(time(NULL));
	float randomNum = Random_GetFNumberFromRange(-350.000f, 350.000f);
	printf("%f", randomNum);*/
}