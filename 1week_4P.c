#include <stdio.h>

int main(void)
{
	int a, b, c, d, i, multi1, multi2, result = 0;		//������ ����
	int arr[6];		//��Ī�� ã�� ���� �迭 ����

	for (a = 100; a <= 999; a++)		//a�� 100���� 999�� �� ������ �ݺ�
	{
		for (b = 100; b <= a; b++)		//b�� 100���� a�� �ɶ����� �ݺ�
		{
			multi1 = multi2 = a * b;		//mul�� a*b�Է�
			for (i = 5; i >= 0; i--)	//�迭 5���� 0�� �� ������ ���� �ݺ�
			{
				arr[i] = multi1 % 10;		//arr[i]�� 10�� ���� mul�� ������ �Է�
				multi1 = multi1 / 10;		//mul�� 10�� ������
			}
			if (arr[5] == arr[0] && arr[4] == arr[1] && arr[3] == arr[2])		//��Ī�迭�϶�
			{
				if (result < multi2)		//result�� mul���� ������
				{
					result = multi2;		//result�� mul �Է�
					c = a;		//c�� a �Է�
					d = b;		//c�� b �Է�
				}
			}
		}
	}
	printf("��:%d x %d = %d \n", c, d, result);		//��� ���
	return 0;
}