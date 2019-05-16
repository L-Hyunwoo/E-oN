#include <stdio.h>

int main(void)
{
	int input, i;		//값들 입력

	printf("홀수 입력 : ");		//입력을 위한 메세지 출력
	scanf_s("%d", &input);		//input에 값 입력

	for (int i = 1; i <= input; i += 2)		//i가 input까지 홀수번만 반복
	{
		for (int j = input; j > i; j -= 2)	//공백 부분 반복
			printf(" ");		
		for (int k = 1; k <= i; k++)				//* 부분 반복
			printf("*");
		printf("\n");
	}
	for (i = 1; i <= input; i += 2)		//i가 input까지 홀수번만 반복
	{
		for (int j = 1; j <= i; j += 2)		//공백 부분 반복
			printf(" ");
		for (int k = input -  i - 1; k > 0; k--)		//* 부분 반복
			printf("*");
		printf("\n");
	}
	return 0;
}