#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;//链表中元素的数据类型

// Node结构体 ，表示链表中的一个结点
typedef struct node{
	ElemType data; //数据域：存放链表中的元素值；
	struct node *next; //指针域：存放指向下一个节点的地址（指针）。
}Node;
