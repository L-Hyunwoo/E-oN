/*�� �簢�� ��ǥ�� �־��� �� �� �簢���� ������(overlap) �Ǵ��� �ƴ����� �Ǵ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� �����ϰų� �������� �����ϴ� ��쿡�� overlap �Ǵ� ������ �����Ѵ�.*/

#include <stdio.h>

int main(void)
{
	int x1[2], y1[2], x2[2], y2[2], overlap_x = 0, overlap_y = 0;

	scanf_s("%d %d %d %d", &x1[0], &y1[0], &x1[1], &y1[1]);	//ù��° �簢�� ���� �Է�
	scanf_s("%d %d %d %d", &x2[0], &y2[0], &x2[1], &y2[1]);	//�ι�° �簢�� ���� �Է�

	overlap_x = term(x1[0], x1[1], x2[0], x2[1]);	//x��ǥ ��
	overlap_y = term(y1[0], y1[1], y2[0], y2[1]);	//y��ǥ ��

	if ((overlap_x * overlap_y) == 1)		//x,y��ǥ �Ѵ� 1�϶� overlap ���
	{
		printf("Overlap");
	}
	else		//�� �ܿ� No overlap ���
	{
		printf("No overlap");
	}
	return 0;
}

int term(int a1, int a2, int b1, int b2)		//�����Լ� ����
{
	int i, overlap = 0;

	if ((a2 - a1) >= (b2 - b1))		//ù��° �簢���� ��ǥ���� �ι�° �簢���� ��ǥ������ Ŭ��
	{
		for (i = a1; i <= a2; i++)		//��ǥ(a1)���� ��ǥ(a2)���� �ݺ�����
		{
			if (i == b2 || i == b1)		//��ǥ(i)�� ��ǥ(b1) �Ǵ� ��ǥ(b2)�� ������
			{
				overlap = 1;		//overlap ���� ����
			}
		}
	}
	else		//ù��° �簢���� ��ǥ���� �ι�° �簢���� ��ǥ������ �۰ų� ������
	{
		for (i = b1; i <= b2; i++)		//i�� ��ǥ(b1)���� ��ǥ(b2)���� �ݺ�����
		{
			if (i == a2 || i == a1)		//��ǥ(i)�� ��ǥ(a2) �Ǵ� ��ǥ(a1)�� ������
			{
				overlap = 1;		//overlap ���� ����
			}
		}
	}
	return overlap;	//overlap ���� ���� �Լ��� ����
}