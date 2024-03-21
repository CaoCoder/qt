
#include"List.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = new SListNode;
	newnode->data = x;
	newnode->next = nullptr;
	return newnode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	while (plist->next != NULL)
	{
		cout << plist->next->data << " ";
		plist = plist->next;
	}
	cout << endl;
}

// 单链表尾插
void SListPushBack(SListNode* pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (newnode == NULL)
	{
		cout << "申请空间失败" << endl;
	}
	while ((pplist)->next != NULL)
	{
		(pplist) = (pplist)->next;

	}
	(pplist)->next = newnode;
	
}
// 单链表的尾删
void SListPopBack(SListNode* pplist)
{	
	if (pplist->next == NULL)
	{
		cout << "没有可删的东西" << endl;
		return;
	}
	SListNode* tmp = pplist;
	while (pplist->next != NULL)
	{
		tmp = pplist;
		pplist = pplist->next;
	}
	tmp->next = NULL;

	delete pplist;
	pplist = NULL;

}

// 单链表的头插
void SListPushFront(SListNode* pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* prev = pplist->next;
	SListNode* newnode = BuySListNode(x);
	pplist->next = newnode;
	newnode->next = prev;


}

// 单链表头删
void SListPopFront(SListNode* pplist)
{
	assert(pplist);
	if (pplist->next == NULL)
	{
		cout << "没有节点可以删了" << endl;
		return;
	}
	SListNode* next1 = pplist->next->next;

	delete pplist->next;

	pplist->next = next1;

	
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist->next);
	SListNode* cur = plist->next;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos >= 0);
	SListNode* newnode = BuySListNode(x);
	SListNode* next1 = pos->next;
	pos->next = newnode;
	newnode->next = next1;

}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	if (pos->next == NULL)
	{
		cout << "没有东西可删了";
		return;
	}
	SListNode* next1 = pos->next->next;
	delete pos->next;

	pos->next = next1;

}
//销毁
void SLDestroy(SListNode* pphead)
{
	SListNode* nextnode = NULL;
	SListNode* cur = pphead->next;
	while (cur != NULL)
	{
		nextnode = cur->next;
		delete cur;
		cur = nextnode;
		
	}
	delete pphead;
}
int main()
{

	SListNode* dummy = BuySListNode(0);//创建虚拟头结点
	SListPushFront(dummy, 4);
	SListPushFront(dummy, 3);
	SListPushFront(dummy, 2);
	SListPushFront(dummy, 1); 

	
	//打印
	SListPrint(dummy);
	
	
	SListNode* node = SListFind(dummy, 2);
	if (node != NULL)
	{
		cout << node->data << endl;
		SListEraseAfter(node);
	}
	else
	{
		cout << "没有数据" << endl;
	}

	SListPrint(dummy);


	SLDestroy(dummy);//销毁

	
	return 0;
}

