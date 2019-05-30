/* http://59.23.150.58/30stair/print/print.php?pname=print */

#include <stdio.h>
#include <stdlib.h>


struct data
{
	int value;
	int test;
	struct data *next;
};

void RemoveSp(struct data **start)
{
	struct data *del = *start;	//���� �ʱ�ȭ
	*start = (*start)->next;		//1���� 2������ ����
	free(del);
}

void MoveLast(struct data **start, struct data **end)
{
	(*end)->next = *start;			//1���� ���������� ����
	*start = (*start)->next;		//2���� 1������ ����
	*end = (*end)->next;			//1���� ���������� �̵�
	(*end)->next = NULL;			//�������� ����
}

int TestDaTa(struct data *testdata)
{
	int test = 0;
	int testValue = testdata->value;
	while (testdata != NULL) {
		if (testValue < testdata->value)
			return 1;
		testdata = testdata->next;
	}
	return 0;
}
int main(void)
{

	int allCount, setNum, timeValue = 0;

	printf("�Է� \n");
	scanf_s("%d %d", &allCount, &setNum);


	struct data *start = malloc(sizeof(struct data) * 1);	 //1�� ����
	struct data *end = start;		//������ ����

	for (int c = 0; c < allCount; c++)
	{
		int iValue;
		scanf_s("%d", &iValue);
		end->value = iValue;		//�Է¹��� ���� ������ ������ ����

		if (c == setNum)
			end->test = 1;		//�˻��� ��° test���� 1 ����
		else
			end->test = 0;
		if (c + 1 == allCount)
			end->next = NULL;	//���������� ����
		else
		{
			end->next = malloc(sizeof(struct data) * 1);
			end = end->next;
		}
	}


	while (1)
	{
		if (TestDaTa(start) == 1)				//�ڿ� ���� �켱������ ������
			MoveLast(&start, &end);		//�ڷ� �̵�
		else		//����Ʈ ����Ҷ�
		{
			timeValue++;		//�ѹ� ����Ʈ �ɶ����� �ð����� + 1

			if (start->test == 1)		//����Ʈ ��µ� ���� ���� �˻��Ϸ��� ������ �Ǻ�
				break;
			else
				RemoveSp(&start);		//������� ���� �����
		}
	}
	printf("\n��� \n");
	printf("%d\n", timeValue);
	return 0;
}