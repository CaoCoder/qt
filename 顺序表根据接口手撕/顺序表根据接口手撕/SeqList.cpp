#include "SeqList.h"
#include <iostream>
using namespace std;

void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->size = 0;
	ps->capacity = 30;
	ps->a = (SLDateType*)malloc(ps->capacity * sizeof(SLDateType));

}

void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void CheckCacpity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}
void SeqlListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
		CheckCacpity(ps);

		ps->a[ps->size] = x;
		ps->size++;

}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = ps->size - 1; i >= 0 ; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;

}

void SeqListPopFront(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];

	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	ps->size--;
}


// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			printf("%d �ҵ���", ps->a[i]);
			return 1;
		}

	}
	printf("û�ҵ�");
	return 0;
}

void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		cout << ps->a[i] << ",";
	}
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos)
{
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];

	}
	ps->size--;
}
int main()
{
	SeqList se; // ����Ҫʹ��ָ�룬ֱ�Ӵ��� SeqList ����
	SeqListInit(&se); // ���ݽṹ��ĵ�ַ����ʼ������

	SeqlListPushBack(&se, 3); // ���Ԫ��ʱ��Ҫ���ݽṹ��ĵ�ַ
	SeqlListPushBack(&se, 2);
	SeqlListPushBack(&se, 1);



	SeqListPushFront(&se, 2);
	SeqListPushFront(&se, 3);
	SeqListPushFront(&se, 4);
	SeqListInsert(&se, 3, 8);
	SeqListErase(&se, 3);
	//SeqListPopBack(&se);





	//SeqListFind(&se, 1);

	SeqListPrint(&se); // ��ӡʱҲ��Ҫ���ݽṹ��ĵ�ַ
	SeqListDestory(&se); // ����ʱ���ݽṹ��ĵ�ַ

	return 0;
}
