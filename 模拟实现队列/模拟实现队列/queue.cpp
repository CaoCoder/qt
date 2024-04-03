#include <iostream>
#include "queue.h"
#include <assert.h>
using namespace std;

//��ʼ������
void QueueInit(Queue* q)
{
	q->_front = new QNode();
	q->_front->_data = 0;
	q->_front->_next = NULL;

	q->_rear = q->_front;//ָ��ͬһ��λ��

}
QNode* buyNewnode(QDataType x)
{
	QNode* newnode = new QNode();
	newnode->_next = NULL;
	newnode->_data = x;

	return newnode;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{	
	QNode* newnode = buyNewnode(data);
	assert(newnode);
	q->_rear->_next = newnode;
	q->_rear = newnode;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	if(q->_front->_next == NULL)
	{
		cout << "����Ϊ��" << endl;
		return -1;
	}
	return q->_front->_next->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	QNode* tail = q->_front->_next->_next;
	delete q->_front->_next;

	q->_front->_next = tail;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	int sz = 0;
	QNode* cur = q->_front->_next;
	while (cur != NULL)
	{
		cur = cur->_next;
		sz++;
	}
	return sz;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	while (!QueueEmpty(q))
	{
		QueuePop(q);
	}
	delete q->_front;
	q->_front = nullptr;
}
int main()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 2);
	QueuePush(&q, 1);
	//QueuePop(&q);
	
	//int sz = QueueSize(&q);
	//cout << sz;

	//��ȡ����Ԫ��
	/*int x = QueueFront(&q);
	cout << x << endl;*/

	//int x = QueueBack(&q);
	//cout << x << endl;

	//while (!QueueEmpty(&q))
	//{
	//	int front = QueueFront(&q);
	//	QueuePop(&q);

	//	cout << front  << " ";
	//}
	//cout << endl;

	QueueDestroy(&q);
	return 0;
}