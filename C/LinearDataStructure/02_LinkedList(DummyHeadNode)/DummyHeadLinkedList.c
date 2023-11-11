#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//※ int* p; int를 가리키는 변수 p

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_pHeadNode = NULL;
USERDATA g_HeadNode = { 0, "_DummyHeadNode_" }; //는 무조건 존재한다.

void AddNewNode(int age, const char* pszName, const char* pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	USERDATA* pTail = &g_HeadNode;
	while (pTail->pNext != NULL)
	{
		pTail = pTail->pNext;
	}//Tail찾는다.
	pTail->pNext = pNewNode;
}

void ReleaseList(void)
{
	USERDATA* pTmp = g_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{ //헤드 앞 노드부터 삭제
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete : [%p] %d, %s, %s [%p]\n",
			pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete); //AddNewNode()에서 동적할당된 것 해제해준다.
	}
	g_HeadNode.pNext = NULL;
}

void initDummyData(void)
{
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Choi", "010-2222-2222");
	AddNewNode(12, "Lee", "010-3333-3333");
}

void printList(void)
{
	USERDATA* pTmp = &g_HeadNode;
	while (pTmp != NULL)
	{//헤드노드부터 프린트한다.
		printf("[%p] %d, %s, %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

USERDATA* SearchByName(const char* pszName) //찾은 노드의 주소 반환
{
	USERDATA* pTmp = g_HeadNode.pNext;
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

USERDATA* SearchToRemove(const char* pszName) //찾은 노드의 앞 노드 반환
{
	USERDATA* pPrev = &g_HeadNode;
	while (pPrev->pNext != NULL)
	{
		if (strcmp(pPrev->pNext->name, pszName) == 0)
		{
			return pPrev;
		}
		pPrev = pPrev->pNext;
	}
	return NULL;
}

void RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;
	
	pRemove = pPrev->pNext;
	pPrev->pNext = pRemove->pNext;
	free(pRemove);
}

int main()
{
	//※ int* p; int를 가리키는 변수 p
	//g_pHeadNode는 헤드노드를 가리키는 포인터임을 인지하기

	/*initDummyData();
	printList();
	SearchByName("Hoon");
	SearchByName("Lee");
	SearchByName("Kim");
	SearchByName("Choi");
	ReleaseList();*/

	initDummyData();
	USERDATA* pPrev = SearchToRemove("Lee");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	ReleaseList();
	return 0;
}