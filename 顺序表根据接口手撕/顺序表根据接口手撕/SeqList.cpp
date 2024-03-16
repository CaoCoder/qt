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


// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			printf("%d 找到了", ps->a[i]);
			return 1;
		}

	}
	printf("没找到");
	return 0;
}

void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		cout << ps->a[i] << ",";
	}
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
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
	SeqList se; // 不需要使用指针，直接创建 SeqList 对象
	SeqListInit(&se); // 传递结构体的地址给初始化函数

	SeqlListPushBack(&se, 3); // 添加元素时需要传递结构体的地址
	SeqlListPushBack(&se, 2);
	SeqlListPushBack(&se, 1);



	SeqListPushFront(&se, 2);
	SeqListPushFront(&se, 3);
	SeqListPushFront(&se, 4);
	SeqListInsert(&se, 3, 8);
	SeqListErase(&se, 3);
	//SeqListPopBack(&se);





	//SeqListFind(&se, 1);

	SeqListPrint(&se); // 打印时也需要传递结构体的地址
	SeqListDestory(&se); // 销毁时传递结构体的地址

	return 0;
}
