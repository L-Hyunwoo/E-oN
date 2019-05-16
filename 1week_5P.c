#include <stdio.h>

int main(void)
{

	int num = 1, i; //값들 입력

	while (1) //제한을 두지않고 무한 반복
	{
		for (i = 1; i <= 20; i++) //1부터 20까지 반복
		{
			if (num % i != 0) //num이 1에서 20까지의 수 중 하나로 나누어지지 않으면
				break; //수행종료
		}
		if (i == 21) //i가 21이 된다면
			break;  //수행종료
		num++;
	}

	printf("%d\n", num); //num값 출력
	return 0;
}