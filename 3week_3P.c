/*�� �簢�� ��ǥ�� �־��� �� �� �簢���� ������(overlap) �Ǵ��� �ƴ����� �Ǵ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� �����ϰų� �������� �����ϴ� ��쿡�� overlap �Ǵ� ������ �����Ѵ�.
*�迭�� ������ ���� Ƚ���� ������ �϶�.(�����Ҵ� Ȱ��) */

#include <stdio.h>

int main(void)
{
	int n, i;
	int *p;

	scanf_s("%d", &n);		//���� Ƚ�� �Է�
	p = (int*)malloc(n * sizeof(int));		//�����Ҵ� ���

	for (i = 0; i <= (n - 1); i++)
		*(p + i) = Overlap_find();		//������ �Ǵ� �Լ��� �̵�

	for (i = 0; i <= (n - 1); i++)
		printf("%d", *(p + i));		//������ ��� ���

	return 0;
}

int Overlap_find(void)
{
	int x1[2], y1[2], x2[2], y2[2], overlap_x = 0, overlap_y = 0;
	int *pa1, *pa2, *pb1, *pb2;

	scanf_s("%d %d %d %d", &x1[0], &y1[0], &x1[1], &y1[1]);	//ù��° �簢�� ���� �Է�
	scanf_s("%d %d %d %d", &x2[0], &y2[0], &x2[1], &y2[1]);	//�ι�° �簢�� ���� �Է�
	pa1 = x1;
	pa2 = y1;
	pb1 = x2;
	pb2 = y2;

	overlap_x = term(pa1, (pa1 + 1), pb1, (pb1 + 1));	//x��ǥ ��
	overlap_y = term(pa2, (pa2 + 1), pb2, (pb2 + 1));	//y��ǥ ��

	return (overlap_x * overlap_y);
}


int term(int* a1, int* a2, int* b1, int* b2)		//�����Լ� ����
{
	int i, overlap = 0;

	if ((*a2 - *a1) >= (*b2 - *b1))		//ù��° �簢���� ��ǥ���� �ι�° �簢���� ��ǥ������ Ŭ��
	{
		for (i = *a1; i <= *a2; i++)		//��ǥ(a1)���� ��ǥ(a2)���� �ݺ�����
		{
			if (i == *b2 || i == *b1)		//��ǥ(i)�� ��ǥ(b1) �Ǵ� ��ǥ(b2)�� ������
			{
				overlap = 1;		//overlap ���� ����
			}
		}
	}
	else		//ù��° �簢���� ��ǥ���� �ι�° �簢���� ��ǥ������ �۰ų� ������
	{
		for (i = *b1; i <= *b2; i++)		//i�� ��ǥ(b1)���� ��ǥ(b2)���� �ݺ�����
		{
			if (i == *a2 || i == *a1)		//��ǥ(i)�� ��ǥ(a2) �Ǵ� ��ǥ(a1)�� ������
			{
				overlap = 1;		//overlap ���� ����
			}
		}
	}
	return overlap;	//overlap ���� ���� �Լ��� ����
}