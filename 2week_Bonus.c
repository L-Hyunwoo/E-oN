/*다음과 같은 수열이 있다
1
1 1
1 2
1 1 2 1
1 2 2 1 1 1
1 1 2 2 1 3 1
1 2 2 2 1 1 3 1
1 1 2 3 1 2 3 1 1 1 ...
다음의 규칙을 만족하는 코드를 완성하되

크기가 30인 배열을 선언하고, 입력의 마지막 수는 0으로 한다.*/

#include <stdio.h>

int main(void)
{

	int arr[30], c = 0, i;

	for (i = 0; i <= 30; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] == 0)
			break;
	}
	int data = arr[0], count = 1;
	while (arr[c] != 0)
	{
		c++;
		if (arr[c] == data)			//앞숫자와 뒤숫자가 같을때
		{
			count++;		//count + 1
		}
		else				//앞숫자와 뒤숫자가 다를때
		{
			printf("%d %d ", data, count);
			data = arr[c];		//data를 c번째 배열의 수로 설정
			count = 1;		//count 초기화
		}
	}
	return 0;
}