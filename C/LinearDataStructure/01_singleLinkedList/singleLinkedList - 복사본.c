#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

USERDATA* g_pHeadNode = NULL;

void AddNewNode(int age, const char* pszName, const char* pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	if (g_pHeadNode == NULL)
		g_pHeadNode = pNewNode;//가 가리키는놈을 너도 가리켜라
	else
	{
		//방법1
		//추가되는 노드가 첫 노드가됨
		//pNewNode->pNext = g_pHeadNode;//가 가리키는놈을 너도 가리켜라
		//g_pHeadNode = pNewNode;


		//방법2
		//Tail을 찾아서 연결리스트의 끝에 추가함
		USERDATA* pTail = g_pHeadNode;
		while (pTail->pNext != NULL)
		{
			pTail = pTail->pNext;
		}//Tail찾는다.
		pTail->pNext = pNewNode;
	}
}

void ReleaseList(void)
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{ //헤드 앞 노드부터 삭제
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete : [%p] %d, %s, %s [%p]\n",
			pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete); //AddNewNode()에서 동적할당된 것 해제해준다.
	}
	g_pHeadNode = NULL;
}

void initDummyData(void)
{
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Choi", "010-2222-2222");
	AddNewNode(12, "Lee", "010-3333-3333");
}

void printList(void)
{
	USERDATA* pTmp = g_pHeadNode;
	while (pTmp != NULL)
	{//헤드노드부터 프린트한다.
		printf("[%p] %d, %s, %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

USERDATA* SearchByName(const char* pszName) //찾은 노드의 주소 반환
{
	USERDATA* pTmp = g_pHeadNode;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->name, pszName) == 0)
		{
			printf("found\n");
			return pTmp;
		}
		pTmp = pTmp->pNext;
	}
	printf("not found\n");
	return NULL;
}

int main()
{
	initDummyData();
	printList();
	SearchByName("Hoon");
	SearchByName("Lee");
	SearchByName("Kim");
	SearchByName("Choi");
	ReleaseList();
	return 0;
}