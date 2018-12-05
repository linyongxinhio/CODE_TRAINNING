/**
* @description:输入一个值，删除链表中所有的该值
* @idea:1.递归
* @author: 林永欣
* @date: 2018/10/17
**/
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

// 创建单链表
node *creat()
{
	node *head, *p;
	head = new node;
	p = head;

	int x, cycle = 1;
	while (cycle)
	{
		cout << "请输入链表数据: ";
		cin >> x;

		if (x != -1)
		{
			node *s = new node;
			s->data = x;
			cout << "当前输入的值: " << x << endl;

			p->next = s;
			p = s;
		}
		else
		{
			cycle = 0;
			cout << "输入完毕! " << endl;
		}
	}

	head = head->next;
	p->next = NULL;

	return head;
}

// 单链表打印
void printL(node *head)
{
	node *p = head;

    cout << "链表如下："<<endl;
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
        cout << "当前为空链表" <<endl;
    }
}

// 单链表删除
node *del(node *head, int data)
{
    node *p = head;
    if (p == NULL) return NULL;
    p->next = del(p->next, data);
    return p->data == data ? p->next : p;
}


int main()
{
	cout << "***创建单链表***" << endl;
	node *head = creat();
	cout << endl;

	cout << "***打印单链表***" << endl;
	printL(head);
	cout << endl;

	cout << "****删除节点****" << endl;
	cout << "请输入要删除的值: ";
	int outData;
	cin >> outData;
	cout << endl;

	cout << "***打印删除后的单链表***" << endl;
	head = del(head, outData);
	printL(head);
	cout << endl;

	return 0;
}
