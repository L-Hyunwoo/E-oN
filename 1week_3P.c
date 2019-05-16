/*어떤 수를 소수의 곱으로만 나타내는 것을 소인수분해라 하고, 이 소수들을 그 수의 소인수라고 합니다.
예를 들면 13195의 소인수는 5, 7, 13, 29 입니다.
600851475143의 소인수 중에서 가장 큰 수를 구하세요.*/

#include <stdio.h>

int main(void)
{
	long long i, save = 1, result, num = 600851475143;		//값들 설정
	for (i = 2; i <= num; i++)		//i가 2에서 600851475143까지 반복
	{
		if (num % i == 0)		// num이 i로 나누어 떨어진다면
		{
			num = num / i;		//num에 인수를 나눗셈
			result = i;		//result에 인수값 저장
		}
	}
	printf("%d \n", result);		//출력
}