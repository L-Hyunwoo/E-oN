#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Data
{
	char *name;
	char *writer;
	char *year;
	char *company;
	char *genre;
	struct Data *NextData;
};

struct Data* load(struct Data *DataStart)		//���� �ε� ����ü
{
	struct Data *loop = DataStart;

	FILE *ifile = fopen("input.txt", "r");		//���� �ҷ�����

	if (ifile == NULL)		//������ ������ ����
	{
		printf("���� �ε� ����\n");
		exit(1);
	}

	char db[5][100];		//�����͸� ���� �迭 ����

	while (!feof(ifile))		//������ ���� ������ ������ �ݺ�
	{
		fscanf(ifile, "%s %s %s %s %s", db[0], db[1], db[2], db[3], db[4]);		//������ �����͸� ������ ����
		char *out[5];
		for (int i = 0; i < 5; i++)
		{
			out[i] = malloc(sizeof(char) * (strlen(db[i])));		//�����͸� �����Ҵ��� ����
			strcpy(out[i], db[i]);		//db�� out�� ����
		}

		struct Data *NewData = malloc(sizeof(struct Data) * 1);			//newdata�� data�� ũ�⸸ŭ �����Ҵ�
		NewData->name = out[0];			//�������� newdata�� ����
		NewData->writer = out[1];		//���ڸ� newdata�� ����
		NewData->year = out[2];			//���࿬���� newdata�� ����
		NewData->company = out[3];		//���ǻ縦 newdata�� ����
		NewData->genre = out[4];		//�帣�� newdata�� ����
		NewData->NextData = NULL;		//���� �����Ϳ� NULL�� ����

		if (DataStart == NULL)		//data�� ������
		{
			DataStart = NewData;	//newdata�� data�� ����
			loop = DataStart;		//data�� loop�� ����
		}
		else
		{
			loop->NextData = NewData;		//���� �����Ϳ� newdata ����
			loop = loop->NextData;		//loop�� ���� �����͸� ����
		}
	}
	fclose(ifile);		//file�� ����
	return DataStart;		//data�� ����
}

struct Data* save(struct Data *print)		//���� ���� �Լ�
{
	FILE *ofile = fopen("input.txt", "w");

	if (ofile == NULL)
	{
		printf("���� �ε� ����\n");
		exit(1);
	}

	while (print != NULL)
	{
		if (print->NextData == NULL)
			fprintf(ofile, "%s %s %s %s %s", print->name, print->writer, print->year, print->company, print->genre);
		else
			fprintf(ofile, "%s %s %s %s %s\n", print->name, print->writer, print->year, print->company, print->genre);
		print = print->NextData;
	}

	fclose(ofile);
	printf("File Save Completed! \n");
}

int PrintBook(struct Data *DataStart);		//����Լ��� ���İ�

char* String()		//�Է¹��� ������ ũ�⸸ŭ �����Ҵ�
{
	char db[100];
	scanf("%s", db);
	char *out = malloc(sizeof(char) * (strlen(db)));
	strcpy(out, db);
	return out;
}

struct Data* Add(struct Data *DataStart)		//���� �߰� ����ü
{
	struct Data* link = DataStart;		//link�� data�� �Է�

	printf("�߰��� ������ �Է��ϼ���. \n");
	printf("(������ ���� ���ǿ��� ���ǻ�� �帣 ������ �Է�)\n");
	struct Data *NewData = malloc(sizeof(struct Data) * 1);		//newdata�� dataũ�⸸ŭ �����Ҵ�
	NewData->name = String();		//�������� �Է¹ް� ����
	NewData->writer = String();		//���ڸ� �Է¹ް� ����
	NewData->year = String();		//���࿬���� �Է¹ް� ����
	NewData->company = String();	//���ǻ縦 �Է¹ް� ����
	NewData->genre = String();		//�帣�� �Է¹ް� ����
	NewData->NextData = NULL;		//���� �����Ϳ� NULL���� �Է�

	if (DataStart == NULL)		//data�� NULL���̸� newdata �Է�
		DataStart = NewData;
	else
	{
		while (link->NextData != NULL)		//���������Ͱ� NULL���϶����� �ݺ�
			link = link->NextData;		//link�� ���������� ����
		
		link->NextData = NewData;		//���� �����Ϳ� newdata ����
	}

	return DataStart;
}

struct Data* SearchNode(struct Data *test, char *put)		//���� �˻� ����ü
{
	if (test == NULL)		//���Ͽ� ����� ������ ������ ����
		return NULL;
	else
	{
		while (test != NULL)		//test�� NULL���� ������ �ݺ�
		{
			if (strstr(test->name, put) != NULL)		//�˻��� �ܾ ������ ���Ե� ��
				return test;
			else if (strstr(test->writer, put) != NULL)		//�˻��� �ܾ ���ڿ� ���Ե� ��
				return test;
			else if (strstr(test->year, put) != NULL)		//�˻��� �ܾ ���࿬���� ���Ե� ��
				return test;
			else if (strstr(test->company, put) != NULL)		//�˻��� �ܾ ���ǻ翡 ���Ե� ��
				return test;
			else if (strstr(test->genre, put) != NULL)		//�˻��� �ܾ �帣�� ���Ե� ��
				return test;
			else
				test = test->NextData;		//�������� ��� ���� �����ͷ� �Ѿ
		}
		return NULL;
	}
}

struct Data* Search(struct DataList *link)		//�����˻� �Լ�
{
	printf("Ű���带 �Է����ּ���. : ");
	char *put = String();		//Ű���� �Է�
	
	struct Data *print;		//print ����ü ����
	while (link != NULL)		//link�� NULL���� ������ �ݺ�
	{
		print = SearchNode(link, put);		//�����˻�����ü�� �̵�

		if (print == NULL)
			break;
		else
		{
			printf("%s, %s, %s, %s, %s\n", print->name, print->writer, print->year, print->company, print->genre);
			link = print->NextData;
		}
	}
	printf("----------------------------------------------\n");
}

struct Data* Edit(struct Data *DataStart)		//���� ���� ���� �Լ�
{
	if (DataStart == NULL)		//������ �����Ͱ� ���� ��� ����
		return;

	PrintBook(DataStart);		//���� ��� ���

	struct Data* test = DataStart;		//test ����ü ����
	while (1)
	{
		printf("\n������ �������� ��Ȯ�� �Է��ϼ���:");
		char *edit = String();		//������ �Է�

		while (test != NULL)		//test�� NULL���� �� ������ �ݺ�
		{
			if (strcmp(test->name, edit) == 0)		//�Է¹��� ������� ��ġ�ϴ� �������� ����
				break;
			else
				test = test->NextData;
		}
		if (test == NULL)	//test�� NULL���� ���
		{
			test = DataStart;		//test�� data ����
			printf("�˻��� �������� �����ϴ�.\n");
		}
		else
			break;
	}

	printf("������ ����� �����ϼ���. \n");
	printf("1. ������\n");
	printf("2. ����\n");
	printf("3. ���ǿ���\n");
	printf("4. ���ǻ��\n");
	printf("5. �帣\n");
	int num;
	while (1)
	{
		scanf("%d", &num);
		switch (num)
		{
		case 1:		//�������� �����ϰ��� �� ��
			printf("������ ������ �Է� : ");
			test->name = String();
			break;
		case 2:		//���ڸ� �����ϰ��� �� ��
			printf("������ ���� �Է� : ");
			test->writer = String();
			break;
		case 3:		//���ǿ����� �����ϰ��� �� ��
			printf("������ ���ǿ��� �Է� : ");
			test->year = String();
			break;
		case 4:		//���ǻ���� �����ϰ��� �� ��
			printf("������ ���ǻ�� �Է� : ");
			test->company = String();
			break;
		case 5:		//�帣�� �����ϰ��� �� ��
			printf("������ �帣 �Է� : ");
			test->genre = String();
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���:");
			continue;
			break;
		}
		break;
	}
	printf("���� ���� ��� : %s %s %s %s %s\n", test->name, test->writer, test->year, test->company, test->genre);
	printf("----------------------------------------------\n");
}

struct Data* Delete(struct Data *DataStart)		//���� ���� ���� ����ü
{
	PrintBook(DataStart);		//���� ��� ���

	struct Data* test = DataStart;		//test ����ü ����

	while (1)
	{
		printf("\n������ �������� ��Ȯ�� �Է��ϼ���:");
		char *del = String();		//������ ������ �Է�
		while (test != NULL)
		{
			if (strcmp(test->name, del) == 0)		//�Է¹��� ������� ��ġ�ϴ� �������� ����
				break;
			else
				test = test->NextData;
		}
		if (test == NULL)
		{
			test = DataStart;
			printf("�˻��� �������� �����ϴ�.\n");
		}
		else
			break;
	}

	struct Data* loop = DataStart;		//loop ����ü ����
	if (test == DataStart)		//test�� data�� ���� ��
	{
		DataStart = DataStart->NextData;		//data�� ���� �����ͷ� ����
		free(test);		//test �ʱ�ȭ
	}
	else
	{
		while (loop != NULL)		//loop�� NULL���� ���� ������ �ݺ�
		{
			if (loop->NextData == test)		//���������Ͱ� test�� ���� �� ����
				break;
			else
				loop = loop->NextData;		//loop�� ���������� ����
		}
		loop->NextData = test->NextData;
		free(test);		//test �ʱ�ȭ
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	return DataStart;
}

int PrintBook(struct Data *DataStart)		//���� ��� ��� �Լ�
{
	struct Data *link = DataStart;		//link ����ü ����
	printf("������	����	���ǿ���	���ǻ��	�帣\n");
	printf("-------------------------------------------------\n");
	while (link != NULL)		//link�� NULL���� ���� ������ �ݺ�
	{
		printf("%s %s %s %s %s\n", link->name, link->writer, link->year, link->company, link->genre);
		link = link->NextData;
	}
	printf("-------------------------------------------------\n");
}

int main(void)
{

	struct DataList *DataStart = NULL;		//data����ü �ʱ�ȭ
	DataStart = load(DataStart);		//data�� ������ �ε�
	int sel;
	while (1)
	{
		printf("1.���� �߰� \n");
		printf("2.���� �˻� \n");
		printf("3.���� ���� ���� \n");
		printf("4.���� ���� \n");
		printf("5.���� �� ���� ��� ��� \n");
		printf("6.���� \n");
		printf("7.���α׷� ������(�ڵ�����) \n");
		printf("�Է�: ");
		scanf("%d", &sel);
		printf("\n");
		switch (sel)
		{
		case 1:		//������ �߰��� ���
			DataStart = Add(DataStart);
			break;
		case 2:		//������ �˻��� ���
			DataStart = Search(DataStart);
			break;
		case 3:		//���� ������ ������ ���
			DataStart = Edit(DataStart);
			break;
		case 4:		//������ ������ ���
			DataStart = Delete(DataStart);
			break;
		case 5:		//���� ����� �� ���
			PrintBook(DataStart);
			break;
		case 6:		//������ ������ ���
			DataStart = save(DataStart);
			break;
		case 7:		//���α׷��� ������ ���
			DataStart = save(DataStart);
			return;
			break;
		default:
			printf("�ٽ��Է��ϼ���.\n");
			break;
		}
	}
	return 0;
}