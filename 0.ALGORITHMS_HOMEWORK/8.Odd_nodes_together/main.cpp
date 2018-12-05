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

//创建单链表
ListNode* cteateList(ListNode *head)
{
    ListNode *p = head;

    cout << "请输入单链表的元素值："  << endl;

    int value;
    while(cin >> value)
    {
        ListNode *newnode = new ListNode(value);
        p->next = newnode;
        p = p->next;

        if(cin.get() == '\n')
            break;
    }

    return head->next;
}

//奇偶链表
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *pre = head, *cur = head->next;  //pre保存奇数位，cur保存偶数位
    while (cur && cur->next) {
        ListNode *tmp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = tmp;
        cur = cur->next;
        pre = pre->next;
    }
    return head;
}

int main()
{
    cout << "建立单链表" << endl;
    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);p'p'p'p
    ListNode *first = oddEvenList(mlist);
    cout << "输出最终的链表：" ;
    ListNode *p = first;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
