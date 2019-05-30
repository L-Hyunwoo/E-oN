/* ũ�Ⱑ 10�� �迭�� �����ϰ�, Push, Pop, Show(���ÿ� �ִ� �����͵��� ���)������ �����ϴ� ���α׷��� ����ÿ�. */

#include<stdio.h>
#include<stdlib.h>

struct order
{
	int i, command, count;		//������ ��ɾ� �Է�
	int *data;		//������ ��ɾ� �Է�
};


int main(void)
{
	struct order o;

	o.count = -1;
	o.data = (int *)malloc(sizeof(int) * 10);

	printf("PUSH : 1\nPOP : 2\nSHOW : 3\n");
	printf("(���� �Ϸ��� 1,2,3 �̿��� �� �Է�)\n\n");

	while (1)
	{
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &o.command);		//������ �޴� �Է�
		if (o.command == 1)		//push�� �����ϰ��� �Ҷ�
		{
			o.count++;		//count+1
			if (o.count > 9)		//�迭 10ĭ�� �� ä������
			{
				o.count = 9;			//9�� �ٽ� ����
				printf("�迭 ���� �Ѿ����ϴ�.\n");
				continue;
			}
			o.data[o.count] = push();		//push�Լ��� data�� ����
		}
		else if (o.command == 2)		//pop�� �����ϰ��� �Ҷ�
		{
			if (o.count == 0)		//���̻� ������ �迭�� ������
				printf("������ �迭�� �����ϴ�. \n");
			else
			{
				o.data[o.count] = o.data[o.count + 1];		//data���� �ϳ��� ���
				o.count--;		//count - 1
			}
		}
		else if (o.command == 3)		//SHOW�� �����ϰ��� �Ҷ�
		{
			for (o.i = 0; o.i <= o.count; o.i++)		//�迭 0������ �Էµ� �迭���� �ݺ�
			{
				printf("%d ", o.data[o.i]);
			}
			printf("\n");
		}
		else		//�� �� ������ ���ڸ� �Է¹޾��� ��
		{
			free(o.data);
			printf("========== ���� ���α׷��� �����մϴ� =============");
			break;
		}
	}
}

int push(void)
{
	int input;
	printf("�� �Է� : ");
	scanf_s("%d", &input);
	return input;
}