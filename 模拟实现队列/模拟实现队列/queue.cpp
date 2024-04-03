#include <iostream>
#include "queue.h"
#include <assert.h>
using namespace std;

//初始化队列
void QueueInit(Queue* q)
{
	q->_front = new QNode();
	q->_front->_data = 0;
	q->_front->_next = NULL;

	q->_rear = q->_front;//指向同一个位置

}
QNode* buyNewnode(QDataType x)
{
	QNode* newnode = new QNode();
	newnode->_next = NULL;
	newnode->_data = x;

	return newnode;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{	
	QNode* newnode = buyNewnode(data);
	assert(newnode);
	q->_rear->_next = newnode;
	q->_rear = newnode;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	if(q->_front->_next == NULL)
	{
		cout << "队列为空" << endl;
		return -1;
	}
	return q->_front->_next->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		cout << "队列为空" << endl;
		return;
	}
	QNode* tail = q->_front->_next->_next;
	delete q->_front->_next;

	q->_front->_next = tail;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
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

// 销毁队列 
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

	//获取对首元素
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