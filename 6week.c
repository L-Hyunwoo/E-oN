#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char input[100];		//입력받을 문자
	int ans = 0;		//회문 판단 여부

	printf("문자열 입력 : ");
	scanf("%s", &input);

	int length = strlen(input);		//입력받은 문자열의 길이 계산
	char *test = (char*)malloc(sizeof(char) * (length));		//문자열의 길이만큼 동적할당
	strcpy(test, input);		//test에 input 복사
	
	for (int i = 0; i < length / 2; i++)		//문자열의 절반만큼 반복 실행
	{
		if (test[i] != test[length - i - 1])		//문자열 앞에서 i번째와 뒤에서 i번째가 다를 경우
		{
			ans++;		//ans에 값을 추가
			break;
		}
	}

	if (ans == 0)
		printf("출력 : 회문입니다.\n");			//ans가 0일 때 회문
	else
		printf("출력 : 회문이 아닙니다.\n");		//ans가 1일 때 회문

	return 0;
}