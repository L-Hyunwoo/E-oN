/*ũ�Ⱑ 10�� �迭�� �����ϰ�
Push, Pop, Show(���ÿ� �ִ� �����͵��� ���)������ �����ϴ� ���α׷��� ����ÿ�.*/

#include<stdio.h>
int main(void)
{
	int i, com, count = 0, input, arr[10];
	printf("PUSH : 1\nPOP : 2\nSHOW : 3\n");
	printf("(���� �Ϸ��� 1,2,3 �̿��� �� �Է�)\n\n");
	while (1)		//�ݺ��� ����
	{

		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &com);		//������ �޴� �Է�
		if (com == 1)		//push�� �����ϰ��� �Ҷ�
		{
			if (count > 9)		//�迭 10ĭ�� �� ä������
			{
				count = 10;		//10���� �ٽ� ����
				printf("�迭 ������ �Ѿ����ϴ�.\n");
			}
			else
			{
				printf("�� �Է� : ");
				scanf_s("%d", &input);		//������ ���� �Է�
				arr[count] = input;		//�迭�� �Է°� ����
				count++;		//count+1
			}
		}
		else if (com == 2)		//pop�� �����ϰ��� �Ҷ�
		{
			if (count == 0)		//���̻� ������ �迭�� ������
				printf("������ �迭�� �����ϴ�. \n");
			else
			{
				count--;
				arr[count] = ' ';
			}
		}
		else if (com == 3)		//SHOW�� �����ϰ��� �Ҷ�
		{
			for (i = 0; i < count; i++)		//�迭 0������ �Էµ� �迭���� �ݺ�
				printf("%d  ", arr[i]);
			printf("\n");
		}
		else		//�� �� ������ ���ڸ� �Է¹޾��� ��
		{
			printf("========== ���� ���α׷��� �����մϴ� ==========");
			break;
		}
	}
	return 0;
}
