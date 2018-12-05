#include <iostream>

using namespace std;

//��������ڵ�ṹ��
struct ListNode
{
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

//�ҵ��м�ڵ�
ListNode* middleNode(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    ListNode* slow=head;  //��ָ��һ����һ��
    ListNode* fast=head;  //��ָ��һ��������

    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->next;  // ָ���м�ڵ�
}

int main()
{
    cout << "����������" << endl;

    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);

    ListNode *middle = middleNode(mlist);
    cout << "�м�ڵ��е�Ԫ��ֵΪ��" << middle->val << endl;
    cout << "�м�ڵ㼰����ֵΪ��" ;
    ListNode *p = middle;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
