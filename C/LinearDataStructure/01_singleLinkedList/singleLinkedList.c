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
		g_pHeadNode = pNewNode;//�� ����Ű�³��� �ʵ� �����Ѷ�
	else
	{
		//���1
		//�߰��Ǵ� ��尡 ù ��尡��
		//pNewNode->pNext = g_pHeadNode;//�� ����Ű�³��� �ʵ� �����Ѷ�
		//g_pHeadNode = pNewNode;


		//���2
		//Tail�� ã�Ƽ� ���Ḯ��Ʈ�� ���� �߰���
		USERDATA* pTail = g_pHeadNode;
		while (pTail->pNext != NULL)
		{
			pTail = pTail->pNext;
		}//Tailã�´�.
		pTail->pNext = pNewNode;
	}
}

void ReleaseList(void)
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{ //��� �� ������ ����
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete : [%p] %d, %s, %s [%p]\n",
			pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete); //AddNewNode()���� �����Ҵ�� �� �������ش�.
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
	{//�������� ����Ʈ�Ѵ�.
		printf("[%p] %d, %s, %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

USERDATA* SearchByName(const char* pszName) //ã�� ����� �ּ� ��ȯ
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