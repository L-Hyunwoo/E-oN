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

struct Data* load(struct Data *DataStart)		//파일 로딩 구조체
{
	struct Data *loop = DataStart;

	FILE *ifile = fopen("input.txt", "r");		//파일 불러오기

	if (ifile == NULL)		//파일이 없으면 종료
	{
		printf("파일 로딩 실패\n");
		exit(1);
	}

	char db[5][100];		//데이터를 받을 배열 설정

	while (!feof(ifile))		//파일의 끝에 도달할 때까지 반복
	{
		fscanf(ifile, "%s %s %s %s %s", db[0], db[1], db[2], db[3], db[4]);		//파일의 데이터를 변수에 저장
		char *out[5];
		for (int i = 0; i < 5; i++)
		{
			out[i] = malloc(sizeof(char) * (strlen(db[i])));		//데이터를 동적할당후 저장
			strcpy(out[i], db[i]);		//db를 out에 복사
		}

		struct Data *NewData = malloc(sizeof(struct Data) * 1);			//newdata에 data의 크기만큼 동적할당
		NewData->name = out[0];			//도서명을 newdata에 저장
		NewData->writer = out[1];		//저자를 newdata에 저장
		NewData->year = out[2];			//발행연도를 newdata에 저장
		NewData->company = out[3];		//출판사를 newdata에 저장
		NewData->genre = out[4];		//장르를 newdata에 저장
		NewData->NextData = NULL;		//다음 데이터에 NULL값 저장

		if (DataStart == NULL)		//data가 없으면
		{
			DataStart = NewData;	//newdata를 data에 저장
			loop = DataStart;		//data를 loop에 저장
		}
		else
		{
			loop->NextData = NewData;		//다음 데이터에 newdata 저장
			loop = loop->NextData;		//loop는 다음 데이터를 저장
		}
	}
	fclose(ifile);		//file을 닫음
	return DataStart;		//data값 저장
}

struct Data* save(struct Data *print)		//파일 저장 함수
{
	FILE *ofile = fopen("input.txt", "w");

	if (ofile == NULL)
	{
		printf("파일 로딩 실패\n");
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

int PrintBook(struct Data *DataStart);		//출력함수를 거쳐감

char* String()		//입력받은 변수를 크기만큼 동적할당
{
	char db[100];
	scanf("%s", db);
	char *out = malloc(sizeof(char) * (strlen(db)));
	strcpy(out, db);
	return out;
}

struct Data* Add(struct Data *DataStart)		//도서 추가 구조체
{
	struct Data* link = DataStart;		//link에 data값 입력

	printf("추가할 도서를 입력하세요. \n");
	printf("(도서명 저자 출판연도 출판사명 장르 순으로 입력)\n");
	struct Data *NewData = malloc(sizeof(struct Data) * 1);		//newdata에 data크기만큼 동적할당
	NewData->name = String();		//도서명을 입력받고 저장
	NewData->writer = String();		//저자를 입력받고 저장
	NewData->year = String();		//발행연도를 입력받고 저장
	NewData->company = String();	//출판사를 입력받고 저장
	NewData->genre = String();		//장르를 입력받고 저장
	NewData->NextData = NULL;		//다음 데이터에 NULL값을 입력

	if (DataStart == NULL)		//data가 NULL값이면 newdata 입력
		DataStart = NewData;
	else
	{
		while (link->NextData != NULL)		//다음데이터가 NULL값일때까지 반복
			link = link->NextData;		//link에 다음데이터 저장
		
		link->NextData = NewData;		//다음 데이터에 newdata 저장
	}

	return DataStart;
}

struct Data* SearchNode(struct Data *test, char *put)		//도서 검색 구조체
{
	if (test == NULL)		//파일에 저장된 도서가 없으면 종료
		return NULL;
	else
	{
		while (test != NULL)		//test가 NULL값일 때까지 반복
		{
			if (strstr(test->name, put) != NULL)		//검색한 단어가 도서명에 포함될 때
				return test;
			else if (strstr(test->writer, put) != NULL)		//검색한 단어가 저자에 포함될 때
				return test;
			else if (strstr(test->year, put) != NULL)		//검색한 단어가 발행연도에 포함될 때
				return test;
			else if (strstr(test->company, put) != NULL)		//검색한 단어가 출판사에 포함될 때
				return test;
			else if (strstr(test->genre, put) != NULL)		//검색한 단어가 장르에 포함될 때
				return test;
			else
				test = test->NextData;		//나머지의 경우 다음 데이터로 넘어감
		}
		return NULL;
	}
}

struct Data* Search(struct DataList *link)		//도서검색 함수
{
	printf("키워드를 입력해주세요. : ");
	char *put = String();		//키워드 입력
	
	struct Data *print;		//print 구조체 선언
	while (link != NULL)		//link가 NULL값일 때까지 반복
	{
		print = SearchNode(link, put);		//도서검색구조체로 이동

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

struct Data* Edit(struct Data *DataStart)		//도서 정보 수정 함수
{
	if (DataStart == NULL)		//수정할 데이터가 없을 경우 종료
		return;

	PrintBook(DataStart);		//도서 목록 출력

	struct Data* test = DataStart;		//test 구조체 선언
	while (1)
	{
		printf("\n수정할 도서명을 정확히 입력하세요:");
		char *edit = String();		//도서명 입력

		while (test != NULL)		//test가 NULL값이 될 때까지 반복
		{
			if (strcmp(test->name, edit) == 0)		//입력받은 도서명과 일치하는 도서에서 정지
				break;
			else
				test = test->NextData;
		}
		if (test == NULL)	//test가 NULL값인 경우
		{
			test = DataStart;		//test에 data 저장
			printf("검색된 도서명이 없습니다.\n");
		}
		else
			break;
	}

	printf("수정할 목록을 선택하세요. \n");
	printf("1. 도서명\n");
	printf("2. 저자\n");
	printf("3. 출판연도\n");
	printf("4. 출판사명\n");
	printf("5. 장르\n");
	int num;
	while (1)
	{
		scanf("%d", &num);
		switch (num)
		{
		case 1:		//도서명을 변경하고자 할 때
			printf("변경할 도서명 입력 : ");
			test->name = String();
			break;
		case 2:		//저자를 변경하고자 할 때
			printf("변경할 저자 입력 : ");
			test->writer = String();
			break;
		case 3:		//출판연도를 변경하고자 할 때
			printf("변경할 출판연도 입력 : ");
			test->year = String();
			break;
		case 4:		//출판사명을 변경하고자 할 때
			printf("변경할 출판사명 입력 : ");
			test->company = String();
			break;
		case 5:		//장르를 변경하고자 할 때
			printf("변경할 장르 입력 : ");
			test->genre = String();
			break;
		default:
			printf("잘못된 입력입니다. 다시입력하세요:");
			continue;
			break;
		}
		break;
	}
	printf("정보 수정 결과 : %s %s %s %s %s\n", test->name, test->writer, test->year, test->company, test->genre);
	printf("----------------------------------------------\n");
}

struct Data* Delete(struct Data *DataStart)		//도서 정보 삭제 구조체
{
	PrintBook(DataStart);		//도서 목록 출력

	struct Data* test = DataStart;		//test 구조체 선언

	while (1)
	{
		printf("\n삭제할 도서명을 정확히 입력하세요:");
		char *del = String();		//삭제할 도서명 입력
		while (test != NULL)
		{
			if (strcmp(test->name, del) == 0)		//입력받은 도서명과 일치하는 도서에서 정지
				break;
			else
				test = test->NextData;
		}
		if (test == NULL)
		{
			test = DataStart;
			printf("검색된 도서명이 없습니다.\n");
		}
		else
			break;
	}

	struct Data* loop = DataStart;		//loop 구조체 선언
	if (test == DataStart)		//test가 data와 같을 때
	{
		DataStart = DataStart->NextData;		//data를 다음 데이터로 저장
		free(test);		//test 초기화
	}
	else
	{
		while (loop != NULL)		//loop가 NULL값이 나올 때까지 반복
		{
			if (loop->NextData == test)		//다음데이터가 test와 같을 때 종료
				break;
			else
				loop = loop->NextData;		//loop에 다음데이터 저장
		}
		loop->NextData = test->NextData;
		free(test);		//test 초기화
	}
	printf("삭제가 완료되었습니다.\n");
	return DataStart;
}

int PrintBook(struct Data *DataStart)		//도서 목록 출력 함수
{
	struct Data *link = DataStart;		//link 구조체 선언
	printf("도서명	저자	출판연도	출판사명	장르\n");
	printf("-------------------------------------------------\n");
	while (link != NULL)		//link가 NULL값이 나올 때까지 반복
	{
		printf("%s %s %s %s %s\n", link->name, link->writer, link->year, link->company, link->genre);
		link = link->NextData;
	}
	printf("-------------------------------------------------\n");
}

int main(void)
{

	struct DataList *DataStart = NULL;		//data구조체 초기화
	DataStart = load(DataStart);		//data에 파일을 로딩
	int sel;
	while (1)
	{
		printf("1.도서 추가 \n");
		printf("2.도서 검색 \n");
		printf("3.도서 정보 수정 \n");
		printf("4.도서 삭제 \n");
		printf("5.현재 총 도서 목록 출력 \n");
		printf("6.저장 \n");
		printf("7.프로그램 나가기(자동저장) \n");
		printf("입력: ");
		scanf("%d", &sel);
		printf("\n");
		switch (sel)
		{
		case 1:		//도서를 추가할 경우
			DataStart = Add(DataStart);
			break;
		case 2:		//도서를 검색할 경우
			DataStart = Search(DataStart);
			break;
		case 3:		//도서 정보를 수정할 경우
			DataStart = Edit(DataStart);
			break;
		case 4:		//도서를 삭제할 경우
			DataStart = Delete(DataStart);
			break;
		case 5:		//도서 목록을 볼 경우
			PrintBook(DataStart);
			break;
		case 6:		//도서를 저장할 경우
			DataStart = save(DataStart);
			break;
		case 7:		//프로그램을 종료할 경우
			DataStart = save(DataStart);
			return;
			break;
		default:
			printf("다시입력하세요.\n");
			break;
		}
	}
	return 0;
}