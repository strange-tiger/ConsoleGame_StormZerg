#include "Random.h"
#include <stdlib.h>
#include <time.h>

#define RANDOM_NUMBER_RANGE_SIZE (maxExclusive - minInclusive)

void Random_Init(void)
{
	srand(time(NULL));
}


int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	int32 randomNumberFromRange = 0;

	randomNumberFromRange = (rand() * (rand() + rand())) % RANDOM_NUMBER_RANGE_SIZE + minInclusive;
	
	// Jaesung's idea : rand to esch bit
	/*for (int i = 0; i < 32; i++)
	{
		randomNumberFromRange += rand() % 2;
		randomNumberFromRange = randomNumberFromRange << 1;
	}*/
	
	return randomNumberFromRange;
}

//int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
//{
//	
//
//	
//
//	
//	
//	
//	
//	
//	
//
//	
//}

float Random_GetFNumberFromRange(float minInclusive, float maxExclusive)
{
	float randomFNumberFromRange = 0.0f;

	randomFNumberFromRange = RANDOM_NUMBER_RANGE_SIZE * (float)rand() / RAND_MAX  + minInclusive;
	
	return randomFNumberFromRange;
}

//float Random_GetFNumberFromRange(float minInclusive, float maxExclusive)
//{
//	
//
//	
//
//	
//}