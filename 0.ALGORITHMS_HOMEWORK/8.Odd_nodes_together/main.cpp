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

//��ż����
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *pre = head, *cur = head->next;  //pre��������λ��cur����ż��λ
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
    cout << "����������" << endl;
    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);p'p'p'p
    ListNode *first = oddEvenList(mlist);
    cout << "������յ�����" ;
    ListNode *p = first;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
