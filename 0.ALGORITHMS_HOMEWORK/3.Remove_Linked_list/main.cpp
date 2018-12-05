/**
* @description:����һ��ֵ��ɾ�����������еĸ�ֵ
* @idea:1.�ݹ�
* @author: ������
* @date: 2018/10/17
**/
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

// ����������
node *creat()
{
	node *head, *p;
	head = new node;
	p = head;

	int x, cycle = 1;
	while (cycle)
	{
		cout << "��������������: ";
		cin >> x;

		if (x != -1)
		{
			node *s = new node;
			s->data = x;
			cout << "��ǰ�����ֵ: " << x << endl;

			p->next = s;
			p = s;
		}
		else
		{
			cycle = 0;
			cout << "�������! " << endl;
		}
	}

	head = head->next;
	p->next = NULL;

	return head;
}

// �������ӡ
void printL(node *head)
{
	node *p = head;

    cout << "�������£�"<<endl;
    if (p != NULL)
    {
        cout << p->data;
        p = p->next;
        while(p != NULL)
        {
            cout << "->" << p->data ;
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "��ǰΪ������" <<endl;
    }
}

// ������ɾ��
node *del(node *head, int data)
{
    node *p = head;
    if (p == NULL) return NULL;
    p->next = del(p->next, data);
    return p->data == data ? p->next : p;
}


int main()
{
	cout << "***����������***" << endl;
	node *head = creat();
	cout << endl;

	cout << "***��ӡ������***" << endl;
	printL(head);
	cout << endl;

	cout << "****ɾ���ڵ�****" << endl;
	cout << "������Ҫɾ����ֵ: ";
	int outData;
	cin >> outData;
	cout << endl;

	cout << "***��ӡɾ����ĵ�����***" << endl;
	head = del(head, outData);
	printL(head);
	cout << endl;

	return 0;
}
