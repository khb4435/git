#pragma once
//헤더파일엔 선언온다.
typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pPrev;
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_pHeadNode = NULL;
USERDATA g_HeadNode;
USERDATA g_TailNode;

void AddNewNode(int age, const char* pszName, const char* pszPhone);
void InitList(void);
void ReleaseList(void);
int IsEmpty(void);
void Push(USERDATA* pUser);
USERDATA* Pop();
USERDATA* Dequeue(void);
void Enqueue(USERDATA* pUser);
USERDATA* SearchByName(const char* pszName);
void RemoveNode(USERDATA* pRemove);