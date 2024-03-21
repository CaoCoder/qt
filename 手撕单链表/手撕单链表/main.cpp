
#include"List.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = new SListNode;
	newnode->data = x;
	newnode->next = nullptr;
	return newnode;
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	while (plist->next != NULL)
	{
		cout << plist->next->data << " ";
		plist = plist->next;
	}
	cout << endl;
}

// ������β��
void SListPushBack(SListNode* pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (newnode == NULL)
	{
		cout << "����ռ�ʧ��" << endl;
	}
	while ((pplist)->next != NULL)
	{
		(pplist) = (pplist)->next;

	}
	(pplist)->next = newnode;
	
}
// �������βɾ
void SListPopBack(SListNode* pplist)
{	
	if (pplist->next == NULL)
	{
		cout << "û�п�ɾ�Ķ���" << endl;
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

// �������ͷ��
void SListPushFront(SListNode* pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* prev = pplist->next;
	SListNode* newnode = BuySListNode(x);
	pplist->next = newnode;
	newnode->next = prev;


}

// ������ͷɾ
void SListPopFront(SListNode* pplist)
{
	assert(pplist);
	if (pplist->next == NULL)
	{
		cout << "û�нڵ����ɾ��" << endl;
		return;
	}
	SListNode* next1 = pplist->next->next;

	delete pplist->next;

	pplist->next = next1;

	
}
// ���������
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos >= 0);
	SListNode* newnode = BuySListNode(x);
	SListNode* next1 = pos->next;
	pos->next = newnode;
	newnode->next = next1;

}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	if (pos->next == NULL)
	{
		cout << "û�ж�����ɾ��";
		return;
	}
	SListNode* next1 = pos->next->next;
	delete pos->next;

	pos->next = next1;

}
//����
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

	SListNode* dummy = BuySListNode(0);//��������ͷ���
	SListPushFront(dummy, 4);
	SListPushFront(dummy, 3);
	SListPushFront(dummy, 2);
	SListPushFront(dummy, 1); 

	
	//��ӡ
	SListPrint(dummy);
	
	
	SListNode* node = SListFind(dummy, 2);
	if (node != NULL)
	{
		cout << node->data << endl;
		SListEraseAfter(node);
	}
	else
	{
		cout << "û������" << endl;
	}

	SListPrint(dummy);


	SLDestroy(dummy);//����

	
	return 0;
}

