/*두 사각형 좌표가 주어질 때 두 사각형이 오버랩(overlap) 되는지 아닌지를 판단하는 프로그램을 작성하시오.
변을 공유하거나 꼭지점을 공유하는 경우에도 overlap 되는 것으로 간주한다.
*배열의 개수는 시행 횟수와 같도록 하라.(동적할당 활용) */

#include <stdio.h>

int main(void)
{
	int n, i;
	int *p;

	scanf_s("%d", &n);		//시행 횟수 입력
	p = (int*)malloc(n * sizeof(int));		//동적할당 사용

	for (i = 0; i <= (n - 1); i++)
		*(p + i) = Overlap_find();		//오버랩 판단 함수로 이동

	for (i = 0; i <= (n - 1); i++)
		printf("%d", *(p + i));		//오버랩 결과 출력

	return 0;
}

int Overlap_find(void)
{
	int x1[2], y1[2], x2[2], y2[2], overlap_x = 0, overlap_y = 0;
	int *pa1, *pa2, *pb1, *pb2;

	scanf_s("%d %d %d %d", &x1[0], &y1[0], &x1[1], &y1[1]);	//첫번째 사각형 범위 입력
	scanf_s("%d %d %d %d", &x2[0], &y2[0], &x2[1], &y2[1]);	//두번째 사각형 범위 입력
	pa1 = x1;
	pa2 = y1;
	pb1 = x2;
	pb2 = y2;

	overlap_x = term(pa1, (pa1 + 1), pb1, (pb1 + 1));	//x좌표 비교
	overlap_y = term(pa2, (pa2 + 1), pb2, (pb2 + 1));	//y좌표 비교

	return (overlap_x * overlap_y);
}


int term(int* a1, int* a2, int* b1, int* b2)		//지역함수 생성
{
	int i, overlap = 0;

	if ((*a2 - *a1) >= (*b2 - *b1))		//첫번째 사각형의 좌표폭이 두번째 사각형의 좌표폭보다 클때
	{
		for (i = *a1; i <= *a2; i++)		//좌표(a1)부터 좌표(a2)까지 반복실행
		{
			if (i == *b2 || i == *b1)		//좌표(i)가 좌표(b1) 또는 좌표(b2)와 같을때
			{
				overlap = 1;		//overlap 조건 충족
			}
		}
	}
	else		//첫번째 사각형의 좌표폭이 두번째 사각형의 좌표폭보다 작거나 같을때
	{
		for (i = *b1; i <= *b2; i++)		//i를 좌표(b1)부터 좌표(b2)까지 반복실행
		{
			if (i == *a2 || i == *a1)		//좌표(i)가 좌표(a2) 또는 좌표(a1)과 같을때
			{
				overlap = 1;		//overlap 조건 충족
			}
		}
	}
	return overlap;	//overlap 값을 메인 함수로 전달
}