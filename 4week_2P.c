/* 크기가 10인 배열을 설정하고, Push, Pop, Show(스택에 있는 데이터들을 출력)연산을 수행하는 프로그램을 만드시오. */

#include<stdio.h>
#include<stdlib.h>

struct order
{
	int i, command, count;		//실행할 명령어 입력
	int *data;		//실행할 명령어 입력
};


int main(void)
{
	struct order o;

	o.count = -1;
	o.data = (int *)malloc(sizeof(int) * 10);

	printf("PUSH : 1\nPOP : 2\nSHOW : 3\n");
	printf("(종료 하려면 1,2,3 이외의 수 입력)\n\n");

	while (1)
	{
		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &o.command);		//실행할 메뉴 입력
		if (o.command == 1)		//push를 실행하고자 할때
		{
			o.count++;		//count+1
			if (o.count > 9)		//배열 10칸을 다 채웠을때
			{
				o.count = 9;			//9로 다시 조정
				printf("배열 개수 넘었습니다.\n");
				continue;
			}
			o.data[o.count] = push();		//push함수로 data값 저장
		}
		else if (o.command == 2)		//pop을 실행하고자 할때
		{
			if (o.count == 0)		//더이상 삭제할 배열이 없을때
				printf("삭제할 배열이 없습니다. \n");
			else
			{
				o.data[o.count] = o.data[o.count + 1];		//data값을 하나씩 당김
				o.count--;		//count - 1
			}
		}
		else if (o.command == 3)		//SHOW를 실행하고자 할때
		{
			for (o.i = 0; o.i <= o.count; o.i++)		//배열 0번부터 입력된 배열까지 반복
			{
				printf("%d ", o.data[o.i]);
			}
			printf("\n");
		}
		else		//그 외 나머지 숫자를 입력받았을 때
		{
			free(o.data);
			printf("========== 스택 프로그램을 종료합니다 =============");
			break;
		}
	}
}

int push(void)
{
	int input;
	printf("수 입력 : ");
	scanf_s("%d", &input);
	return input;
}