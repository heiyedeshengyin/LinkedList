#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;

struct Node	//节点
{
	int val;	//节点的值
	Node *next;	//下一个节点的指针
	Node()
	{
		val = 0;
		next = NULL;
	}
};

class LinkedList	//单链表
{
private:
	Node *head;	//头节点
public:
	LinkedList();	//默认构造函数
	LinkedList(int _val);	//构造函数
	~LinkedList();	//析构函数
	void creatList(int length);	//输入链表
	void show();	//显示链表
	void addAtHead(int _cur);	//插入新的头结点
	void addAtTail(int _cur);	//插入新的尾节点
	void addAtIndex(int _index, int _val);	//在第index处插入新节点
	void deleteAtIndex(int _index);	//删除第index处的节点
	void reverseList();		//反转链表
	int getLength();	//返回链表的长度
	int getHead();	//返回头节点
	int getTail();	//返回尾节点
	int get(int _index);	//返回第index处的节点
};

LinkedList::LinkedList()	//默认构造函数
{
	head = NULL;
}

LinkedList::LinkedList(int _val)	//构造函数
{
	head = new Node;
	head->val = _val;
}

LinkedList::~LinkedList()	//析构函数
{
	Node *p;
	p = head;
	while (p)
	{
		p = p->next;
		delete head;
		head = p;
	}
	p = NULL;
}

void LinkedList::creatList(int length)	//输入链表
{
	head = new Node;
	int *n;
	n = new int[length];
	for (int i = 0; i < length; i++)
		cin >> n[i];
	int j = 0;
	head->val = n[j];
	for (int j = 1; j < length; j++)
		this->addAtTail(n[j]);
}

void LinkedList::show()	//显示链表
{
	int i = 0;
	for (i = 0; i < this->getLength() - 1; i++)
		cout << this->get(i) << " -> ";
	cout << this->get(i) << endl;
}

ostream &operator<<(ostream &os, LinkedList &m)	//输出链表
{
	int i = 0;
	for (i = 0; i < m.getLength() - 1; i++)
		os << m.get(i) << " -> ";
	os << m.get(i);
	return os;
}

void LinkedList::addAtHead(int _cur)	//插入新的头结点
{
	Node *cur;
	cur = new Node;
	cur->val = _cur;
	cur->next = head;
	head = cur;
}

void LinkedList::addAtTail(int _cur)	//插入新的尾节点
{
	if (head)
	{
		Node *cur;
		cur = new Node;
		cur->val = _cur;
		Node *temp;
		temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = cur;
	}
	else
	{
		head = new Node;
		head->val = _cur;
	}
}

void LinkedList::addAtIndex(int _index, int _val)	//在第index处插入新节点
{
	if (_index == 0)
		this->addAtHead(_val);
	else if (_index < this->getLength())
	{
		Node *temp;
		temp = head;
		int i = 1;
		while (i != _index)
		{
			temp = temp->next;
			i++;
		}
		Node *cur;
		cur = new Node;
		cur->val = _val;
		cur->next = temp->next;
		temp->next = cur;
	}
	else if (_index == this->getLength())
		this->addAtTail(_val);
}

void LinkedList::deleteAtIndex(int _index)	//删除第index处的节点
{
	if (_index == 0)
		head = head->next;
	else if (_index < this->getLength())
	{
		Node *temp;
		temp = head;
		int i = 1;
		while (i != _index)
		{
			temp = temp->next;
			i++;
		}
		temp->next = temp->next->next;
	}
}

void LinkedList::reverseList()	//反转链表
{
	Node *pReversedHead = NULL;
	Node *pNode = head;
	Node *pPrev = NULL;
	while (pNode)
	{
		Node *pNext = pNode->next;

		if (!pNext)
			pReversedHead = pNode;

		pNode->next = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}
	head = pReversedHead;
}

int LinkedList::getLength()	//返回链表的长度
{
	Node *temp;
	temp = head;
	int i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int LinkedList::getHead()	//返回头节点
{
	if (head)
		return head->val;
	else
		return -1;
}

int LinkedList::getTail()	//返回尾节点
{
	if (head)
	{
		Node *temp;
		temp = head;
		while (temp->next)
			temp = temp->next;
		return temp->val;
	}
	else
		return -1;
}

int LinkedList::get(int index)	//返回第index处的节点
{
	Node *temp;
	temp = head;
	int i = 0;
	while (temp&&i < index)
	{
		temp = temp->next;
		i++;
	}
	if (!temp || i > index)
		return -1;
	else
		return temp->val;
}

#endif // !LINKEDLIST_H
