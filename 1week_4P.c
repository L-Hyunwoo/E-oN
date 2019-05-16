#include <stdio.h>

int main(void)
{
	int a, b, c, d, i, multi1, multi2, result = 0;		//값들을 설정
	int arr[6];		//대칭을 찾기 위한 배열 설정

	for (a = 100; a <= 999; a++)		//a가 100부터 999가 될 때까지 반복
	{
		for (b = 100; b <= a; b++)		//b가 100부터 a가 될때까지 반복
		{
			multi1 = multi2 = a * b;		//mul에 a*b입력
			for (i = 5; i >= 0; i--)	//배열 5부터 0이 될 때까지 감소 반복
			{
				arr[i] = multi1 % 10;		//arr[i]에 10을 나눈 mul의 나머지 입력
				multi1 = multi1 / 10;		//mul에 10을 나눗셈
			}
			if (arr[5] == arr[0] && arr[4] == arr[1] && arr[3] == arr[2])		//대칭배열일때
			{
				if (result < multi2)		//result가 mul보다 작을때
				{
					result = multi2;		//result에 mul 입력
					c = a;		//c에 a 입력
					d = b;		//c에 b 입력
				}
			}
		}
	}
	printf("답:%d x %d = %d \n", c, d, result);		//결과 출력
	return 0;
}