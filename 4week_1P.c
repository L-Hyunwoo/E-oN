/* http://59.23.150.58/30stair/print/print.php?pname=print */

#include <stdio.h>
#include <stdlib.h>


struct data
{
	int value;
	int test;
	struct data *next;
};

void RemoveSp(struct data **start)
{
	struct data *del = *start;	//공간 초기화
	*start = (*start)->next;		//1번을 2번으로 설정
	free(del);
}

void MoveLast(struct data **start, struct data **end)
{
	(*end)->next = *start;			//1번을 마지막으로 연결
	*start = (*start)->next;		//2번을 1번으로 설정
	*end = (*end)->next;			//1번을 마지막으로 이동
	(*end)->next = NULL;			//마지막을 삭제
}

int TestDaTa(struct data *testdata)
{
	int test = 0;
	int testValue = testdata->value;
	while (testdata != NULL) {
		if (testValue < testdata->value)
			return 1;
		testdata = testdata->next;
	}
	return 0;
}
int main(void)
{

	int allCount, setNum, timeValue = 0;

	printf("입력 \n");
	scanf_s("%d %d", &allCount, &setNum);


	struct data *start = malloc(sizeof(struct data) * 1);	 //1번 설정
	struct data *end = start;		//마지막 설정

	for (int c = 0; c < allCount; c++)
	{
		int iValue;
		scanf_s("%d", &iValue);
		end->value = iValue;		//입력받은 수를 마지막 값으로 설정

		if (c == setNum)
			end->test = 1;		//검사할 번째 test값에 1 대입
		else
			end->test = 0;
		if (c + 1 == allCount)
			end->next = NULL;	//마지막공간 삭제
		else
		{
			end->next = malloc(sizeof(struct data) * 1);
			end = end->next;
		}
	}


	while (1)
	{
		if (TestDaTa(start) == 1)				//뒤에 높은 우선순위가 있으면
			MoveLast(&start, &end);		//뒤로 이동
		else		//프린트 출력할때
		{
			timeValue++;		//한번 프린트 될때마다 시간변수 + 1

			if (start->test == 1)		//프린트 출력될 수가 내가 검사하려는 수인지 판별
				break;
			else
				RemoveSp(&start);		//출력으로 인정 지우기
		}
	}
	printf("\n출력 \n");
	printf("%d\n", timeValue);
	return 0;
}