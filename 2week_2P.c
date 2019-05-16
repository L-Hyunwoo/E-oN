/*크기가 10인 배열을 설정하고
Push, Pop, Show(스택에 있는 데이터들을 출력)연산을 수행하는 프로그램을 만드시오.*/

#include<stdio.h>
int main(void)
{
	int i, com, count = 0, input, arr[10];
	printf("PUSH : 1\nPOP : 2\nSHOW : 3\n");
	printf("(종료 하려면 1,2,3 이외의 수 입력)\n\n");
	while (1)		//반복문 실행
	{

		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &com);		//실행할 메뉴 입력
		if (com == 1)		//push를 실행하고자 할때
		{
			if (count > 9)		//배열 10칸을 다 채웠을때
			{
				count = 10;		//10으로 다시 조정
				printf("배열 개수를 넘었습니다.\n");
			}
			else
			{
				printf("수 입력 : ");
				scanf_s("%d", &input);		//저장할 숫자 입력
				arr[count] = input;		//배열에 입력값 저장
				count++;		//count+1
			}
		}
		else if (com == 2)		//pop을 실행하고자 할때
		{
			if (count == 0)		//더이상 삭제할 배열이 없을때
				printf("삭제할 배열이 없습니다. \n");
			else
			{
				count--;
				arr[count] = ' ';
			}
		}
		else if (com == 3)		//SHOW를 실행하고자 할때
		{
			for (i = 0; i < count; i++)		//배열 0번부터 입력된 배열까지 반복
				printf("%d  ", arr[i]);
			printf("\n");
		}
		else		//그 외 나머지 숫자를 입력받았을 때
		{
			printf("========== 스택 프로그램을 종료합니다 ==========");
			break;
		}
	}
	return 0;
}
