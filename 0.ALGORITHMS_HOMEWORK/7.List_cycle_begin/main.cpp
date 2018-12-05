#include <iostream>

using namespace std;

//定义链表节点结构体
struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域

    //构造函数
    ListNode(int data): val(data), next(NULL) {}
};

//创建循环链表
ListNode* cteateList(ListNode *head)
{
    ListNode *p = head;

    int value[5]={1,3,4,5,6};
    int i=0;
    while(value[i]!=NULL)
    {
        ListNode *newnode = new ListNode(value[i]);
        p->next = newnode;
        p = p->next;
        i=i+1;
    }
    p->next = head->next;
    p = p->next;

    return head->next;
}

//查找链表循环的开始节点
ListNode *detectCycle(ListNode *head)
{
   if (head == NULL) return NULL;
   ListNode *slow = head, *fast = head;
   while (slow != NULL && fast != NULL)
   {
       if (slow->next != NULL) //检测慢指针的结束节点
       {
          slow = slow->next;
       }
       else
       {
          return NULL;
       }
       if (fast->next != NULL) //检测快指针的结束节点,走第一步
       {
          fast = fast->next;
       }
       else
       {
          return NULL;
       }
       if (fast->next != NULL) //检测快指针的结束节点，走第二步
       {
          fast = fast->next;
       }
       else
       {
          return NULL;
       }
       if (slow == fast)  //快指针和慢指针相遇的时候结束循环
       {
          break;
       }
    }
    slow = head;  //从头节点开始和相遇点开始移动，直到相遇就是循环开始的地方
    while (slow != fast)
    {
         slow = slow->next;
         fast = fast->next;
    }
    return slow;
}

int main()
{
    cout << "建立循环链表" << endl;
    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);
    ListNode *first = detectCycle(mlist);
    if (first->val == NULL)
        cout << "不存在循环链表" << endl;
    else
        cout << "循环开始节点的元素值为：" << first->val << endl;

    return 0;
}
