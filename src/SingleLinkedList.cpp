#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;

template <typename T>
struct Node	//节点
{
	T val;	//节点的值
	Node<T> *next;	//下一个节点的指针

	Node()
	{
		val = NULL;
		next = NULL;
	}
};

template <typename T>
class LinkedList	//单链表
{
private:
	Node<T> *head;	//头节点
public:
	LinkedList();	//默认构造函数
	LinkedList(T _val);	//构造函数
	~LinkedList();	//析构函数
	void creatList(int length);	//输入链表
	void show();	//显示链表
	void addAtHead(T _cur);	//插入新的头结点
	void addAtTail(T _cur);	//插入新的尾节点
	void addAtIndex(int _index, T _val);	//在第index处插入新节点
	void deleteAtIndex(int _index);	//删除第index处的节点
	void reverseList();		//反转链表
	int getLength();	//返回链表的长度
	T getHead();	//返回头节点
	T getTail();	//返回尾节点
	T get(int _index);	//返回第index处的节点
};

template <typename T>
LinkedList<T>::LinkedList()	//默认构造函数
{
	head = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(T _val)	//构造函数
{
	head = new Node<T>;
	head->val = _val;
}

template <typename T>
LinkedList<T>::~LinkedList()	//析构函数
{
	Node<T> *p;
	p = head;
	while (p)
	{
		p = p->next;
		delete head;
		head = p;
	}
	p = NULL;
}

template <typename T>
void LinkedList<T>::creatList(int length)	//输入链表
{
	head = new Node<T>;
	T *n;
	n = new T[length];
	for (int i = 0; i < length; i++)
		cin >> n[i];
	int j = 0;
	head->val = n[j];
	for (int j = 1; j < length; j++)
		this->addAtTail(n[j]);
}

template <typename T>
void LinkedList<T>::show()	//显示链表
{
	int i = 0;
	for (i = 0; i < this->getLength() - 1; i++)
		cout << this->get(i) << " -> ";
	cout << this->get(i) << endl;
}

template <typename T>
ostream &operator<<(ostream &os, LinkedList<T> &m)	//输出链表
{
	int i = 0;
	for (i = 0; i < m.getLength() - 1; i++)
		os << m.get(i) << " -> ";
	os << m.get(i);
	return os;
}

template <typename T>
void LinkedList<T>::addAtHead(T _cur)	//插入新的头结点
{
	Node<T> *cur;
	cur = new Node<T>;
	cur->val = _cur;
	cur->next = head;
	head = cur;
}

template <typename T>
void LinkedList<T>::addAtTail(T _cur)	//插入新的尾节点
{
	if (head)
	{
		Node<T> *cur;
		cur = new Node<T>;
		cur->val = _cur;
		Node<T> *temp;
		temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = cur;
	}
	else
	{
		head = new Node<T>;
		head->val = _cur;
	}
}

template <typename T>
void LinkedList<T>::addAtIndex(int _index, T _val)	//在第index处插入新节点
{
	if (_index == 0)
		this->addAtHead(_val);
	else if (_index < this->getLength())
	{
		Node<T> *temp;
		temp = head;
		int i = 1;
		while (i != _index)
		{
			temp = temp->next;
			i++;
		}
		Node<T> *cur;
		cur = new Node<T>;
		cur->val = _val;
		cur->next = temp->next;
		temp->next = cur;
	}
	else if (_index == this->getLength())
		this->addAtTail(_val);
}

template <typename T>
void LinkedList<T>::deleteAtIndex(int _index)	//删除第index处的节点
{
	if (_index == 0)
		head = head->next;
	else if (_index < this->getLength())
	{
		Node<T> *temp;
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

template <typename T>
void LinkedList<T>::reverseList()	//反转链表
{
	Node<T> *pReversedHead = NULL;
	Node<T> *pNode = head;
	Node<T> *pPrev = NULL;
	while (pNode)
	{
		Node<T> *pNext = pNode->next;

		if (!pNext)
			pReversedHead = pNode;

		pNode->next = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}
	head = pReversedHead;
}

template <typename T>
int LinkedList<T>::getLength()	//返回链表的长度
{
	Node<T> *temp;
	temp = head;
	int i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

template <typename T>
T LinkedList<T>::getHead()	//返回头节点
{
	if (head)
		return head->val;
	else
		return -1;
}

template <typename T>
T LinkedList<T>::getTail()	//返回尾节点
{
	if (head)
	{
		Node<T> *temp;
		temp = head;
		while (temp->next)
			temp = temp->next;
		return temp->val;
	}
	else
		return -1;
}

template <typename T>
T LinkedList<T>::get(int index)	//返回第index处的节点
{
	Node<T> *temp;
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
