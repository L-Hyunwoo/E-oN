/*������ ���� ������ �ִ�
1
1 1
1 2
1 1 2 1
1 2 2 1 1 1
1 1 2 2 1 3 1
1 2 2 2 1 1 3 1
1 1 2 3 1 2 3 1 1 1 ...
������ ��Ģ�� �����ϴ� �ڵ带 �ϼ��ϵ�

ũ�Ⱑ 30�� �迭�� �����ϰ�, �Է��� ������ ���� 0���� �Ѵ�.*/

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
		if (arr[c] == data)			//�ռ��ڿ� �ڼ��ڰ� ������
		{
			count++;		//count + 1
		}
		else				//�ռ��ڿ� �ڼ��ڰ� �ٸ���
		{
			printf("%d %d ", data, count);
			data = arr[c];		//data�� c��° �迭�� ���� ����
			count = 1;		//count �ʱ�ȭ
		}
	}
	return 0;
}