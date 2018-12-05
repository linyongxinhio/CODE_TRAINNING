#include <iostream>
#include <stdlib.h>

using namespace std;

//��������ڵ�ṹ��
struct ListNode{
    int val; //������
    ListNode *next; //ָ����

    //���캯��
    ListNode(int data): val(data), next(NULL) {}
};

//����������
ListNode* cteateList(ListNode *head)
{
    ListNode *p = head;

    cout << "�����뵥�����Ԫ��ֵ��"  << endl;

    int value;
    while(cin >> value){
        ListNode *newnode = new ListNode(value);
        p->next = newnode;
        p = p->next;

        if(cin.get() == '\n')
            break;
    }

    return head->next;
}

//������������ĺϲ�
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //��һΪ��
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    /*
    ListNode* newHead = ListNode(0);   // �����ϲ��������ͷ�ڵ�
    ListNode* p = newHead;
    */

   if(l1->val <= l2->val){
       ListNode *newlist = l1;
       newlist->next = mergeTwoLists(l1->next, l2);  // ���жϵĹ����н���������
       return newlist;
   }else{
       ListNode *newlist = l2;
       newlist->next = mergeTwoLists(l1, l2->next);
       return newlist;
   }
}

int main()
{
    cout << "������һ��������" << endl;
    ListNode *head1 = new ListNode(0);
    ListNode *l1 = cteateList(head1);

    cout << "�����ڶ���������" << endl;
    ListNode *head2 = new ListNode(0);
    ListNode *l2 = cteateList(head2);

    ListNode *newlist = mergeTwoLists(l1, l2);

    cout << "�ϲ���ĵ�����Ϊ��" << endl;
    ListNode *p = newlist;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
