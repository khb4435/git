#include "list.h"
#include <stdlib.h>

void InitDummyData(void)
{
	//Input
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Choi", "010-2222-2222");
	AddNewNode(13, "Jang", "010-3333-3333");
}

void TestStep01(void)
{
	puts("TestStep01()----------------------------");
	AddNewNode(10, "Choi", "010-2222-2222");
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(13, "Jang", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Choi");
	if (pPrev != NULL)
		RemoveNode(pPrev);

	PrintListReverse();
	ReleaseList();
	putchar('\n');
}

void TestStep02(void)
{
	puts("TestStep02()----------------------------");
	AddNewNode(10, "Choi", "010-2222-2222");
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(13, "Jang", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Hoon");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	ReleaseList();
	putchar('\n');
}

void TestStep03(void)
{
	puts("TestStep03()----------------------------");
	AddNewNode(10, "Choi", "010-2222-2222");
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(13, "Jang", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Jang");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	ReleaseList();
	putchar('\n');
}