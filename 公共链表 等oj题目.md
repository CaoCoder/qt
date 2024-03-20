#  公共链表 等oj题目

##  公共链表

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
            ListNode* tmp1 = headA;
            ListNode* tmp2 = headB;
            //先算出相差了多少，让两个链表同时起步遍历
            int t1 = 0;
            int t2 = 0;
            while(tmp1 != NULL)
            {
                tmp1 = tmp1->next;
                ++t1;
            }
            while(tmp2 != NULL)
            {
                tmp2 = tmp2->next;
                ++t2;
            }
            int res = 0;
            
            ListNode* cur = NULL;
            ListNode* cur1 = NULL;
            if(t2 > t1)
            {
                res = t2 - t1;
                cur = headB;
                cur1 = headA;
            }
            else
            {
                res = t1 - t2;
                cur  = headA;
                cur1 = headB;
            }
            while(res > 0)
            {
                cur = cur->next;
                res--;
            }
            //同时起步
            ListNode* result = NULL;
             while(cur != NULL && cur1 != NULL)
             {
                 if(cur != cur1)
                 {
                    cur = cur->next;
                    cur1 = cur1->next;
                 }
                 else
                 {
                    result = cur;
                    break;
                 }
             }
             if(result == NULL)
             {
                return NULL;
             }
           
             return result;
         

    }
};
```

##  环形链表2

用unordered_map哈希表，直接秒杀。

因为哈希表只允许key出现一次，value可以无限叠加，只要检测到value增加了，就说明第一次进入环了。此时返回这个结点即可。

```c++
#include <unordered_map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        int c = 0;
        unordered_map<ListNode*, int> nodemap;
        ListNode* cur = head;
        while(cur != NULL)
        {
            nodemap[cur]++;
            if(nodemap[cur] > 1)
            {
                return cur;
                break;
            }
            cur = cur->next;

        }
        return NULL;

    }
};
```

##  环形链表(双指针法 空间位O(1))

双指针法，虽然空间复杂度为O(1)，但是很多空指针要注意，

一定要注意空指针，边界条件。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
            if(head == NULL)
            {
                return false;
            }
            ListNode* slow = head;
            ListNode* fast = head;
            
            if(fast->next == NULL)
            {
                return false;
            }
            else
            {
                fast = fast->next->next;
            }
            while(slow != NULL && fast != NULL)
            {
                if(slow == fast)
                {
                    return true;
                }
                slow = slow->next;
                if(fast->next != NULL)
                {
                fast = fast->next->next;

                }
                else
                {
                    return false;
                }
                
            }
            return false;
    }
};
```

##  复制带随机链表的指针(哈希表)

以下是将给定的代码从 Java 转换为 C++ 的版本：

```c++
cpp
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* cur = head;
        std::unordered_map<Node*, Node*> map;

        // First pass: 将原来结点 和 新创建的结点 联系起来。
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Second pass: 连接next和random
        cur = head;
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};
```