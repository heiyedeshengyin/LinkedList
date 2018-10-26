# LinkedList
基本的数据结构，用面向对象的方式实现单链表，双链表和循环链表  
链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。  
链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。  
每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。  
链表有很多种不同的类型：单向链表，双向链表以及循环链表。  
目前只实现了单向链表。  
    
链表实现需要两个对象，一个是节点对象，另一个是属性为节点的链表对象。  
    
节点对象和链表对象(单链表)  
```cpp
struct Node //节点
{
  int val;  //节点中储存的数据
  Node *next; //下一个节点的指针
}

class LinkedList  //链表
{
  Node *head; //头结点
}

```
头结点代表一个链表，所以头结点的指定非常重要。  
    
测试代码(单链表)  
```cpp
#include"SingleLinkedList.cpp"

int main()
{
	LinkedList s1;
	s1.creatList(5);
	cout << s1 << endl;
	cout << s1.getLength() << endl;

	s1.addAtIndex(4, 6);
	cout << s1 << endl;
	cout << s1.getLength() << endl;

	s1.deleteAtIndex(3);
	cout << s1 << endl;
	cout << s1.getLength() << endl;

	return 0;
}

```

输入：5 8 7 3 1  
运行结果为  
```
5 -> 8 -> 7 -> 3 -> 1
5
5 -> 8 -> 7 -> 3 -> 6 -> 1
6
5 -> 8 -> 7 -> 6 -> 1
5

```
