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

//����ѭ������
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

//��������ѭ���Ŀ�ʼ�ڵ�
ListNode *detectCycle(ListNode *head)
{
   if (head == NULL) return NULL;
   ListNode *slow = head, *fast = head;
   while (slow != NULL && fast != NULL)
   {
       if (slow->next != NULL) //�����ָ��Ľ����ڵ�
       {
          slow = slow->next;
       }
       else
       {
          return NULL;
       }
       if (fast->next != NULL) //����ָ��Ľ����ڵ�,�ߵ�һ��
       {
          fast = fast->next;
       }
       else
       {
          return NULL;
       }
       if (fast->next != NULL) //����ָ��Ľ����ڵ㣬�ߵڶ���
       {
          fast = fast->next;
       }
       else
       {
          return NULL;
       }
       if (slow == fast)  //��ָ�����ָ��������ʱ�����ѭ��
       {
          break;
       }
    }
    slow = head;  //��ͷ�ڵ㿪ʼ�������㿪ʼ�ƶ���ֱ����������ѭ����ʼ�ĵط�
    while (slow != fast)
    {
         slow = slow->next;
         fast = fast->next;
    }
    return slow;
}

int main()
{
    cout << "����ѭ������" << endl;
    ListNode *head = new ListNode(0);
    ListNode *mlist = cteateList(head);
    ListNode *first = detectCycle(mlist);
    if (first->val == NULL)
        cout << "������ѭ������" << endl;
    else
        cout << "ѭ����ʼ�ڵ��Ԫ��ֵΪ��" << first->val << endl;

    return 0;
}
