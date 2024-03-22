#include "list.h"
#include <iostream>
#include <assert.h>
using namespace std;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
    ListNode* newnode = new ListNode();
    newnode->_next = newnode;
    newnode->_prev = newnode;
    newnode->_data = 0;

    return newnode;
}
// 创建普通结点
ListNode* buyNewnode(int x)
{
    ListNode* newnode = new ListNode();
    newnode->_next = NULL;
    newnode->_prev = NULL;
    newnode->_data = x;

    return newnode;
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* newnode = buyNewnode(x);
    ListNode* pre = pHead->_prev;
    pre->_next = newnode;
    newnode->_prev = pre;
    newnode->_next = pHead;
    pHead->_prev = newnode;

    
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{   
    ListNode* cur = pHead;
    assert(pHead);
    while(pHead->_next != cur)
    {
        cout <<  pHead->_next->_data << " ";
         pHead =  pHead->_next;
    }
    cout << endl;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
    ListNode* cur = pHead->_next;
    if(pHead->_prev == pHead)
    {
        cout << "没有可以销毁的了" << endl;
        return;
    }
    //注意循环条件
    while(cur!= pHead)
    {
        ListNode* tail = pHead->_prev->_prev;

        delete pHead->_prev;

        tail->_next = pHead;
        pHead->_prev = tail;

        cur = pHead->_next;//迭代
    }
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
    if(pHead->_next == pHead)
    {
        cout<< "没有结点可删了" <<endl;
        return;
    }
    ListNode* pre = pHead->_prev->_prev;

    delete pHead->_prev;
    pre->_next = pHead;
    pHead->_prev = pre;

}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
    ListNode* newnode = buyNewnode(x);
    assert(newnode);
    ListNode* tail = pHead->_next;

    pHead->_next = newnode;
    newnode->_prev = pHead;
    newnode->_next = tail;
    tail->_prev = newnode;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
    if(pHead->_next == pHead)
    {
        cout << "不能再删了" << endl;
        return;
    }
    ListNode* tail = pHead->_next->_next;

    delete pHead->_next;

    pHead->_next = tail;
    tail->_prev = pHead;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    if(pHead->_next == pHead)
    {
        cout << "链表为NULL" << endl;
        return NULL;
    }
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        if(cur->_data == x)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* newnode = buyNewnode(x);
    assert(newnode);
    ListNode* pre = pos->_prev;

    pre->_next = newnode;
    newnode->_prev = pre;
    newnode->_next = pos;
    pos->_prev = newnode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* tail = pos->_next;
    ListNode* pre = pos->_prev;
    delete pos;
    pre->_next =tail;
    tail->_prev = pre;
}

int main()
{
    ListNode* dummy = ListCreate();
    if(dummy ==  NULL)
    {
        cout << "申请虚拟头节点失败" << endl;
    }

       
     ListPushFront(dummy, 3);
    ListPushFront(dummy, 2);
    ListPushFront(dummy, 1);
    ListPrint(dummy);
    //  ListPopFront(dummy);
    
   ListNode* node = ListFind(dummy, 1);
   if(node != NULL)
   {
        ListErase(node);
   }
   else
   {
    cout << "找不到" << endl;
   }
   


    ListPrint(dummy);

    ListDestory(dummy);
    
    delete dummy;
    return 0;
}