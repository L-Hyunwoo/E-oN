#include <stdio.h>

int main(void)
{

	int num = 1, i; //���� �Է�

	while (1) //������ �����ʰ� ���� �ݺ�
	{
		for (i = 1; i <= 20; i++) //1���� 20���� �ݺ�
		{
			if (num % i != 0) //num�� 1���� 20������ �� �� �ϳ��� ���������� ������
				break; //��������
		}
		if (i == 21) //i�� 21�� �ȴٸ�
			break;  //��������
		num++;
	}

	printf("%d\n", num); //num�� ���
	return 0;
}