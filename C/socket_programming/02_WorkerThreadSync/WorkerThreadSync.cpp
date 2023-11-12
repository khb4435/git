// WorkerThreadSync.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <Windows.h>

//�۾��� ������ �Լ�.
DWORD WINAPI ThreadFunction(LPVOID pParam)
{
	puts("*** Begin Thread ****");
	for (int i = 0; i < 5; ++i)
	{
		printf("[Worker thread] %d\n", i);
		::Sleep(1);
	}

	//�����尡 ������ ���� �̺�Ʈ�� ��Ʈ�Ѵ�.
	puts("���� �̺�Ʈ ��Ʈ ��");
	//�� �Լ��� ȣ���ϸ� _tmain() �Լ���
	//WaitForSingleObject() �Լ��� ��ȯ�Ѵ�!
	::SetEvent((HANDLE)pParam);
	puts("���� �̺�Ʈ ��Ʈ ��");
	puts("**** End Thread ****");
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//�̺�Ʈ ��ü(kernel object)�� �����Ѵ�. //���������� �ñ׳�
	HANDLE hEvent = ::CreateEvent(
		NULL,	//����Ʈ ���� �Ӽ� ����.
		FALSE,	//�ڵ����� ���� ��ȯ.
		FALSE,	//�ʱ���´� FALSE.
		NULL);	//�̸� ����.

	//���� �����尡 �۾��� �����带 �����ϰ� �����Ѵ�.
	DWORD dwThreadID = 0;
	HANDLE hThread = ::CreateThread(
		NULL,		//���ȼӼ� ���
		0,			//���� �޸𸮴� �⺻ũ�� (1MB) 
		ThreadFunction, //������� ������ �Լ��̸�
		hEvent,		//�̺�Ʈ �ڵ��� ������ �Լ��� �����Ѵ�.
		0,			//���� �÷��״� �⺻�� ��� 
		&dwThreadID); //������ ������ID ����

	//�۾��� ������� ���ÿ� ����Ǵ� �ڵ� ������ ����.
	for (int i = 0; i < 5; ++i)
	{
		printf("[Main thread] %d\n", i);
		//i���� 3�̸� �̺�Ʈ�� ��Ʈ�Ǳ⸦ ������ ��ٸ���!
		if (i == 3 &&
			::WaitForSingleObject(hEvent, INFINITE) == WAIT_OBJECT_0)
		{
			puts("���� �̺�Ʈ�� �����߽��ϴ�!");
			::CloseHandle(hEvent);
			hEvent = NULL;
		}
	}

	::CloseHandle(hThread);
	return 0;
}
