#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char input[100];		//�Է¹��� ����
	int ans = 0;		//ȸ�� �Ǵ� ����

	printf("���ڿ� �Է� : ");
	scanf("%s", &input);

	int length = strlen(input);		//�Է¹��� ���ڿ��� ���� ���
	char *test = (char*)malloc(sizeof(char) * (length));		//���ڿ��� ���̸�ŭ �����Ҵ�
	strcpy(test, input);		//test�� input ����
	
	for (int i = 0; i < length / 2; i++)		//���ڿ��� ���ݸ�ŭ �ݺ� ����
	{
		if (test[i] != test[length - i - 1])		//���ڿ� �տ��� i��°�� �ڿ��� i��°�� �ٸ� ���
		{
			ans++;		//ans�� ���� �߰�
			break;
		}
	}

	if (ans == 0)
		printf("��� : ȸ���Դϴ�.\n");			//ans�� 0�� �� ȸ��
	else
		printf("��� : ȸ���� �ƴմϴ�.\n");		//ans�� 1�� �� ȸ��

	return 0;
}