/*�߰� �κ��� *�� ����(Ȧ��)�� �Է¹ް� 
���̾Ƹ�尡 ��µǴ� ���α׷��� �����Ͻÿ�*/

#include <stdio.h>

int main(void)
{
	int input, i;		//���� �Է�

	printf("Ȧ�� �Է� : ");		//�Է��� ���� �޼��� ���
	scanf_s("%d", &input);		//input�� �� �Է�

	for (int i = 1; i <= input; i += 2)		//i�� input���� Ȧ������ �ݺ�
	{
		for (int j = input; j > i; j -= 2)	//���� �κ� �ݺ�
			printf(" ");		
		for (int k = 1; k <= i; k++)				//* �κ� �ݺ�
			printf("*");
		printf("\n");
	}
	for (i = 1; i <= input; i += 2)		//i�� input���� Ȧ������ �ݺ�
	{
		for (int j = 1; j <= i; j += 2)		//���� �κ� �ݺ�
			printf(" ");
		for (int k = input -  i - 1; k > 0; k--)		//* �κ� �ݺ�
			printf("*");
		printf("\n");
	}
	return 0;
}